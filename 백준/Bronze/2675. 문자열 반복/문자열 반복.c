#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short t = 0; 
	scanf("%hd", &t);

	for (short i = 0, r = 0; i < t; i++) {
		char s[20] = { '\0' };
		scanf("%hd%s", &r, s);

		short a = -1;
		while (s[++a] != '\0')
		{
			for (int j = 0; j < r; j++)
				printf("%c", s[a]);
		}
		printf("\n");
	}
}