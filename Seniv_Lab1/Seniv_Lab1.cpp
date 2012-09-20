// Seniv_Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.h"
#include <vector>
#include <stack>
#include <conio.h>

//variant - 6

int powi(int a, int b)
{
	int vali = a;
	for (int i = 1; i < b; i++)
		vali *= a;

	return vali;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x, a, c, m;
	char answer;

	printf("%s", "Use data of 6-th variant?\n");
	scanf("%c", &answer);

	if (answer == 'y' || answer == 'Y')
	{
		x = 64;
		a = powi(2, 3);
		c = 8;
		m = powi(2, 15) - 1;
		printf("\n x = %d, a = %d, c = %d, m = %d\n", x, a, c, m);
		getchar();
	}
	else
	{
		printf("%s", "Then enter your own values:");

		printf("\nX0 = ");
		scanf("%d", &x);

		printf("\na = ");
		scanf("%d", &a);

		printf("\nc = ");
		scanf("%d", &c);

		printf("\nm = ");
		scanf("%d", &m);
	}

// 	64, powi(2, 3), 8, powi(2, 15) - 1
	Random _random(x, a, c, m);
	RandomPeriodCalculator _randomPeriod(new Random(x, a, c, m));

	FILE *f = fopen("file.txt", "w+");

	int n;
	printf("\nHow many numbers to generate?\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int randomVal = _random.Next();
		printf("\n%d", randomVal);
		fprintf(f, "\n%d", randomVal);
	}

	int *periodVals = new int[_random.GetM()];

	int period = _randomPeriod.GetPeriod(periodVals);
	printf("\nRandom period is %d:\n", period);
	fprintf(f, "\nRandom period is %d:\n", period);

	for (int i = 0; i < period; i++)
	{
		printf("%d ", periodVals[i]);
		fprintf(f, "%d ", periodVals[i]);
	}
	printf("\n");
	fprintf(f, "\n");

	fclose(f);

	return 0;
}

