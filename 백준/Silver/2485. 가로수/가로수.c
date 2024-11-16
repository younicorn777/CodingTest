#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tree[100000];
int tree_distance[100000];

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() 
{
	int n, gap, count = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &tree[i]);

	for (int i = 0; i < n - 1; i++)
		tree_distance[i] = tree[i + 1] - tree[i];

	gap = tree_distance[0];
	for (int i = 1; i < n - 1; i++)
		gap = gcd(gap, tree_distance[i]);
	
	for (int i = 0; i < n - 1; i++)
		count += (tree_distance[i] / gap) - 1;

	printf("%d", count);
}