#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Sum(int m, int n)
{
	return ((m & n) << 1) + (m ^ n);//��������
}
int Ave(int a, int b)
{
	return ((a ^ b) >> 1) + (a & b);//������ƽ����
}
int main()
{
	int r = Sum(2,4);
	int c = Ave(2, 4);
	printf("%d,%d", r,c);
	return 0;
}