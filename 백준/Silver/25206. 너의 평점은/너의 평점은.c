#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char dept[51], grade[3];       // 과목명, 과목평점(글)
	double credit, point = 0.0;    // 학점, 과목평점(수)
	double dsum = 0.0, csum = 0.0; // 전공과목별합, 학점합
	
	for (int i = 0; i < 20; i++)
	{
		point = 0.0;
		scanf("%s%lf%s", dept, &credit, grade);

		if (grade[0] == 'P')
			continue;
		
		// 과목 평점 구하기
		if (grade[0] == 'A')
			point += 4.0;
		else if (grade[0] == 'B')
			point += 3.0;
		else if (grade[0] == 'C')
			point += 2.0;
		else if (grade[0] == 'D')
			point += 1.0;
		else
			point += 0.0;

		if (grade[1] == '+')
			point += 0.5;

		dsum += (credit * point); 
		csum += credit; 
	}
	printf("%lf", dsum / csum);
}