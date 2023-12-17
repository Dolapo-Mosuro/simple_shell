#include "main.h"

/**
 * _getchar - function that reads char from user input
 *
 * Return: returns the input
 */

char _getchar(void)
{
char *buf;
char c;
int i = 0;

buf = malloc(2);

if (!buf)
return (-1);

fflush(stdout);

i = read(1, buf, 1);
if (i == -1)
{
perror("Reading Input");
return (-1);
}
else if (i == 0)
{
write(1, "\n", 2);
fflush(stdout);
exit(1);
}

c = *buf;

return (c);
}

/**
 * _getline - reads a line from the standard input
 * @line: a pointer to a pointer of location to save the string
 * @len: characters read size
 *
 * Return: returns the size
 */

int _getline(char **line, size_t *len)
{
size_t limit = 25;
char *tmp;

line[0] = malloc(25);
if (!line[0])
return (-1);
*len = 0;

while (line[0][*len - 1] != '\n')
{
line[0][*len] = _getchar();
*len += 1;

if (*len > (limit - 3))
{
tmp = realloc(line[0], limit + 10);
if (tmp)
line[0] = tmp;
else
perror("Move ...");
limit += 10;
}
}

return (*len);
}

/**
 * echoer - echoes back text
 * @line: array of command, arguments
 *
 * Return: returns 1 in success. Otherwise -1
 */

int echoer(char *line[])
{
int i = 1;

if (line[i] == NULL)
{
write(1, "\n", 2);
return (1);
}

while (line[i] != NULL)
{
write(1, line[i], strleng(line[i]));
i++;
if (line[i] != NULL)
{
write(1, " ", 2);
}
}
write(1, "\n", 2);

return (1);
}
