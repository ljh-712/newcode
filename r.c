#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int x, y;
//	double  ave;
//	scanf("%d%d", &x,&y);
//	ave = y + (x - y) / 2.0;//求平均数
//	printf("%lf", ave);
//
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	int count = 0;
//	int sum = 0;
//	int r = 0;
//	for (count = 0; count < 32; count++)
//	{
//		r =(( value >> count)&1) * pow(2, 31 - count);//25&1=1   1*2^31   随着count增加
//		sum = sum + r;
//	}
//	return sum;
//}
//int main()
//{
//	int num = 25;
//	int r = reverse_bit(num);
//	printf("%u", r);//%u输出十进制无符号整数
//	return 0;
//}
//#include<stdio.h>//求一组数中，其他数字都是成对出现的，只有一个数出现了一次
//
//int fun(int arr[], int len)
//{
//	int i = 0;
//	
//	for (i = 0; i < len; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];
//	}
//	return ;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,3,2,1 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = fun(arr, len);
//	printf("%d", ret);
//	return 0;
//}
#include<stdio.h>
void reverse(char * str)//逆序输出一个字符串
{
	if (*str != '\0')
		reverse(str + 1);
	printf("%c", *(str - 1));
}
int main()
{
	char *str = "i am a student";
	reverse(str);
	return 0;
}