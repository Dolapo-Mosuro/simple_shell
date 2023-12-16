#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;
extern int errno;

/**
 * struct selectfunction - a struct array of functions
 * @command: a pointer to the caharacter of the command string
 * @funcptr: a pointer to a function
 */

typedef struct selectfunction
{
char *command;
int (*funcptr)(char **line);
} selecte;



/* Function Prototypes */
void sigint_(int sig_num __attribute__((unused)))
int getstr(char *str);
char **strbrk(char *line, char c);
int _getline(char **line, size_t *len);
void farewell(void);
void description(void);
void printstar(void);
void printstr(char *s);
int strleng(char *s);
void strcopy(char *src, char *dest);
int strcomp(char *str, char *equ);
void strmix(char *src, char *dest);
int (*getfunc(char *str))(char **line);
int echorr(char *line[]);
int pwder(char *line[]);
int envir(char *line[]);
int maker(char *line[]);
char *stringer(char *line, int i, char *str, char c);
char _getinput(void);
void prompt_dis(int i);
int _getline(char **line, size_t *size_char);
int echo_text(char *line[]);
int shell_pro(char **line, char **argv)
int exit_(char *line[]);
int list(char *line[]);
int set_exe(char *line[]);
int unlisted(char **line);
int pwder(char *line[]);
int echorr(char *line[]);
int exit_(char *line[]);
int changedir(char **line);
int getstr(char *str)



#endif /* MAIN_H */
