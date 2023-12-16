#include "main.h"

/**
 * copyarray - copy string array to another string array variable
 * @line: string array to be copied
 *
 * Return: returns the copied array
 */

char **copyarray(char **line)
{
char **array;
int i = 1;

array = malloc(64);
if (!array)
return (NULL);

while (line[i] != NULL)
{
array[(i - 1)] = malloc(32);
if (!array[(i - 1)])
return (NULL);

strcopy(line[i], array[(i - 1)]);
i++;
}

return (array);
}

/**
 * sigint_ - handle the ctrl-c signal
 * @sig_num: an integer signal indicator
 *
 * Return: void function
 */

void sigint_(int sig_num __attribute__((unused)))
{
signal(SIGINT, sigint_);
write(1, "\n", 2);
prompt_dis(0);
fflush(stdout);
}

/**
 * main - main function of shell
 * @argc: the number of arguments given
 * @argv: array of given argument strings
 *
 * Return: returns integer
 */

int main(int argc __attribute__((unused)), char **argv)
{
char *line;

line = malloc(256);
if (!line)
{
perror("Allocation");
exit(1);
}

if (!isatty(STDIN_FILENO))
{
if (getstr(line) == (-1))
{
write(1, "\n", 2);
exit(1);
}
if (shell_pro(strbrk(line, ' '), argv) == -1)
{
perror("Error");
}

exit(0);
}

do {
printprompt(0);
if (getstr(line) == (-1))
{
write(1, "\n", 2);
exit(0);
}

if ((shell_pro(strbrk(line, ' '), argv)) == -1)
{
perror("Error");
}
} while (1);

return (0);
}
