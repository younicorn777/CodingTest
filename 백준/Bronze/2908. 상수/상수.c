#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char a[4], b[4];
	scanf("%s%s", a, b);

	for (int i = 0, j = 2, temp1 = 0, temp2 = 0; i < j; i++, j--)
	{
		temp1 = a[i];
		a[i] = a[j];
		a[j] = temp1;

		temp2 = b[i];
		b[i] = b[j];
		b[j] = temp2;
	}

	// 각자리 수끼리 비교
	for (int i = 0; i < 3; i++)
	{
		if (a[i] > b[i]) {
			printf("%s", a);
			break;
		}
		else if (a[i] < b[i]) {
			printf("%s", b);
			break;
		}	
	}
}