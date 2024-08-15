#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int cnt = 0; // 크로아티아 알파벳 갯수
	char str[101];
	scanf("%s", str);

	int i = 0;
	while (str[i])
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == '=' || str[i + 1] == '-')
			{
				cnt++;
				i += 2;
			}
			else
			{
				cnt++;
				i++;
			}
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				cnt++;
				i += 3;
			}
			else if (str[i + 1] == '-')
			{
				cnt++;
				i += 2;
			}
			else
			{
				cnt++;
				i++;
			}
		}
		else if (str[i] == 'l' && str[i + 1] == 'j')
		{
			cnt++;
			i += 2;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j')
		{
			cnt++;
			i += 2;
		}
		else if (str[i] == 's' && str[i + 1] == '=')
		{
			cnt++;
			i += 2;
		}
		else if (str[i] == 'z' && str[i + 1] == '=')
		{
			cnt++;
			i += 2;
		}
		else
		{
			cnt++;
			i++;
		}
	}
	printf("%d", cnt);
}