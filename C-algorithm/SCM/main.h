/*
 * main.h
 *
 *  Created on: 2015-9-9
 *      Author: ZKY
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Includes ------------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------
 *
ECG[5][30]中每行存10个数:
	第一行ECG[0]为状态指示数据；
	第二行ECG[1]~第5行ECG[4]分别为为4路心电数据

PPG_int0[6][26]中每行存10个数+6个包头，第一行PPG_int0[0]~第六行PPG_int0[5]分别存储
LED1_ALED1,LED2_ALED2,LED1,LED2,ALED2,ALED1相应数据
note：LED1 = IR and LED2 = RED.
*/

#define Dry_delay 80

uint8_t ADS1292_SendByte();

uint16_t a,b,c,d,e,f,o,u,flag0,BT_Complete=1,LCD_Complete=1;

uint32_t flag1,Temp_BKP,Temp_Date,SystemClock;//ADG715_Comd_START[1]={0x45},ADG715_Comd_Mea[1]={0x5D}

uint8_t ADG715_ADDRESS=0x90,ADG715_Comd_START[1]={0x45},ADG715_Comd_STOP[1]={0x00},
		ADG715_Comd_Mea[1]={0x5D},PPGData_num_10;

uint8_t Time_BKP[26],SendTime_flag,Time_Temp,Measured_flag,StandbyDate_flag,Remind_flag,
		ECG_flag1,ECG_flag2,SendTime_flag0=1,Result_Send_LCD,Result_Send_BT;

uint8_t ADS1292_DRY_BT,ADS1292_DRY_LCD,ECG_buffer1[150],ECG_buffer2[150],ECG[5][30],
		ECG_int[5][26],StandBy_flag,Result_int[26];

float ECG_f[5][10],ECG_Signal[5][10+Dry_delay];//deleteECG_Signal[5][10]

float ECG_Aver[5][10],ECG_Comb[5][10];

uint8_t NumofPackage_PPG,NumofPackage_ECG,Picaso_Buffer1[26],Picaso_Buffer2[26],Picaso_flag1,
		Upload_flag1,Picaso_flag2,Upload_flag2;

uint8_t PPG_int0[6][26],PPG_int1[6][26],PPG_temp[3]={0},AFE4490_DRY_Flag=0,PPGData_Send_BT,
		PPGData_Send_LCD,num,num1=6,PPG_flag,num_float;

float PPG_Aver[6][10],PPG_Comb[6][10],PPG_BP[6][10];

float LED2,ALED2,LED2_ALED2,LED1,ALED1,LED1_ALED1,PPG_float0[6][10],PPG_float1[6][10];

uint8_t ECG_Process_flag;

extern float abs_process(float A,float threshold);


static  float Coeffs[10] =
{
  0.0948,
  0.0993,
  0.1027,
  0.1051,
  0.1063,
  0.1063,
  0.1051,
  0.1027,
  0.0993,
  0.0948
};


/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
void DMA2_Stream0_IRQHandler(void);
void Picaso_Comd_Process(uint8_t* Picaso_Comd);
void StandbyRTCBKPSRAMMode_Measure(void);
void StandBy_Init(void);
void ADS1292_Init();
void BTrans_Init();

void SPI_LCD_Init();
void write_command();
void write_data();
void LCD_Clear();
void LCD_ShowChar();
void LCD_ShowString();
void ST7789VCPT24panelinitialcode();
void DispSmallPic();
void RTC_Config();
void RTC_TimeRegulate();
void RTC_TimeShow();
void showtime();
void LCD_ShowNum();
void Delayms();
void LCD_DrawLine();
void showboxing();
void LcdDrawCurve();
void LcdContinLine();
void LCD_Fill();
void AFE4490_SPI2_Config();
void AFE4490_State_Init();
void ADC_RDY_Config();
void PPGHead_Packet();
void Send2BT(uint8_t* Buffer,uint16_t n);
void ADS1292_SPI1_Config();
void ADS1292_Init();
void ECGHead_Packet();
void ECGData_Packet_BT();
void ECGData2Float_All();
void I2C_MPU9150_Init();
void InitMPU9150();
void NVIC_Config();
void displayMPU9150();


/* handler declaration */
// I2C_HandleTypeDef I2c3Handle;//ADG715
SPI_HandleTypeDef Spi1Handle;//ADS1292
SPI_HandleTypeDef Spi2Handle;//AFE4490
UART_HandleTypeDef Uart4Handle;//PICASO
UART_HandleTypeDef Usart2Handle;//BT
RTC_HandleTypeDef RTCHandle;
RTC_TimeTypeDef  sTime;
RTC_DateTypeDef sDate;
RTC_AlarmTypeDef  sAlarm;
TIM_HandleTypeDef Tim6Handle;
ADC_HandleTypeDef    Adc1Handle;
ADC_ChannelConfTypeDef sConfig;



