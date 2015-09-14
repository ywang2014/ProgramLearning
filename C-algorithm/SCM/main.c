/**
 * @Introduction: 单片机程序开发
 * @date: 2015-9-9
 * @rights: all rights reserved!
 *
 */

#include "main.h"


int main(void)
{
  /* Configure the System clock to have a frequency of 168 MHz */
 HAL_Init();
 SystemClock_Config();

  /* STM32F4xx HAL library initialization:
  - Configure the Flash prefetch, instruction and Data caches
  - Configure the Systick to generate an interrupt each 1 msec
  - Set NVIC Group Priority to 4
  - Low Level Initialization
  */
  /*1、优先级配置为 抢占优先级：响应优先级=2bit：2bit
    2、systick配置为1ms*/

  SystemClock=HAL_RCC_GetHCLKFreq();//读取当前系统时钟；
  //SystemCoreClockUpdate();用于更新系统时间；

  //Timer6Init(&Tim6Handle);

  /* Enable Power Clock */
  __PWR_CLK_ENABLE();//冗余

  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();

  StandBy_Init();//配置PA0管脚中断

   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);//打开LCD电源；
   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET);//打开VDD电源；

  //NVIC_SystemReset();
  /* 各模块初始化；*/
  //  ADG715_Init(&I2c3Handle);
  //  HAL_I2C_Master_Transmit(&I2c3Handle,(uint16_t)ADG715_ADDRESS,(uint8_t*)ADG715_Comd_START,1,10);
  //PWR_Init();
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET); //打开LCD BT Zigbee电源；

  SPI_LCD_Init();

ST7789VCPT24panelinitialcode();

LCD_Clear(0XFFFF);

