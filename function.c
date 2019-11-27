#include "holberton.h"
/**
** create_child-function that fork a program to execute in child
*@t:char type:array that contain a list from command to execute
*no more
*Return: Always success
**/
int create_child(char **t)
{
pid_t pid;
pid = fork();
if (pid == 0)
{
  if ((-1) == execve(t[0], t, NULL))
{
if (t[0] == NULL || __strcmp(t[0], "$PATH") == 0)
{
exit(0);
}
else
{
perror(":not Found");
exit(0);
}
}
}
if (pid > 0)
{
wait(0);
}
return (1);
}
/**
* put_env-function to search envirement.
*
*Return: Always success.
**/
void put_env(void)
{
unsigned int  x, y;
for (x = 0; environ[x] != NULL; x++)
{
for (y = 0; environ[x][y] != '\0'; y++)
write(STDOUT_FILENO, &environ[x][y], 1);
write(STDOUT_FILENO, "\n", 1);
}
}
/**
* check-function to handle ctrl d and env etc..
*@buffer: from getline
*@chart :status  from getline.
*Return:Always succes.
**/
void check(char *buffer, ssize_t chart)
{
if (__strcmp(buffer, "exit\n") == 0)
exit(0);
if (__strcmp(buffer, "$PATH\n") == 0)
{
char *res;
res = gtenv("PATH");
write(STDOUT_FILENO, res, _strlen(res));
write(STDOUT_FILENO, "\n", 1);
}
if (__strcmp(buffer, "env\n") == 0)
{
put_env();
}
if (chart == -1)
{
exit(0);
}
}
/**
* sigintHandler-functino to handle ctrl+c
*@sign :signal de handle
*Return :Always success
**/
void sigintHandler(int __attribute__((unused))  sign)
{
signal(SIGINT, sigintHandler);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "$ ", 2);
}
