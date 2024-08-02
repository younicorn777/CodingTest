#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[1000000] = { 0 };

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	int max = num[0], min = num[0]; // 최댓값, 최솟값

	for (int i = 1; i < n; i++) {
		max = max > num[i] ? max : num[i];
		min = min < num[i] ? min : num[i];
	}
	printf("%d %d", min, max);
}