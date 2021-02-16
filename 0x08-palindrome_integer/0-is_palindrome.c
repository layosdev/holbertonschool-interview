#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - check if is palindrome
 * @n: number to check
 * Return: palindrome status
 */
int is_palindrome(unsigned long n)
{
	unsigned long sum = n % 10, num = n;

	while (num /= 10)
		sum = (sum * 10) + (num % 10);

	return (n == sum);
}
