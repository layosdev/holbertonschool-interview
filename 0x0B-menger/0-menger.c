#include "menger.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * menger - draws a 2D Menger Sponge
 * @level: depth
 */
void menger(int level)
{
	int i, j, k, m;
	int sw = 1, depth;

	if (!level)
	{
		return;
	}

	depth = pow(3, level);

	for (i = 1; i <= depth; i++)
	{
		for (j = 1; j <= depth; j++)
		{
			m = i - 1;
			k = j - 1;
			while (sw)
			{
				if (k == 0 || m == 0)
				{
					printf("#");
					break;
				}
				else if (k % 3 == 1 && m % 3 == 1)
				{
					printf(" ");
					break;
				} else
				{
					k /= 3;
					m /= 3;
				}
			}
		}
		printf("\n");
	}
}
