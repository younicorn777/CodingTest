#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, max_x, min_x, max_y, min_y;
	
	scanf("%d", &n);
	scanf("%d%d", &max_x, &max_y);
	min_x = max_x, min_y = max_y;

	for (int i = 1, x, y; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		
		if (x > max_x)
			max_x = x;
		else if (x < min_x)
			min_x = x;
		
		if (y > max_y)
			max_y = y;
		else if (y < min_y)
			min_y = y;
	}
	printf("%d", (max_x - min_x) * (max_y - min_y));
}