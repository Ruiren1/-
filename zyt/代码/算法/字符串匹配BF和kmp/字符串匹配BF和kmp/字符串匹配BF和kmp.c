#include<stdio.h>
#include<string.h>
#include<malloc.h>
int  BF(char* str, char* sub)
{
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	int i = 0, j = 0;
	while (i < lenstr && j < lensub)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= lensub)
	{
		return i-j;
	}
	return -1;

}
int * getnext(char* p,int plen)
{
	int* next = (int*)malloc(sizeof(int) * plen);
	next[1] = 0;
	for (int i = 2,j=0; i < plen; i++)
	{
		while (j&&p[i] != p[j + 1])
		{
			j = next[j];
		}
		if (p[i] == p[j + 1])
		{
			j++;
			next[j] = j;
		}
	}
	return next;
}

void kmp(char* s, char* p, int slen, int plen)
{
	int* next = getnext(p, plen);
	for (int i = 1, j = 0; i <= slen; i++)
	{
		while (j && s[i] != p[j + 1]) j = next[j];
		if (s[i] == p[j + 1]) j++;
		if (j == plen)
		{
			printf("%d ", i - plen);
			j = next[j];
		}
	}
}
int main()
{
	char s[20] = { 0 };
	char p[10] = { 0 };
	kmp(s, p, sizeof(s) / sizeof(char), sizeof(p) / sizeof(char));
	return 0;
}