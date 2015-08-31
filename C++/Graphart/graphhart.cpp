/**
* 人类智慧也可以璀璨无比！
* 三段140字符以内代码生成一张1024*1024的图片
* Tweetable Mathematical Art 比赛
* C++ 编写RD GR BL 三个函数
* 具体查看知乎问答！pdf
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define DIM 1024
#define DMI (DIM - 1)
#define _sq(x) ((x) * (x))  //square
#define _cb(x) abs((x) * (x) * (x)) //absolute value of cube
#define _cr(x) (unsigned char)(pow((x), 1.0 / 3.0)) //cube root

// 第一版本：
unsigned char RD0(int i, int j)
{
    // TODO
    return (char)(_sq(cos(atan2(j - 512, i - 512) / 2)) * 255);
}

unsigned char GR0(int i, int j)
{
    // TODO
    return (char)(_sq(cos(atan2(j - 512, i - 512) / 2 - 2 * acos(-1) / 3)) * 255);
}

unsigned char BL0(int i, int j)
{
    // TODO
    return (char)(_sq(cos(atan2(j - 512, i - 512) / 2 + 2 * acos(-1) / 3)) * 255);
}

// 第二版本：
unsigned char RD1(int i, int j)
{
    // TODO
    double a=0,b=0,c,d,n=0;
    while((c=a*a)+(d=b*b)<4&&n++<880)
    {
        b=2*a*b+(j)*9e-9-.645411;
        a=c-d+(i)*9e-9+.356888;
    }
    return 8000*pow((n)/800,.5);
}

unsigned char GR1(int i, int j)
{
    // TODO
    double a=0,b=0,c,d,n=0;
    while((c=a*a)+(d=b*b)<4&&n++<880)
    {
        b=2*a*b+(j)*9e-9-.645411;
        a=c-d+(i)*9e-9+.356888;
    }
    return 40*pow((n)/800,.5);
}

unsigned char BL1(int i, int j)
{
    // TODO
    double a=0,b=0,c,d,n=0;
    while((c=a*a)+(d=b*b)<4&&n++<880)
    {
        b=2*a*b+(j)*9e-9-.645411;
        a=c-d+(i)*9e-9+.356888;
    }
    return 10*pow((n)/800,.5);
}

// 第三版本：
unsigned char GR2(int i, int j);

unsigned char RD2(int i, int j)
{
    // TODO
    #define F float
    #define L(X,Y,Z) sqrt(X*X+Y*Y+Z*Z)
    #define N(X,Y,Z) {F K=L(X,Y,Z);X/=K;Y/=K;Z/=K;}
    return GR2(i, j);
}
F x,y,z,g,Q,W,E,X,Y,Z,J,A,B,C,r,R,V,S,T,P;
F M(F x,F y,F z){ A=x,B=y,C=z,R=1; for(int i=0;i<500;++i) { r=L(A,B,C); if(r>6)break; T=acos(C/r)*8; P=atan(B/A)*8; R=pow(r,7)*8*R+1;V=pow(r,8);S=sin(T);A=V*S*cos(P)+x;B=V*S*sin(P)+y;C=V*cos(T)+z;}return log(r)*r/R/2;}
unsigned char GR2(int i, int j)
{
    // TODO
    y=4,x=z=g=0,Q=(F)i/DIM-0.5,W=-1,E=(F)j/DIM-0.5;
    N(Q,W,E)
    while(g<10)
    {
        J=M(x,y,z);
        g+=J;
        x+=J*Q;
        y+=J*W;
        z+=J*E;
        if(J<0.01)
        {
            J=M(x,y,z);
            X=M(x+0.001,y,z)-J;
            Y=M(x,y+0.001,z)-J;
            Z=M(x,y,z+0.001)-J;
            N(X,Y,Z)
            return 255*fmax(0,-Z);
        }
    }
    return 0;
}

unsigned char BL2(int i, int j)
{
    // TODO
    return GR2(i, j);
}

// 第四版本：
unsigned char BL3(int i, int j);
unsigned char GR3(int i, int j);

unsigned char RD3(int i, int j)
{
    // TODO
    #define f(a,b) for(a=0;++a<b;)
    #define D float x=0,y=0
    static int z,m,n;
    if(!z)
    {
        z=1;
        f(m,4096)
        f(n,4096)
        BL3(m-4096, n-4096);
    };
    return GR3(i, j);
}

unsigned char GR3(int i, int j)
{
    // TODO
    #define R a=x*x-y*y+i/1024.+2;y=2*x*y+j/1024.+2
    static float c[DIM][DIM], p;
    if(i>=0)
    {
        return (p = c[i][j]) > DMI ? DMI : p;
    }
    c[j+DIM][i/2+DIM] += i % 2 * 2 + 1;
}

unsigned char BL3(int i, int j)
{
    // TODO
    D,a,k,p=0;
    if(i<0)
    {
        f(k,5e5)
        {
            R;
            x = a;
            if(x*x>4||y*y>4)
            {
                break;
            }
            GR3(int((x-2)*256)*2-p, (y-2)*256);
            if(!p&&k==5e5-1)
            {
                x=y=k=0;
                p=1;
            }
        }
    }
    return GR3(i, j);
}

// 第五版本：
unsigned char RD4(int i, int j)
{
    // TODO
    double a=0,b=0,d,n=0;
    for( ; a*a+(d=b*b) < 4&&n++<8192; b=2*a*b+j/5e4+.06,a=a*a-d+i/5e4+.34);
    return n/4;
}

unsigned char GR4(int i, int j)
{
    // TODO
    return 2 * RD4(i, j);
}

unsigned char BL4(int i, int j)
{
    // TODO
    return 4 * RD4(i, j);
}

// 第六版本：
unsigned char RD5(int i, int j)
{
    // TODO
    double a=0,b=0,c,d,n=0;
    while((c=a*a)+(d=b*b)<4&&n++<880)
    {
        b=2*a*b+j*8e-9-.645411;
        a=c-d+i*8e-9+.356888;
    }
    return 255 * pow((n-80) / 800, 3.0);
}

unsigned char GR5(int i, int j)
{
    // TODO
    double a=0,b=0,c,d,n=0;
    while((c=a*a)+(d=b*b)<4&&n++<880)
    {
        b=2*a*b+j*8e-9-.645411;
        a=c-d+i*8e-9+.356888;
    }
    return 255 * pow((n-80) / 800, 0.7);
}

unsigned char BL5(int i, int j)
{
    // TODO
    double a=0,b=0,c,d,n=0;
    while((c=a*a)+(d=b*b)<4&&n++<880)
    {
        b=2*a*b+j*8e-9-.645411;
        a=c-d+i*8e-9+.356888;
    }
    return 255 * pow((n-80) / 800, 0.5);
}

// 第七版本：
/*
* Edit: It's really hard to come up with decent colour schemes with these few remaining bytes. Here is one other version:
*   // RED      return log(k)*47;
*   // GREEN    return log(k)*47;
*   // BLUE     return 128-log(k)*23;
*
*/
unsigned char RD6(int i, int j)
{
    // TODO
    float x=0,y=0;
    int k;
    for(k=0;k++<256;)
        {
            float a=x*x-y*y+(i-768.0)/512;
            y=2*x*y+(j-512.0)/512;
            x=a;
            if(x*x+y*y>4)
                break;
        }
    return k>31?256:k*8;
}

