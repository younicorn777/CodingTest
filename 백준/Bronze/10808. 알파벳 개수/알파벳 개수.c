#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int idx = 0;
	char str[101];
	int alpha_cnt[26] = { 0 };
	scanf("%s", str);

	while (str[idx] != '\0')
		alpha_cnt[str[idx++]-97]++;

	for (int i = 0; i < 26; i++)
		printf("%d ", alpha_cnt[i]);
}