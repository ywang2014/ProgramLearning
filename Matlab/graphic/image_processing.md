# 常用的一些图像处理Matlab源代码

[1.数字图像矩阵数据的显示及其傅立叶变换](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#1)

[2.二维离散余弦变换的图像压缩](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#2)

[3.采用灰度变换的方法增强图像的对比度](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#3)

[4.直方图均匀化](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#4)

[5.模拟图像受高斯白噪声和椒盐噪声的影响](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#5)

[6.采用二维中值滤波函数medfilt2对受椒盐噪声干扰的图像滤波](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#6)

[7.采用MATLAB中的函数filter2对受噪声干扰的图像进行均值滤波](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#7)

[8.图像的自适应魏纳滤波](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#8)

[9.运用5种不同的梯度增强法进行图像锐化](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#9)

[10.图像的高通滤波和掩模处理](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#10)

[11.利用巴特沃斯（Butterworth）低通滤波器对受噪声干扰的图像进行平滑处理](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#11)

[12.利用巴特沃斯（Butterworth）高通滤波器对受噪声干扰的图像进行平滑处理](https://github.com/ywang2014/ProgramLearning/tree/master/Matlib/graphic/image_processing.md#12)

 
#### <a name = "1"> </a>数字图像矩阵数据的显示及其傅立叶变换

	f=zeros(30,30);
	f(5:24,13:17)=1;
	imshow(f, 'notruesize');
	F=fft2(f,256,256); % 快速傅立叶变换算法只能处矩阵维数为2的幂次，f矩阵不
						  % 是，通过对f矩阵进行零填充来调整   
	F2=fftshift(F);      % 一般在计算图形函数的傅立叶变换时，坐标原点在
						  % 函数图形的中心位置处，而计算机在对图像执行傅立叶变换
						  % 时是以图像的左上角为坐标原点。所以使用函数fftshift进
						  %行修正，使变换后的直流分量位于图形的中心；
	figure,imshow(log(abs(F2)),[-1 5],'notruesize');
 
 
#### <a name = "2"> </a>二维离散余弦变换的图像压缩

	I=imread('cameraman.tif');           % MATLAB自带的图像
	imshow(I);
	clear;close all
	I=imread('cameraman.tif');
	imshow(I);
	I=im2double(I);
	T=dctmtx(8);
	B=blkproc(I,[8 8], 'P1*x*P2',T,T');
	Mask=[1 1 1 1 0 0 0 0
		   1 1 1 0 0 0 0 0
		   1 1 0 0 0 0 0 0
		   1 0 0 0 0 0 0 0
		   0 0 0 0 0 0 0 0
		   0 0 0 0 0 0 0 0
		   0 0 0 0 0 0 0 0
		   0 0 0 0 0 0 0 0];
	B2=blkproc(B,[8 8],'P1.*x',Mask);    % 此处为点乘(.*)
	I2=blkproc(B2,[8 8], 'P1*x*P2',T',T);
	figure,imshow(I2);                 % 重建后的图像
 
#### <a name = "3"> </a>采用灰度变换的方法增强图像的对比度

	I=imread('rice.tif');
	imshow(I);
	figure,imhist(I);
	J=imadjust(I,[0.15 0.9], [0 1]);
	figure,imshow(J);
	figure,imhist(J);
 
 
#### <a name = "4"> </a>直方图均匀化

	I=imread('pout.tif');  % 读取MATLAB自带的potu.tif图像
	imshow(I);
	figure,imhist(I);     
	[J,T]=histeq(I,64);      % 图像灰度扩展到0~255，但是只有64个灰度级
	figure,imshow(J);
	figure,imhist(J);
	figure,plot((0:255)/255,T); % 转移函数的变换曲线
	J=histeq(I,32);
	figure,imshow(J);   % 图像灰度扩展到0~255，但是只有32个灰度级
	figure,imhist(J);
	
#### <a name = "5"> </a>模拟图像受高斯白噪声和椒盐噪声的影响

	I=imread('eight.tif');
	imshow(I) ;

	J1=imnoise(I,'gaussian',0,0.02); % 叠加均值为0，方差为0.02的高斯噪声，可以用
										   % localvar代替figure,imshow  (J1);

	J2=imnoise(I,'salt & pepper',0.04); % 叠加密度为0.04的椒盐噪声。
											  
	figure,imshow(J2);
 
#### <a name = "6"> </a>采用二维中值滤波函数medfilt2对受椒盐噪声干扰的图像

	I=imread('eight.tif');
	imshow(I) ;

	J2=imnoise(I,'salt & pepper',0.04); % 叠加密度为0.04的椒盐噪声。
											  
	figure,imshow(J2);

	I_Filter1=medfilt2(J2,[3 3]);  %窗口大小为3×3
	figure,imshow(I_Filter1);
	I_Filter2=medfilt2(J2,[5 5]);  %窗口大小为5×5
	figure,imshow(I_Filter2);
	I_Filter3=medfilt2(J2,[7 7]);  %窗口大小为7×7
	figure,imshow(I_Filter3);
 
 
#### <a name = "7"> </a>采用MATLAB中的函数filter2对受噪声干扰的图像进行均值滤波

	[I,map]=imread('eight.tif');
	figure,imshow(I);title('original')
	J1=imnoise(I,'gaussian',0,0.02); % 受高斯噪声干扰
	M4=[0 1 0; 1 0 1; 0 1 0];
	M4=M4/4;                 % 4邻域平均滤波
	I_filter1=filter2(M4,J1);
	figure,imshow(I_filter1,map);  

	M8=[1 1 1; 1 0 1; 1 1 1];      % 8邻域平均滤波
	M8=M8/8;
	I_filter2=filter2(M8,J1);
	figure,imshow(I_filter2,map); 
	
#### <a name = "8"> </a>图像的自适应魏纳滤波

	[I,map]=imread('eight.tif');
	figure,imshow(I);title('original')
	J1=imnoise(I,'gaussian',0,0.02); % 受高斯噪声干扰
	[K noise]=wiener2(J1, [5 5]);
	figure,imshow(K);  
	
#### <a name = "9"> </a>运用5种不同的梯度增强法进行图像锐化

	[I,map]=imread('3-22.jpg');
	imshow(I,map);
	I=double(I);
	[Gx,Gy]=gradient(I);       % 计算梯度
	G=sqrt(Gx.*Gx+Gy.*Gy);   % 注意是矩阵点乘

	J1=G;
	figure,imshow(J1,map);    % 第一种图像增强

	J2=I;                   % 第二种图像增强
	K=find(G>=7);
	J2(K)=G(K);
	figure,imshow(J2,map);

	J3=I;                   % 第三种图像增强
	K=find(G>=7);
	J3(K)=255;
	figure,imshow(J3,map);

	J4=I;                   % 第四种图像增强
	K=find(G<=7);
	J4(K)=255;
	figure,imshow(J4,map);

	J5=I;                   % 第五种图像增强
	K=find(G<=7);
	J5(K)=0;
	Q=find(G>=7);
	J5(Q)=255;
	figure,imshow(J5,map);   
	
#### <a name = "10"> </a>图像的高通滤波和掩模处理

	[I,map]=imread('blood1.tif');
	imshow(I,map);
	H2=[-1 -1 -1;-1 -9 -1;-1 -1 -1];
	J1=filter2(H2,I);             % 高通滤波
	figure,imshow(J1,map);

	I=double(I);
	M=[1 1 1;1 1 1;1 1 1]/9;
	J2=filter2(M,I);
	J3=I-J2;                % 掩模
	figure,imshow(J3,map);
	
#### <a name = "11"> </a>利用巴特沃斯（Butterworth）低通滤波器对受噪声干扰的图像进行平滑处理
	I=imread('Saturn.tif');
	imshow(I);
	J1=imnoise(I,'salt & pepper');   % 叠加椒盐噪声
	figure,imshow(J1);
	f=double(J1);     % 数据类型转换，MATLAB不支持图像的无符号整型的计算
	g=fft2(f);        % 傅立叶变换
	g=fftshift(g);     % 转换数据矩阵
	[M,N]=size(g);
	nn=2;           % 二阶巴特沃斯(Butterworth)低通滤波器
	d0=50;
	m=fix(M/2); n=fix(N/2);
	for i=1:M
		   for j=1:N
			   d=sqrt((i-m)^2+(j-n)^2);
			   h=1/(1+0.414*(d/d0)^(2*nn));  % 计算低通滤波器传递函数
			   result(i,j)=h*g(i,j);
		   end
	end
	result=ifftshift(result);
	J2=ifft2(result);
	J3=uint8(real(J2));
	figure,imshow(J3);                      % 显示滤波处理后的图像
	
#### <a name = "12"> </a>利用巴特沃斯（Butterworth）高通滤波器对受噪声干扰的图像进行平滑处理

	I=imread('blood1.tif');
	imshow(I);
	f=double(I);     % 数据类型转换，MATLAB不支持图像的无符号整型的计算
	g=fft2(f);        % 傅立叶变换
	g=fftshift(g);     % 转换数据矩阵
	[M,N]=size(g);
	nn=2;           % 二阶巴特沃斯(Butterworth)高通滤波器
	d0=5;
	m=fix(M/2);
	n=fix(N/2);
	for i=1:M
		   for j=1:N
			   d=sqrt((i-m)^2+(j-n)^2);
			   if (d==0)
				  h=0;
			   else
				  h=1/(1+0.414*(d0/d)^(2*nn));% 计算传递函数
			   end
	result(i,j)=h*g(i,j);
	end
	end
	result=ifftshift(result);
	J2=ifft2(result);
	J3=uint8(real(J2));
	figure,imshow(J3);  % 滤波后图像显示