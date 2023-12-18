#include "main.h"

/**
* lister- This excutes /bin/ls program to list files
* @line: array of command, argument
*
* Return: returns 1 in success. Otherwise -1
*/

int lister(char *line[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking ...");
}

if (child == 0)
{
execve("/bin/ls", line, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(line);

return (1);
}

/**
* cater - excutes the /bin/cat program to show text files
* @line: an array of command and arguments
*
* Return: returns 1 in success. Otherwise -1
*/

int cater(char *line[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking ...");
}
if (child == 0)
{
execve("/bin/cat", line, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(line);

return (1);
}

/**
* builtincom - excutes when unlisted command entered
* @line: is a pointer to pointer of characters
*
* Return: return integer
*/

int builtincom(char **line)
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking ...");
}

if (child == 0)
{
execve(line[0], line, NULL);
if (errno != 0)
{
return (errno);
}
}
else
{
waiter = wait(&status);

if (waiter == -1)
{
perror("Waiting");
}
}

free(line);
return (0);
}

/**
* pwder - a function which prints the current path
* @line: an array of command and arguments
*
* Return: returns 1 in success and -1 if it fails
*/

int pwder(char *line[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
perror("Forking ...");

if (child == 0)
{
execve("/bin/pwd", line, NULL);
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
* echorr - echo back any text
* @line: array of command, arguments
*
* Return: returns 1 in success. Otherwise -1
*/

int echorr(char *line[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking ...");
}
if (child == 0)
{
execve("/bin/echo", line, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(line);

return (1);
}
