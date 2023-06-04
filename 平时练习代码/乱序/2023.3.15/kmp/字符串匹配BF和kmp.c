#include<stdio.h>
#include<string.h>
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
int main()
{
	printf("%d", BF("abababcdab", "abcd"));
	return 0;
}