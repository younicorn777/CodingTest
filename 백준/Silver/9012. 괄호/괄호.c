#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _strInfo
{
	char str[51];//문장
	int size;    //글자 개수
}Str;

int main(void)
{
	int t;
	scanf("%d", &t);
	Str* parr = (Str*)malloc(sizeof(Str) * t);

	for (int i = 0, j, count; i < t; i++)
	{
		count = 0;
		scanf("%s", parr[i].str);
		parr[i].size = strlen(parr[i].str);

		for (j = 0; j < parr[i].size; j++)
		{
			if (count == 0 && (parr[i].str)[j] == ')')
			{
				printf("NO\n");
				break;
			}
			else if ((parr[i].str)[j] == '(')
				count++;
			else if ((parr[i].str)[j] == ')')
				count--;
		}

		if (j == parr[i].size)
			(count == 0) ? printf("YES\n") : printf("NO\n");
	}
	free(parr);
}