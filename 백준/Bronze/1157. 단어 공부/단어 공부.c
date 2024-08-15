#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[1000001];

int main(void)
{
	int a = 0; // 가장 많이 나온 알파벳
	int alpha[26] = { 0 }; // 알파벳이 등장한 횟수
	scanf("%s", str);

	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			alpha[str[i] - 97]++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			alpha[str[i] - 65]++;
		i++;
	}
	
	int max = alpha[0], cnt = 0; // 가장 많이 나온 알파벳수와 해당 알파벳
	for (int i = 1; i < 26; i++)
	{
		if (alpha[i] > max) {
			max = alpha[i];
			a = i;
		}
	}

	for (int i = 0; i < 26; i++) 
	{
		if (max == alpha[i])
			cnt++;
	}

	if (cnt > 1)
		printf("?");
	else
		printf("%c", a + 65);

	return 0;
}