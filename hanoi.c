#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int hanoi_twice(int n)
{
	if (1 == n)
		return 1;
	else
		return 2 * hanoi_twice(n - 1) + 1;
}

void Hanoi_Step(int n, char A, char B, char C)
{
	if (1 == n)
		printf("%c --> %c\n", A, C);
	else
	{
		Hanoi_Step(n - 1, A, C, B);//从A绕过C移到B
		printf("%c --> %c\t", A, C);
		Hanoi_Step(n - 1, B, A, C);//从B绕过A移到C
	}
}

int main()
{
	int n;
	scanf("%d", &n);//塔数
	int ret = hanoi_twice(n);
	Hanoi_Step(n, 'A', 'B', 'C');
	printf("完成%d层的汉诺塔需要%d步。\n", n, ret);
	return 0;
}