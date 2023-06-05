#include<stdio.h>
#include<assert.h>
size_t strlen(const char* str)
{
	/*int len;
	while(*str)
	{
		len++;
		str++;
	}
	return len;*/
	/*if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + strlen(str + 1);
	}*/
	char* p = str;
	while (*p)
		p++;
	return p - str;//指针相减等于相隔的步长；

}
char* strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest);
	assert(src);
	while ((*dest++ = *src++));
	return ret;	
}
char* strcat(char* dest, const  char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while ((*dest++ = *src++));
	return ret;
}


int main()
{
	int a[] = "012345\06789";
	int	m = strlen(a);
	return 0;
}