unsigned char GR6(int i, int j)
{
    // TODO
    float x=0,y=0;
    int k;
    for(k=0;k++<256;)
    {
        float a=x*x-y*y+(i-768.0)/512;
        y=2*x*y+(j-512.0)/512;
        x=a;
        if(x*x+y*y>4)
            break;
    }
    return k>63 ? 256 : k*4;
}

unsigned char BL6(int i, int j)
{
    // TODO
    float x=0,y=0;
    int k;
    for(k=0;k++<256;)
    {
        float a=x*x-y*y+(i-768.0)/512;
        y=2*x*y+(j-512.0)/512;
        x=a;
        if(x*x+y*y>4)
            break;
    }
    return k;
}

// 第八版本：
unsigned char RD7(int i, int j)
{
    // TODO
    #define r(n)(rand()%n)
    static char c[1024][1024];
    return !c[i][j] ? c[i][j] = !r(999) ? r(256) : RD7((i+r(2)) % 1024, (j+r(2)) % 1024) : c[i][j];
}

unsigned char GR7(int i, int j)
{
    // TODO
    static char c[1024][1024];
    return !c[i][j] ? c[i][j] = !r(999) ? r(256) : GR7((i+r(2)) % 1024, (j+r(2)) % 1024) : c[i][j];
}

unsigned char BL7(int i, int j)
{
    // TODO
    static char c[1024][1024];
    return !c[i][j] ? c[i][j] = !r(999) ? r(256) : BL7((i+r(2)) % 1024, (j+r(2)) % 1024) : c[i][j];
}
// random walk isotropic: static char c[1024][1024];return!c[i][j]?c[i][j]=r(999)?red_fn((i+r(5)+1022)%1024,(j+r(5)+1022)%1024):r(256):c[i][j];

// 第九版本：
unsigned char RD8(int i, int j)
{
    // TODO
    #define P 6.03
    float s = 3.0 / (j+250);
    float y = (j + sin((i*i+_sq(j-700)*5)/100./DIM+P)*15)*s;
    return (int((i+DIM)*s+y)%2 + int((DIM*2-i)*s+y)%2)*127;
}

