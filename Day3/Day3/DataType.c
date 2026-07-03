/*
data type 数据类型

1bit 1个0或1 比特位
1Byte = 8bit 字节，计算机中最小的存储单元
1024Byte = 1KB 1024KB = 1MB 1024MB = 1GB
1024GB = 1TB 1024TB = 1PB 1024PB = 1EB ---> ZB YB

不同数据类型所表示的范围和内存大小都不一样，
具体由编译器决定，可以使用sizeof来确定。
sizeof函数占位符为：%zu
例如，printf("%zu\n%zu\n",sizeof(a),sizeof(long));
short <= int <= long <= long long

一、整数类型
1、short 短整型 Windows 2个字节（-32768~32767）
2、int 整数默认类型 Windows 4个字节（-2147483648~2147483647）
3、long 长整型 Windows 4个字节（-2147483648~2147483647）
               Linux 32位 4个字节 ；64位 8个字节
			   注意赋值时需要添加后缀L/l
			   打印时，占位符为%ld
4、long long（C99）超长整型 Windows 8个字节（19位数）
                   赋值后缀 LL
				   打印占位符%lld
扩展：
1、完整定义形态
short int a = 10;
long int b = 1000;
int c = 1;
2、有符号整数和无符号整数的定义情况
unsigned 无符号
signed 有符号 默认情况
signed int d = -100;
无符号打印占位符：%u

二、小数类型（实数/浮点数）Windows中
1、float  4个字节 38位
   单精度小数，小数点后6位
   C语言中小数默认double类型，赋值float类型时，需要后缀f/F
2、double  8个字节 308位
   双精度小数，小数点后15位
   占位符为：%lf
3、long double  8个字节
   高精度小数，小数点后18~19位
   后缀 L
以科学计算法形式进行存储，因而取值范围远超整数
小数默认double类型

三、字符类型
char  取值范围：ASCII码表  Windows 1个字节
                不能写中文汉字和标点

*/

#include <stdio.h>
int main()
{
	short a = 10;
	a = 32768;
	// 超出短整型范围，出错，-32768
	int b = 100;
	b = 2147483648;
	// 超出int范围，出错，-2147483648 
	long c = 1000L;
	c = 2147483648l;
	// 超出long类型Windows系统范围，出错，-2147483648
	long long d = 10000LL;
	printf("%d\n%d\n%ld\n%lld\n",a,b,c,d);
    printf("%zu\n%zu\n%zu\n%zu\n",sizeof(a), sizeof(b), sizeof(c), sizeof(d));
	// 定义一个变量用于表示序号，无负数，即无符号整数
	unsigned int e = 1;
	printf("%u\n",e);
	// short: -32768~32767
	// unsigned short: 0~65535

	float f = 3.14F;
	double g = 9.9;
	long double h = 3.1415926L;
	printf("%.2f\n%.3lf\n%lf",f,g,h);
	printf("%zu\n%zu\n%zu\n",sizeof(f),sizeof(g),sizeof(h));

	char i = 'q';
	i = '汉';
	// 不能使用中文，报错：?
	i = 'defg';
	// 语法错误，输出最后一个字符：g
	printf("%c\n%zu",i,sizeof(i));

	return 0;
}