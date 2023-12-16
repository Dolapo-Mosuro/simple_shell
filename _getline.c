#include "main.h"

/**
 * _getinput - function that reads char from user input
 *
 * Return: returns the input
 */

char _getinput(void)
{
char *buff;
char c;
int i = 0;

buff = malloc(2);

if (!buff)
return (-1);

fflush(stdout);

i = read(1, buff, 1);
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

c = *buff;

return (c);
}

/**
 * _getline - reads a line from the standard input
 * @line: a pointer to a pointer of location to save the string
 * @size_char: characters read size
 *
 * Return: returns the size
 */

int _getline(char **line, size_t *size_char)
{
size_t limit = 25;
char *tmp;

line[0] = malloc(25);
if (!line[0])
return (-1);
*size_char = 0;

while (line[0][*size_char - 1] != '\n')
{
line[0][*size_char] = _getinput();
*size_char += 1;

if (*size_char > (limit - 3))
{
tmp = realloc(line[0], limit + 10);
if (tmp)
line[0] = tmp;
else
perror("Move ...");
limit += 10;
}
}

return (*size_char);
}

/**
 * echo_text - echos back text
 * @line: array of command, arguments
 *
 * Return: returns 1 in success. Otherwise -1
 */

int echo_text(char *line[])
{
int i = 1;

if (line[i] == NULL)
{
write(1, "\n", 2);
return (1);
}

while (line[i] != NULL)
{
write(1, line[i], strsize_charg(line[i]));
i++;
if (line[i] != NULL)
{
write(1, " ", 2);
}
}
write(1, "\n", 2);

return (1);
}
