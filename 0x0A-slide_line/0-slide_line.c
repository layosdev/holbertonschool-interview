#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: line
 * @size: size of the array
 * @direction: direction
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != 0 && direction != 1) || (line == NULL || size < 1))
	{
		return (0);
	}
	if (direction == 0)
	{
		int i, position = 0, n = 0;

		for (i = 0; i < (int)size; i++)
		{
			if (line[i] == 0)
				position++;
			if (line[i] > 0)
				n++;
			if (line[i] > 0 && position > 0)
			{
				line[i - position] = line[i];
				line[i] = 0;
				i = i - position;
				position = 0;
			}
		}
		position = 0;
		for (i = 0; i < n; i++)
		{
			if (i < n - 1 && line[i] == line[i + 1])
			{
				line[position] = line[i] + line[i + 1];
				line[i + 1] = 0;
				if (position != i)
					line[i] = 0;
				position++;
			}
			else if (line[i] > 0 && position > 0)
			{
				line[position] = line[i];
				if (position != i)
					line[i] = 0;
				position++;
			}
			else if (line[i] > 0)
				position++;
		}
	}
	if (direction == 1)
	{
		int i, position = 0, max = size - 1, n = 0;

		for (i = max; i >= 0; i--)
		{
			if (line[i] == 0)
				position++;
			if (line[i] > 0)
				n++;
			if (line[i] > 0 && position > 0)
			{
				line[i + position] = line[i];
				line[i] = 0;
				i = i + position;
				position = 0;
			}
		}
		position = max;
		for (i = max; i > max - n; i--)
		{
			if (i > max - n + 1 && line[i] == line[i - 1])
			{
				line[position] = line[i] + line[i - 1];
				line[i - 1] = 0;
				if (position != i)
					line[i] = 0;
				position--;
			}
			else if (line[i] > 0 && position < max)
			{
				line[position] = line[i];
				if (position != i)
					line[i] = 0;
				position--;
			}
			else if (line[i] > 0)
				position--;
		}
	}
	return (1);
}
