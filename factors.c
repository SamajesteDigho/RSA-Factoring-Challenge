#include "main.h"
/**
 * find_pair - Find Pair
 * @nb: Number to find prime factors
 * Description: Find the prime factors of the given number
 * Return: Table of prime numbers
 */
int find_pair(unsigned long long int nb)
{
unsigned long long int a, mid;
mid = nb / 2;

for (a = 2; a <= mid; a++)
{
if (nb % a == 0)
{
printf("%llu=%llu*%llu\n", nb, nb / a, a);
return (0);
}
}
return (-1);
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
unsigned long long int nb;

if (argc < 2)
{
fprintf(stderr, "Usage: factors <numbers_file>\n");
exit(98);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Could not open file: %s\n", argv[1]);
exit(98);
}

while (fgets(buffer, sizeof(buffer), file))
{
nb = atoll(buffer);
find_pair(nb);
}
return (0);
}