//DispSmallPic(0,0,240,211, gImage_C);



  BTrans_Init(&Usart2Handle);
  ADS1292_Init(&Spi1Handle);
  AFE4490_Init(&Spi2Handle);
 Send2BT(&PPG[0],26);   //调串口用的数组发送

  AFE4490_RegConfig(&Spi2Handle);

  //PPG_State_Change(0x01);//0x01为反射式测量模式、0x00为透射式测量模式
  //ECG_State_Change(0x01);//0x01为干电极测量模式、0x00为湿电极测量模式

  PPGHead_Packet();
  ECGHead_Packet();
  ResultHead_Packet();
  Time_BKPHead_Packet();

  InitMPU9150();
 //displayMPU9150();
  /*******************************************************************************
  各个模块的复位操作；
  *******************************************************************************/
  //ADS1292_DeInit(&Spi1Handle);

  /*******************************************************************************
  通过I2C3向ADG715发送指令实现对各个模块的电源管理；
  *******************************************************************************/
  //HAL_I2C_Master_Transmit_DMA(&I2c3Handle, (uint16_t)ADG715_ADDRESS, (uint8_t*)ADG715_Comd_STOP, 1);
  //HAL_I2C_Master_Transmit(&I2c3Handle,(uint16_t)ADG715_ADDRESS,(uint8_t*)ADG715_Comd_Mea,1,10);
  //ADG715_DeInit(&I2c3Handle);

  I2C_BME280_Init();


  /***********************************
  徐志红SB
  ***********************************/

  ECGData_Packet_BT();
  PPGHead_Packet_float();


  /* Infinite loop */
  while (1)
  {



   /*************************************************心电ADS1292程序     START   *************************************************************/

      if(ECG_flag1==1)
      {
      ECG_flag1=0;
      for(uint8_t n=0;n<10;n++)
      {

      ECG[0][3*n+0]=ECG_buffer1[9*n+3];
      ECG[0][3*n+1]=ECG_buffer1[9*n+4];
      ECG[0][3*n+2]=ECG_buffer1[9*n+5];
      ECG[1][3*n+0]=ECG_buffer1[9*n+6];
      ECG[1][3*n+1]=ECG_buffer1[9*n+7];
      ECG[1][3*n+2]=ECG_buffer1[9*n+8];

      }
      ECGData2Float_All();
      ECG_Process_flag=1;
    }

    if(ECG_flag2==1)
    {
      ECG_flag2=0;
      for(uint8_t n=0;n<10;n++)
      {
      ECG[0][3*n+0]=ECG_buffer2[9*n+3];
      ECG[0][3*n+1]=ECG_buffer2[9*n+4];
      ECG[0][3*n+2]=ECG_buffer2[9*n+5];
      ECG[1][3*n+0]=ECG_buffer2[9*n+6];
      ECG[1][3*n+1]=ECG_buffer2[9*n+7];
      ECG[1][3*n+2]=ECG_buffer2[9*n+8];
      }

      ECGData2Float_All();
      ECG_Process_flag=1;

    }
    if(ECG_Process_flag==1)
    {
      ECG_Process_flag=0;


      for(uint8_t i=0;i<10;i++)
      {
        ECG_Signal[0][Dry_delay+i]=Comb_Filter(ECG_Comb[0],Mean_n_Filter (150,Breath_Aver,ECG_f[0][i]))+3;//ECG_Signal[]是信号的
        ECG_Signal[1][Dry_delay+i]=Comb_Filter(ECG_Comb[1],Mean_n_Filter (10,ECG_Aver[1],ECG_f[1][i]))+3;
    //   ECG_Signal[3][Dry_delay+i]=Comb_Filter(ECG_Comb[3],Mean_n_Filter (10,ECG_Aver[3],ECG_f[3][i]))+3;
    //   ECG_Signal[4][Dry_delay+i]=Comb_Filter(ECG_Comb[4],Mean_n_Filter (10,ECG_Aver[4],ECG_f[4][i]))+3;
      }
      datacopy_float(ECG_Signal[1]+Dry_delay,ECG_Dry+70,0,10);
      for(uint8_t i=0;i<10;i++)
      {
        copyArray(ECG_Dry,tempArray,50+i);
        sort(tempArray);
        BL[i]=tempArray[10];
        BL_end[2][i]=Mean_n_Filter(160,BL_average[2],BL[i]);
      }
      minus(ECG_Signal[1],BL_end[2],ECG_Signal_process[2]);
      ECGData_Packet();
      //Send2LCD(ECG_int[2],78);
      datacopy_float(ECG_Channel_float,ECG_Channel_float,numtoprocess,1000-numtoprocess);
      datacopy_float(ECG_Signal[1]+Dry_delay,ECG_Channel_float+990,0,10);
      //Send2BT_float(ECG_Signal[2]+Dry_delay,ECG_Send,1);//屏蔽 发送原始一通道数据；
      //Send2BT_float(BL_end[2],ECG_Send,2);
      //Send2BT_float(ECG_Signal_process[2],ECG_Send,3);//屏蔽 发送中值滤波后一通道数据；
      //Send2BT_float(ECG_Signal[1],ECG_Send,4);//屏蔽 发送原始呼吸数据；
      datacopy_float(ECG_Dry,ECG_Dry,10,70);
      datacopy_float(ECG_Signal[2],ECG_Signal[1],10,80);
      datacopy_float(ECG_lowpass_signal,ECG_lowpass_signal,numtoprocess,1000-numtoprocess);
      datacopy_float(ECG_Channel_lowpass_float,ECG_Channel_lowpass_float,numtoprocess,1000-numtoprocess);
      datacopy_float(ECG_Channel_highpass_float,ECG_Channel_highpass_float,numtoprocess,1000-numtoprocess);
      datacopy_float(ECG_Channel_derivation_float,ECG_Channel_derivation_float,numtoprocess,1000-numtoprocess);
      datacopy_float(ECG_Channel_square_float,ECG_Channel_square_float,numtoprocess,1000-numtoprocess);
      datacopy_float(move_average,move_average,numtoprocess,1000-numtoprocess);
      datacopy_uint(peak_flag,peak_flag,numtoprocess,0,1000-numtoprocess);

      QRS_lowpass_singal(ECG_Channel_float,ECG_lowpass_signal,990,1000);
      QRS_lowpass_singal(ECG_lowpass_signal,ECG_Channel_lowpass_float,990,1000);
      QRS_highpass_S(ECG_Channel_lowpass_float,990,1000);
      QRS_derivation_S(ECG_Channel_highpass_float,990,1000);
      QRS_square_S(ECG_Channel_derivation_float,990,1000);
      mov_average_S(ECG_Channel_square_float,990,1000,MovingAverageNumber);
      if(d%50==0)
      {
        max_5=find_max(550,1000,move_average,-300,max_5);
        ECG_max=find_max(550,1000,ECG_Channel_float,-300,ECG_max);
        ECG_start_compute=1;
      }
      if(ECG_start_compute==1)
      {
        //find_peak(move_average,ECG_Channel_float,1990,2000,max_5,ECG_max,flag_xx);
        flag_test=test_signal(ECG_Channel_float,ECG_max,0.0001,250,1000);
 //      if(flag_test==0)
 //       { find_peak(move_average,ECG_Channel_float,990,1000,max_5,ECG_max,flag_xx);}
 //     else
 //     { Result_int[22]=1;}
      }
      /****************************呼吸率处理程序************************************/
      datacopy_float(Breath_float,Breath_float,numtoprocess,1000-numtoprocess);
      datacopy_float(ECG_Signal[0],Breath_float+990,0,10);
      k_breath++;
      //      static float breath_max;
      //      static uint16_t counter=0;
      //      static uint16_t pulseperiod=0;
      //      static uint8_t beats=0;
      //      static uint8_t breath_heartrate=0;
      if(k_breath==125)
      {
        k_breath=0;
        breath_max=max_find_float(Breath_float+1000,1000);
        start_compute_breath=1;
      }
      if(start_compute_breath==1)
      {
        for(uint8_t i_breath=0;i_breath<numtoprocess;i_breath++)
        {
          counter++;
          pulseperiod++;
          if (Breath_float[i_breath+2000-numtoprocess]> breath_max*0.7)
          {
            counter=0;
          }
          if(counter==300)
          {
            beats++;
            if (beats==3)
            {
              beats=0;
              breath_heartrate=(uint8_t)(60*3*250/pulseperiod);
              pulseperiod=0;
              Result_int[9]=breath_heartrate;
            }
          }
        }
      uint16_t x4 = breath_heartrate/100;
      uint16_t x5 = breath_heartrate%100/10;
      uint16_t x6 = breath_heartrate%10;
       LCD_ShowNum(100,90,x4,1,16);
       LCD_ShowNum(104,90,x5,1,16);
       LCD_ShowNum(108,90,x6,1,16);
      }

      //**********************************************/
      //*********************************************/

      //      ADS1294_DRY_BT=1;
      //      ADS1294_DRY_LCD=1;
    }

 /*   if(ADS1294_DRY_BT==1)
    {
      //d++;
    //  BT_Complete=0;
      ADS1294_DRY_BT=0;
      Send2BT(ECG_int[2],78);//2\3\4 3路心电数据
    }
*/

    if(AFE4490_DRY_Flag!=0)
    {
      AFE4490_DRY_Flag=0;
      /* 寄存器读数->转换为Float型->十步滑动平均 ->梳状滤波器->带通滤波器*/
 //     LED2_ALED2=BandPass_Filter(10,Coeffs,PPG_BP[1],Comb_Filter(PPG_Comb[1],Mean_n_Filter (10,PPG_Aver[1],PPGData2Float(LED2_ALED2VAL))));
      LED1_ALED1=BandPass_Filter(10,Coeffs,PPG_BP[0],Comb_Filter(PPG_Comb[0],Mean_n_Filter (10,PPG_Aver[0],PPGData2Float(LED1_ALED1VAL))));
      PPGData_Packet();//PPG数据打包；
    }

    if(PPGData_num_10==1)
    {
      PPGData_num_10=0;
      /*********************************
      徐志红
      *************************************/
      datacopy_float(PPG_data_IR,PPG_data_IR,10,990);
      datacopy_float(PPG_data_RED,PPG_data_RED,10,990);

      //*************************************
      //**************************************
      if(PPG_flag==1)
      {
        //Send2BT(PPG_int0[0],52);//两路血氧数据；

        /*********************************
        徐志红
        *************************************/
        //Send2BT_float(PPG_Signal1[1],PPG_Send,2);
        datacopy_float(PPG_Signal1[0],PPG_data_RED+990,0,10);
        datacopy_float(PPG_Signal1[1],PPG_data_IR+990,0,10);
        //*************************************
        //**************************************

      }
      else
      {
        //Send2BT(PPG_int1[0],52);
        /*********************************
        徐志红
        *************************************/
        //Send2BT_float(PPG_Signal2[1],PPG_Send,2);
        datacopy_float(PPG_Signal2[0],PPG_data_RED+990,0,10);
        datacopy_float(PPG_Signal2[1],PPG_data_IR+990,0,10);
        //*************************************
        //*************************************
      }

      /*********************************
      徐志红
      *************************************/
      //////////////////////////////////////////////////////////
      for(uint8_t i=0;i<10;i++)
      {
        PPG_Signal[0][Dry_delay+i]=Comb_Filter(PPG_Comb[2],Mean_n_Filter (10,PPG_Aver[2],PPG_data_IR[i+990]));//ECG_Signal[]是信号的
        //PPG_Signal[1][Dry_delay+i]=Comb_Filter(PPG_Comb[5],Mean_n_Filter (10,PPG_Aver[5],PPG_data_RED[i+990]));
      }
      /////////////////////////////////////////////////////////
      datacopy_float(PPG_Signal[0]+Dry_delay,PPG_Dry[1]+40,0,10);
      for(uint8_t i=0;i<10;i++)
      {
        copyArray(PPG_Dry[1],PPG_tempArray[1],i+20);
        sort(PPG_tempArray[1]);
        PPG_BL[1][i]= PPG_tempArray[1][10];
        PPG_BL_end[1][i]=Mean_n_Filter(160,PPG_BL_average[1],PPG_BL[1][i]);
      }
      minus(PPG_Signal[0],PPG_BL_end[1],PPG_Signal_process[1]);
      //Send2BT_float(PPG_data_IR+990,ECG_Send,1);
      //Send2BT_float(PPG_BL_end[1],ECG_Send,2);
      //Send2BT_float(PPG_Signal_process[1],ECG_Send,3);
      datacopy_float(PPG_Dry[1],PPG_Dry[1],10,40);

      datacopy_float(PPG_derivation,PPG_derivation,10,990);
      datacopy_float(PPG_Signal[0],PPG_Signal[0],10,Dry_delay);
      datacopy_uint(PPG_peak_flag,PPG_peak_flag,10,0,1000-NumofPPG);
      PPG_deri(PPG_data_IR,1000-NumofPPG,1000);
      uint16_t num=1000-NumofPPG-5;

      if(c>50&&pulse_start_compute==0)
        pulse_start_compute=1;
      if(pulse_start_compute==1&&c%50==0)
      {
        PPG_derivation_max=max_find_float(PPG_derivation,1000);
        PPG_derivation_threshold=PPG_derivation_max*0.8;
        PPG_amplitude_max=max_find_float(PPG_data_IR,500);


        Result_Send_LCD=1;//
        Result_Send_BT=1;//
      }
      /*****************************************/
      PPG_test_max=max_find_float(PPG_data_IR,1000-num);
      PPG_test[3]=PPG_test[2];
      PPG_test[2]=PPG_test[1];
      PPG_test[1]=PPG_test[0];
      if(abs_process(PPG_amplitude_max,PPG_test_max)<0.1&&(PPG_test_max>0)&&(PPG_test_max!=PPG_amplitude_max))
        PPG_test[0]=0;
      if(PPG_test_max==PPG_amplitude_max)
        PPG_test[0]=1;
      /* delete
      if(abs_process(PPG_amplitude_max,PPG_test_max)>0.099||(PPG_test_max<0))//未完整测量语句
      {
      PPG_test[3]=PPG_test[2];
      PPG_test[2]=PPG_test[1];
      PPG_test[1]=PPG_test[0];
      PPG_test[0]=1;
    }*/
      if((PPG_test[3]==1)&&(PPG_test[2]==1)&&(PPG_test[1]==1)&&(PPG_test[0]==1))
        Result_int[23]=1;
      else
        Result_int[23]=0;
      /*****************************************/
      if(Result_int[23]==0)
      {
        for(;num<1000-5;num++)
        {
          if(((PPG_derivation[num]>PPG_derivation[num-1])||(PPG_derivation[num]==PPG_derivation[num-1]))&&(PPG_derivation[num-1]>0))
          {
            if(((PPG_derivation[num]>PPG_derivation[num+1])||(PPG_derivation[num]==PPG_derivation[num+1]))&&(PPG_derivation[num+1]>0))
            {
              if((PPG_derivation[num-5]>0)||(PPG_derivation[num-5]==0))
              {
                if((PPG_derivation[num+5]>0)||(PPG_derivation[num+5]==0))
                  break;
              }
            }
          }
        }
        if(num!=1000-5&&PPG_derivation[num]!=0.5&&PPG_derivation[num]>PPG_derivation_threshold&&pulse_start_compute==1)
        {
          PPG_peak_flag[num]=1;
          distance_spo2=num-RR_time(num,600,PPG_peak_flag,1); //检查查找到的

          //distance_high_level=
          //distance_low_level=
          //if(Result_int[23]==0)
          i_start=1000+num;//加上1000的原因是心电与血氧数组的差值是1000
          end_spo2=i_start-200;
          for(;i_start>end_spo2;i_start--)
          {
            if(peak_flag[i_start]==1)
              break;
          }
          if((i_start!=end_spo2)||((i_start==end_spo2)&&(peak_flag[i_start]==1)))
          {
            time_spo2++;
            if(time_spo2>7)
            {
              time_spo2=8;
            }/**/
            //if(time_spo2==8)
            //time_spo2=0;
          }
          PTT[7]=PTT[6];PTT[6]=PTT[5];PTT[5]=PTT[4];
          PTT[4]=PTT[3];PTT[3]=PTT[2];PTT[2]=PTT[1];
          PTT[1]=PTT[0];
          PTT[0]=1000+num-i_start;
          uint16_t sum=0;
          if(time_spo2>2)
            //if(time_spo2==8)
          {
            PTT_max=find_max_uint8(PTT,time_spo2);
            PTT_min=find_min(PTT,time_spo2);
            for(uint8_t j=0;j<time_spo2;j++)
              sum+=PTT[j];
            PTT_average=(uint8_t)((sum-PTT_max-PTT_min)/(time_spo2-2));
            Result_int[16]=PTT_average;
          }
          PPG_max_position=max_find_position(PPG_derivation,num-distance_spo2,100);//显示波形中的最大值，原始波形中的最小值
          //PPG_peak_flag[PPG_max_position]=2;
          //distance_spo2_peak=num-RR_time(num,600,PPG_peak_flag,2);
          if(distance_spo2>10)
          {
            pulse_rate[7]=pulse_rate[6];pulse_rate[6]=pulse_rate[5];pulse_rate[5]=pulse_rate[4];
            pulse_rate[4]=pulse_rate[3];pulse_rate[3]=pulse_rate[2];pulse_rate[2]=pulse_rate[1];
            pulse_rate[1]=pulse_rate[0];
            pulse_rate[0]=(uint16_t)(15000/distance_spo2);
            pulse_rate_max=find_max_uint16(pulse_rate,time_spo2);
            pulse_rate_min=find_min_uint16(pulse_rate,time_spo2);
            sum=0;
            if(time_spo2>2)
              //if(time_spo2==8)
            {
              for(uint8_t j=0;j<time_spo2;j++)
                sum+=pulse_rate[j];
              pulse_rate_average=(uint8_t)((sum-pulse_rate_max-pulse_rate_min)/(time_spo2-2));
              //while(pulse_rate_average<220);
              Result_int[8]=pulse_rate_average;

            }
            PPG_min_position=min_find_position(PPG_derivation,num-distance_spo2,100); //显示波形中的最小值，原始波形中的最大值
            PPG_peak_flag[PPG_min_position]=3;
            Q_RED=(PPG_data_RED[PPG_max_position]-PPG_data_RED[PPG_min_position])/(0.5-PPG_data_RED[PPG_min_position]);
            Q_IR=(PPG_data_IR[PPG_max_position]-PPG_data_IR[PPG_min_position])/(0.5-PPG_data_IR[PPG_min_position]);
            R=(float)Q_RED/Q_IR;
            SPO2_f=109.007-10.2132*R-16.5999*R*R;
            SPO2=(uint8_t)SPO2_f;
            if(SPO2>100)
              SPO2=100;
            if(SPO2>60)
              Result_int[7]=SPO2;
            //            sum_blood=0;
            //            uint16_t j=num-distance_spo2;
            //            for(;j<num;j++)
            //            {
            //              sum_blood+=PPG_data_IR[j];
            //            }
            //            sum_blood=0.5*distance_spo2-sum_blood;
            //            k_blood=(float)((float)(sum_blood-(0.5-PPG_data_IR[PPG_max_position])*distance_spo2)/((float)(PPG_data_IR[PPG_max_position]-PPG_data_IR[PPG_min_position])*distance_spo2));
            //            //Send2BT(Result_int,26);
            //            Result_Send_LCD=1;
            //            Result_Send_BT=1;
            //            f++;
            sum_blood=0;
            for(uint16_t j=num-distance_spo2;j<num;j++)
            {
              sum_blood=sum_blood+PPG_data_IR[j];
            }
            sum_blood=0.5*distance_spo2-sum_blood;
            k_blood=(float)((float)(sum_blood-(0.5-PPG_data_IR[PPG_max_position])*distance_spo2)/((float)(PPG_data_IR[PPG_max_position]-PPG_data_IR[PPG_min_position])*distance_spo2));
            //k_blood=(float)(sum_blood/((float)(PPG_data_IR[PPG_max_position]-PPG_data_IR[PPG_min_position])*distance_spo2));
            P_mean=(uint8_t)(k_blood*30.5);
            //Send2BT(spo2_channel);
          }
          else if(distance_spo2!=0)
          {
            PPG_peak_flag[num]=0;
          }

          if((PTT_average<139)&&(Result_int[22]==0)&&(Result_int[23]==0)&&(PTT_average>17))
          {
            Highblood_ever=Highblood;
            Highblood=(uint8_t)(216-1.549*PTT_average);
            median_value=(uint8_t)(P_mean/k_blood);
            if(P_mean!=0&&k_blood!=0)
            {
              if(abs_process(Highblood_ever,Highblood)>15&&(Highblood_ever!=0)&&Highblood_ever>99)
              {
                Highblood=Highblood_ever;
              }
                Result_int[10]=Highblood;
              if(median_value>25&&median_value<35)
              {
                Result_int[11]=Highblood-median_value;
              }
              else
              {
                Result_int[11]=Highblood-30;//问题；
              }
            }
          }

        }
      }

      //*************************************
      //*************************************
      if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8))//反射式测量模式，；
      {
        for(uint8_t i=0;i<10;i++)
        {
          PPG_int0[0][num1]=((int32_t)(PPG_Signal_process[1][i]*360000)&0x0000FF00)>>8;
          num1++;
          PPG_int0[0][num1]=(int32_t)(PPG_Signal_process[1][i]*360000)&0x000000FF;
          num1++;
        }
        num1=6;
        PPGData_Send_BT=1;
        PPGData_Send_LCD=1;
      }

    }

    if(PPGData_Send_BT==1&&BT_Complete==1)   //发给BT
    {
      BT_Complete=0;
      PPGData_Send_BT=0;
      Send2BT(PPG_int0[0],26);//单路血氧数据；
      //c++;
    }


    if(Result_int[23]==1)
    {
      Result_int[7]=0;
      Result_int[8]=0;
      Result_int[10]=0;
      Result_int[11]=0;
    }
    if(Result_int[22]==1)
    {
      Result_int[6]=0;
      Result_int[17]=0;
    }
    if(Result_int[6]==220)
      Result_int[6]=0;
    if(Result_int[6]>Result_int[8]&&Result_int[8]!=0)
      Result_int[6]=Result_int[8];


  }
}
/**
* @brief  Configures Button PA0 and EXTI Line.
*/
void StandBy_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable the GPIOA Clock */
  __GPIOA_CLK_ENABLE();
  //__SYSCFG_CLK_ENABLE();

  /* Configure Button pin as input with External interrupt */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* Enable and set Button EXTI Interrupt to the lowest priority */
  HAL_NVIC_SetPriority(EXTI0_IRQn, 3, 3);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

