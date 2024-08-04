#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short id[30] = { 0 }; // 학생 명부

	for (short i = 0, code; i < 28; i++) {
		scanf("%hd", &code); // 제출한 학생의 번호
		id[code - 1] = code;
	}
	
	for (short i = 0; i < 30; i++)
		if (id[i] == 0)
			printf("%hd\n", i + 1);
}