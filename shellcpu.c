#include "main.h"

/**
 * getfunc - selects a function based on commands
 * @str: a string pointer
 *
 * Return: returns 1 in success and -1 Otherwise.
 */

int (*getfunc(char *str))(char **line)
{
int i = 0;
selecte selector[] = {
{"ls", lister},
{"l", lister},
{"ll", lister},
{"exit", exitor},
{"echo", echorr},
{"cd", changedire},
{"cat", cater},
{"pwd", pwder},
{"env", envir},
{"printenv", envir},
{"/bin/printenv", envir},
{"/bin/env", envir},
{"mkdir", maker},
{NULL, NULL}};

while (!strcomp(selector[i].command, str) && (selector[i].command != NULL))
{
i++;
}

if (selector[i].command == NULL)
{
return (NULL);
}

return (selector[i].funcptr);
}

/**
 * shell_processor -  excutes given commands
 * @line: a pointer to an array of strings
 * @argv: a pointer to an array of arguments
 *
 * Return: returns 1 in success and -1 otherwise.
 */

int shell_processor(char **line, char **argv)
{
int check;
int i = 0;

if (!line)
{
return (1); }
if (getfunc(line[0]) == NULL)
{
i = builtincom(line);
if (i != 0)
{
for (i = 0; line[0][i] != '\0'; i++)
{
if (line[0][i] == '/')
{
check = 1;
break; }}
if (check == 1)
{
write(1, argv[0], strleng(argv[0]));
write(1, ": ", 3);
write(1, line[0], strleng(line[0]));
write(1, ": No such file or folder \n", 28);
exit(EXIT_FAILURE); }
else
{
write(1, line[0], strleng(line[0]));
write(1, ": not found\n", strleng(": not found\n"));
exit(EXIT_FAILURE); }}
}
else
{
getfunc(line[0])(line); }
return (1);
}
