#include "main.h"

/**
 * envir - excutes the /bin/ls program to list files
 * @line: an array of command, arguments
 *
 * Return: returns 1 in success, -1 if it fails
 */

int envir(char *line[] __attribute__((unused)))
{
int i = 0;

while (environ[i] != NULL)
{
write(1, environ[i], strleng(environ[i]));
write(1, "\n", 2);
i++;
}
free(line);
return (1);
}

/**
 * maker - excutes the /bin/ls program to list files
 * @line: an array of command, arguments
 *
 * Return: returns 1 in success, -1 if otherwise
 */

int maker(char *line[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
perror("Forking");

if (child == 0)
{
execve("/bin/mkdir", line, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
perror("Waiting");
}
free(line);
return (1);
}

/**
 * stringer - a sipport function to the string breaker
 * @line: a string pointer
 * @i: start of the string index
 * @str: a string pointer to the location
 * @c: a character which specifys where to end the string
 *
 * Return: returns a string pointer
 */

char *stringer(char *line, int i, char *str, char c)
{
int k = 0;
char *tmp;

str = malloc(64);
if (str == NULL)
{
perror("Couldn't Allocate");
return (NULL);
}
while (line[i] != c && line[i] != '\0')
{
str[k] = line[i++];
k++;
if (k > 60)
{
tmp = realloc(str, (k + 8));
if (!tmp)
{
perror("Error");
return (NULL);
}
else
str = tmp;
}
}

str[k] = '\0';

return (str);
}
