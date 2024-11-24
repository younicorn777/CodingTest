#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	int count[4] = { 0 }, size;
	char str[101], data;

	while (scanf("%[^\n]s", str) != EOF)
	{
		getchar();
		size = strlen(str);

		for (int i = 0; i < size; i++)
		{
			data = str[i];
			
			if (islower(data))
				count[0]++;
			else if (isupper(data))
				count[1]++;
			else if (isdigit(data))
				count[2]++;
			else
				count[3]++;
		}

		for (int i = 0; i < 4; i++)
		{
			printf("%d ", count[i]);
			count[i] = 0;
		}
		puts("");
	}
}