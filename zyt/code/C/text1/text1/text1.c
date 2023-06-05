#include <stdio.h>

int main()
{
	char str[] = "Geneius";
	print(str);
	return 0;
}
print(char* s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}