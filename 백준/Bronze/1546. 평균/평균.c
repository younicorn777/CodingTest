#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double score[1000] = { 0.0 };
	int n = 0;        // 시험 본 과목의 개수
	double sum = 0.0; // 새롭게 정의된 점수들의 합

	scanf("%d", &n);

	scanf("%lf", &score[0]);
	double max = score[0];

	for (int i = 1; i < n; i++) {
		scanf("%lf", &score[i]);
		max = max > score[i] ? max : score[i];
	}

	for (int i = 0; i < n; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}
	printf("%lf", sum / n);
}