#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#if 0
void Mystrlen(const char * str)//µÝ¹éÇó×Ö·û´®³¤¶È
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + Mystrlen(str + 1);
	}
}
int main()
{
	char *p= "abcdef";
	int r = Mystrlen(p);
	printf("%d", r);
	return 0;
}
#endif
#if 0

int main()
{
	char * p = "abcdef";
	int count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	printf("%d", count);
	return 0;
}
#endif

