#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: the first number
 * @n2: the second number
 * @r: the buffer that the function will use to store the result
 * @size_r: the buffer size
 *
 * Return: pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, tmplen, rlen, i, sum, num1, num2, carry;
	char tmp[10000];

	rlen = i = len1 = len2 = sum = num1 = num2 = carry = 0;
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);
	len1--;
	len2--;
	while(i <= len1 || i <= len2)
	{
		num1 = num2 = 0;
		if (i <= len1)
			num1 = n1[len1 - i] - '0';
		if (i <= len2 && (len2 - i) >= 0)
			num2 = n2[len2 - i] - '0';
		sum = num1 + num2 + carry;
		if (sum >= 10)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
			sum = 0;
		r[i] = sum + '0';
		i++;
		rlen++;
	}
	if (carry > 0)
	{
		r[i] = carry + '0';
		r[i + 1] = '\0';
	}
	i = tmplen = 0;
	while (i <= rlen)
	{
		tmp [i] = r[rlen - i];
		tmplen++;
		i++;
	}
	i = 0;
	while (i < tmplen)
	{
		if (r[i] == '\0')
		{
			break;
		}
		r[i] = tmp[i];
		i++;
	}
	return (r);
}
