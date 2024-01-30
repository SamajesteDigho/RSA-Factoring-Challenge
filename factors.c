#include "main.h"
/**
 * find_pair - Find Pair
 * @nb: Number to find prime factors
 * Description: Find the prime factors of the given number
 * Return: Table of prime numbers
 */
int find_pair(long int nb)
{
long int a, b, mid, qtr;
mid = nb / 2;
qtr = (nb / 4) + 1;

for (a = mid; a > 0; a--)
{
for (b = 1; b <= mid; b++)
{
if (a * b == nb)
{
printf("%ld=%ld*%ld\n", nb, a, b);
return (0);
}
}
}
return (0);
}

/**
 * main - Entry point
 * @argc: Number of params
 * @argv: Array of params
 * Description: Main function
 * Return: 0 or exit
*/
int main(int argc, char **argv)
{
FILE *file;
char buffer[30];
long int nb;

if (argc < 2)
{
printf("Usage: factors <numbers_file>\n");
exit(98);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
printf("Could not open file: %s\n", argv[1]);
exit(98);
}

while (fgets(buffer, sizeof(buffer), file))
{
nb = atoi(buffer);
find_pair(nb);
}
return (0);
}