/**
* @brief  This function configures the system to enter Standby mode with RTC
*         clocked by LSE or LSI and with Backup SRAM ON for current consumption
*         measurement purpose.
*         STANDBY Mode with RTC clocked by LSE/LSI and BKPSRAM
*         ====================================================
*           - RTC Clocked by LSE or LSI
*           - Backup SRAM ON
*           - IWDG OFF
*           - Automatic Wakeup using RTC clocked by LSE/LSI (after ~20s)
* @param  None
* @retval None
*/
void StandbyRTCBKPSRAMMode_Measure(void)
{
  /* Configure RTC prescaler and RTC data registers as follow:
  - Hour Format = Format 24
  - Asynch Prediv = Value according to source clock
  - Synch Prediv = Value according to source clock
  - OutPut = Output Disable
  - OutPutPolarity = High Polarity
  - OutPutType = Open Drain */
  //  RTCHandle.Instance = RTC;
  //  RTCHandle.Init.HourFormat = RTC_HOURFORMAT_24;
  //  RTCHandle.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
  //  RTCHandle.Init.SynchPrediv = RTC_SYNCH_PREDIV;
  //  RTCHandle.Init.OutPut = RTC_OUTPUT_DISABLE;
  //  RTCHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  //  RTCHandle.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

  //  if(HAL_RTC_Init(&RTCHandle) != HAL_OK)
  //  {
  //    /* Initialization Error */
  //    Error_Handler();
  //  }

  /*## Configure the Wake up timer ###########################################*/
  /*  RTC Wakeup Interrupt Generation:
  Wakeup Time Base = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSI))
  Wakeup Time = Wakeup Time Base * WakeUpCounter
  = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSI)) * WakeUpCounter
  ==> WakeUpCounter = Wakeup Time / Wakeup Time Base

  To configure the wake up timer to 20s the WakeUpCounter is set to 0xA017:
  RTC_WAKEUPCLOCK_RTCCLK_DIV = RTCCLK_Div16 = 16
  Wakeup Time Base = 16 /(~32.768KHz) = ~0,488 ms
  Wakeup Time = ~20s = 0,488ms  * WakeUpCounter
  ==> WakeUpCounter = ~20s/0,488ms = 40983 = 0xA017 */
  /* Disable Wake-up timer */
  //  if(HAL_RTCEx_DeactivateWakeUpTimer(&RTCHandle) != HAL_OK)
  //  {
  //    /* Initialization Error */
  //    Error_Handler();
  //  }

  //HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, 0xA017, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

  /* Enable WKUP pin 1 */
  HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);

  /* Enable BKPRAM Clock */
  //__BKPSRAM_CLK_ENABLE();

  //  /* Enable the Backup SRAM low power Regulator */
  //  HAL_PWREx_EnableBkUpReg();

  /* Request to enter STANDBY mode (Wake Up flag is cleared in HAL_PWR_EnterSTANDBYMode() function) */
  HAL_PWR_EnterSTANDBYMode();

}






/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSI)
  *            SYSCLK(Hz)                     = 84000000
  *            HCLK(Hz)                       = 84000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSI Frequency(Hz)              = 16000000
  *            PLL_M                          = 16
  *            PLL_N                          = 336
  *            PLL_P                          = 4
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale2 mode
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */

static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /* Enable HSI Oscillator and activate PLL with HSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 0x10;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
