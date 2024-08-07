#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char a[4], b[4];
	scanf("%s%s", a, b);

	int temp = a[0];
	a[0] = a[2];
	a[2] = temp;

	temp = b[0];
	b[0] = b[2];
	b[2] = temp;

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