#include "sandpiles.h"

/**
* sandpiles_sum - function
*
* @grid1: grid
* @grid2: grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;
	int i = 0, j = 0;
	int grid3[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	while (i <= 2 || unstable)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
			{
				unstable = 1;
				grid2[i][j] = -4;
				if (i > 0)
					grid3[i - 1][j] += 1;
				if (j > 0)
					grid3[i][j - 1] += 1;
				if (i < 2)
					grid3[i + 1][j] += 1;
				if (j < 2)
					grid3[i][j + 1] += 1;
			}
			else
				grid2[i][j] = 0;
		}
		i++;
		if (i == 3 && unstable)
		{
			print(grid1);
			sum(grid2, grid3);
			reset(grid3);
			i = 0;
			unstable = 0;
		}
	}
}

/**
* print - print
*
* @grid: grid
*/
void print(int grid[3][3])
{
	int i;
	int j;

	printf("=\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
* reset - reset
*
* @grid: grid to reset
*/
void reset(int grid[3][3])
{
	int i;
	int j;

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			grid[i][j] = 0;
		}
	}
}

/**
* sum - sum
* @grid1: grid
* @grid2: grid
*/
void sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}
