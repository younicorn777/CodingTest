#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short box[100]; 
	short n = 0, m = 0;

	for (int i = 0; i < 100; i++)
		box[i] = i + 1;

	scanf("%hd%hd", &n, &m);
	for (short i = 0, a = 0, b = 0; i < m; i++) {
        
		scanf("%hd%hd", &a, &b);
		for (short j = a, k = b, temp = 0; j < k; j++, k--) {
			temp = box[j - 1];
			box[j - 1] = box[k - 1];
			box[k - 1] = temp;
		}
	}
	
	for (int i = 0; i < n; i++)
		printf("%hd ", box[i]);
}