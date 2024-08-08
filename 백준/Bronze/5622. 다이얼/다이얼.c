#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short time = 0;
	char str[15] = { '\0' };
	scanf("%s", str);

	short i = -1;
	while (str[++i])
	{
		if (str[i] >= 87) // wxyz
			time += 10; 
		else if (str[i] >= 84) // tuv
			time += 9;
		else if (str[i] >= 80) // pqrs
			time += 8;
		else if (str[i] >= 77) // mno
			time += 7;
		else if (str[i] >= 74) // jkl
			time += 6;
		else if (str[i] >= 71) // ghi
			time += 5;
		else if (str[i] >= 68) // def
			time += 4;
		else if (str[i] >= 65) // abc
			time += 3;
		else
			time += 2;
	}
	printf("%hd", time);
}