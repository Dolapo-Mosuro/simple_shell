#include "main.h"

/**
 * strcomp - compare two strings
 * @str: first string to compare
 * @equ: second string to comapre
 *
 * Return: returns an integer indicater of boolean(true/false)
 */

int strcomp(char *str, char *equ)
{
int i = 0;
int result = 0;

if (str == NULL || equ == NULL)
{
return (0);
}
while (equ[i] != '\0' || str[i] != '\0')
{

if (str[i] == equ[i])
{
result = 1;
}
else
{
result = 0;
}
i++;
}

return (result);
}

/**
 * description -  discription about program
 *
 * Return: void
 */

void description(void)
{
printstar();
printstar();
printstr("~- H.E.L.L.O _ W.A.R.M _ W.E.L.C.O.M.E -~");
printstr("");
printstr("This is a simple bash shell project.");
printstr("Designed by sertse and faj for ALX SE ");
printstr("https://github.com/sertsev");
printstar();
printstar();
}


/**
 * printstar - print astar line
 *
 * Return: void
 */

void printstar(void)
{
int i = 0;
write(1, "\n\t\t\t", 5);

while (i < 75)
{
write(1, "*", 2);
i++;
}
}

/**
 * printstr - print a given string between a stars
 * @s: a string location pointer
 *
 * Return: void
 */

void printstr(char *s)
{
int len = strleng(s), spc, m = 0;

write(1, "\n\t\t\t***\t", strleng("\n\t\t\t***\t"));

spc = (60 - len) / 2;

while (m < spc)
{
write(1, " ", 2);
m++;
}

write(1, s, strleng(s));

while (m > 0)
{
write(1, " ", 2);
m--;
}

write(1, "\t***", strleng("\t***"));
}