/************************************** 徐志红sb ***************************************/
#define Dry_delay 80
extern float PPG_Signal1[2][10]={0},PPG_Signal2[2][10]={0};
float Breath_Aver[150];
uint8_t PPG_Send[46*2];
static float breath_max;
static uint16_t counter=0;
static uint16_t pulseperiod=0;
static uint8_t beats=0;
static uint8_t breath_heartrate=0;
uint8_t flag_xx=1;



/**********************心电数据处理程序***************************/
extern float ECG_lowpass_signal[2000]={0},ECG_Channel_lowpass_float[2000]={0},
			 ECG_Channel_derivation_float[2000],ECG_Channel_square_float[2000],move_average[2000],
			 ECG_Channel_highpass_float[2000],ECG_Channel_float[2000],ECG_derivation_float2[2000],
			 ECG_divided12[2000];

extern uint8_t peak_flag[2000];
extern float send_float[10]; //调试用的数组
extern void QRS_lowpass_singal(float *ECG_source,float *ECG_destination,uint16_t position_start,
								uint16_t len);

extern void QRS_highpass_S(float *ECG,uint16_t position,uint16_t len);
extern void QRS_derivation_S(float *ECG,uint16_t position,uint16_t len);
extern void QRS_square_S(float *ECG,uint16_t position,uint16_t len);
extern void mov_average_S(float *ECG,uint16_t position,uint16_t len,uint8_t N);
extern float find_max(uint16_t position_start,uint16_t position_end,float *ECG,float max_threshold,
						float max_ever);

extern void datacopy_uint(uint8_t *source,uint8_t *destination,uint8_t position_source,
							uint16_t destination_position,uint16_t len);

extern void find_peak(float *ECG,float *ECG_source,uint16_t position,uint16_t len,float threshold,
						float ECG_float,uint8_t flag_xx);

extern float max_find_float(float *source,uint16_t len);
extern uint16_t max_find_position(float *source,uint16_t position,uint16_t len);
extern uint16_t  RR_time(uint16_t position_start,uint16_t distance,uint8_t *source,uint8_t flag);
extern float min_find_float(float *source,uint16_t len);
extern uint16_t min_find_position(float *source,uint16_t position_max,uint16_t len);
extern void datacopy_float(float *source,float *destination,uint16_t position,uint16_t N);
extern void Send2BT_float(float *Buffer,uint8_t* destination,uint8_t num);
extern void ECGData_Packet_BT(void);
extern void PPGHead_Packet_float(void);
extern void ResultHead_Packet(void);
extern uint8_t ECG_Send[46*4];
extern void PPG_deri(float *PPG_spo2,uint16_t position,uint16_t len);
extern uint8_t find_max_uint8(uint8_t *source,uint8_t len);
extern uint8_t find_min(uint8_t *source,uint8_t len);
extern uint16_t find_max_uint16(uint16_t *source,uint8_t len);
extern uint16_t find_min_uint16(uint16_t *source,uint8_t len);
float ECG_Dry[Dry_delay],BL[10],tempArray[21],ECG_Signal_process[4][10],BL_average[4][Dry_delay*2],BL_end[4][10];
extern void initEcg2(float ecg1[],float ecg2[]);
extern void sort(float s[]);
extern void copyArray(float s[], float r[], uint8_t i);
void minus(float ecg1[],float BL[],float ecg3[]);
extern uint8_t test_signal(float *signal,float threshold,float error,uint16_t lenght,uint16_t end);



/*********************呼吸处理程序***************************/
float Breath_float[2000];
uint8_t k_breath=0,start_compute_breath=0;



/**************************************************************/

/**********************心电数据格式申请****************************/
uint8_t k=0;float max_5=0,ECG_max=0;
#define numtoprocess          10
#define MovingAverageNumber   30

/**********************血氧处理数据申请***************************/
#define NumofPPG 10
extern float PPG_derivation[1000],PPG_data_IR[1000],PPG_data_RED[1000]={0};
uint8_t PPG_peak_flag[1000],k_spo2,time_spo2,P_mean,Highblood,median_value,High_average,PTT[8],PTT_average,PTT_max,PTT_min,Highblood_ever;
uint16_t i_start,end_spo2,distance_spo2,distance_spo2_peak;
float k_blood;
uint16_t num_blood=0;
uint16_t PPG_order=0,PPG_max_position,PPG_min_position;
float PPG_max,PPG_min;
float sum_blood;
float Q_RED,Q_IR,R,SPO2_f;
uint8_t SPO2;
uint16_t pulse_rate[8],pulse_rate_average,pulse_rate_max,pulse_rate_min;
uint8_t pulse_start_compute;
float PPG_derivation_max,PPG_derivation_threshold,PPG_amplitude_max,PPG_test_max;
uint8_t ECG_start_compute=0,flag_test=0;
uint8_t PPG_test[4]={1,1,1,1};
float PPG_Signal[2][Dry_delay+10],PPG_Dry[2][40],PPG_tempArray[2][21],PPG_BL[2][10],
		PPG_Signal_process[2][10],PPG_BL_average[2][160],PPG_BL_end[2][10];

uint8_t PPG[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};//调串口用的数组


#endif /* MAIN_H_ */
