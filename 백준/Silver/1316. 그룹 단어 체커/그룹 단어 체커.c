#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	short alpha[26] = { 0 }; // 해당 알파벳이 등장한 위치
	char str[101];
	int n = 0, cnt = 0; // 단어의 개수 ,그룹 단어 갯수
	scanf("%d", &n);

	for (int i = 0, k, size; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
			alpha[j] = 0;
		
		scanf("%s", str);
		size = (int) strlen(str);
		
		for (k = 0; k < size; k++)
		{
			if (alpha[str[k] - 97] == 0) 
			{
				alpha[str[k] - 97] = k + 1;
				continue;
			}
			else 
			{
				if (((k + 1) - alpha[str[k] - 97]) <= 1)
					alpha[str[k] - 97] = k + 1;
				else
					break;
			}
		}
		if (k == size)
			cnt++;
	}
	printf("%d", cnt);
}