unsigned char GR8(int i, int j)
{
    // TODO
    float s = 3.0 / (j+250);
    float y = (j + sin((i*i+_sq(j-700)*5)/100./DIM+P)*15)*s;
    return (int(5*((i+DIM)*s+y))%2 + int(5*((DIM*2-i)*s+y))%2)*127;
}

unsigned char BL8(int i, int j)
{
    // TODO
    float s = 3.0 / (j+250);
    float y = (j + sin((i*i+_sq(j-700)*5)/100./DIM+P)*15)*s;
    return (int(29*((i+DIM)*s+y))%2 + int(29*((DIM*2-i)*s+y))%2)*127;
}

// 第十版本：
unsigned char BL9(int i, int j);

unsigned char RD9(int i, int j)
{
    // TODO
    #define LEFT (i < DIM/2)
    #define C1 C(DIM/2, DIM/2, DIM/2)
    #define C2 C(DIM/2, DIM/4, DIM/4)
    return BL9(i, j);
}

unsigned char GR9(int i, int j)
{
    // TODO
    #define C3 C(DIM/2, 3*DIM/4, DIM/4)
    #define C4 C(DIM/2, DIM/4, DIM/16)
    #define C5 C(DIM/2, 3*DIM/4, DIM/16)
    return BL9(i, j);
}

unsigned char BL9(int i, int j)
{
    // TODO
    #define C(x, y, r) (_sq(i - (x)) + _sq(j - (y)) < _sq((r)))
    return !C1 ? 127 : C2 ? C4 ? 0 : 255 : C3 ? C5 ? 255: 0 : LEFT ? 255 : 0;
}


void pixel_write(int, int, int);
FILE *fp;

int main()
{
    const char filename[10][20] = {"MathPic1.ppm", "MathPic2.ppm", "MathPic3.ppm", "MathPic4.ppm",
                                    "MathPic5.ppm", "MathPic6.ppm", "MathPic7.ppm", "MathPic8.ppm",
                                    "MathPic9.ppm", "MathPic10.ppm"};

    for (int f = 0; f < 10; f++)
    {
        printf("Now it is making up picture %d:\n", f);
        fp = fopen(filename[f], "wb");
        fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
        /*
        * ppm Linux图片格式
        * 头文件 + rgb 数据
        * P6/n              // P6 表示ppm这种格式
        * width heigth\n    // 图像宽度和高度，空格隔开
        * 225\n             // 每个颜色分量最大值
        * rgbrgb...         // 数据从上到下，从左到右排放。
        *
        */

        for (int j = 0; j < DIM; j++)
        {
            for (int i = 0; i < DIM; i++)
            {
                pixel_write(i, j, f);
            }
        }

        fclose(fp);
    }

    return 0;
}

void pixel_write(int i, int j, int k)
{
    static unsigned char color[3];
    switch (k)
    {   // 优化：定义函数指针，循环处理！
    case 0:
        color[0] = RD0(i, j)&255;
        color[1] = GR0(i, j)&255;
        color[2] = BL0(i, j)&255;
        break;
    case 1:
        color[0] = RD1(i, j)&255;
        color[1] = GR1(i, j)&255;
        color[2] = BL1(i, j)&255;
        break;
    case 2:
        color[0] = RD2(i, j)&255;
        color[1] = GR2(i, j)&255;
        color[2] = BL2(i, j)&255;
        break;
    case 3:
//        color[0] = RD3(i, j)&255;
//        color[1] = GR3(i, j)&255;
//       color[2] = BL3(i, j)&255;
        break;
    case 4:
        color[0] = RD4(i, j)&255;
        color[1] = GR4(i, j)&255;
        color[2] = BL4(i, j)&255;
        break;
    case 5:
        color[0] = RD5(i, j)&255;
        color[1] = GR5(i, j)&255;
        color[2] = BL5(i, j)&255;
        break;
    case 6:
        color[0] = RD6(i, j)&255;
        color[1] = GR6(i, j)&255;
        color[2] = BL6(i, j)&255;
        break;
    case 7:
        color[0] = RD7(i, j)&255;
        color[1] = GR7(i, j)&255;
        color[2] = BL7(i, j)&255;
        break;
    case 8:
        color[0] = RD8(i, j)&255;
        color[1] = GR8(i, j)&255;
        color[2] = BL8(i, j)&255;
        break;
    case 9:
        color[0] = RD9(i, j)&255;
        color[1] = GR9(i, j)&255;
        color[2] = BL9(i, j)&255;
        break;
    default :
        printf("This method has not been completed!\n");
        break;
    }
    fwrite(color, 1, 3, fp);
}
