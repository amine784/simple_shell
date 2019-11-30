#include "holberton.h"
/**
*main-main function from simple shelll.
*@av:unused attribute
*@argc:int type
*Return: Always success
**/
int main(int __attribute__((unused)) argc, char __attribute__((unused)) **av)
{
char *buffer = NULL;
size_t bufsize = 1024;
char **command;
ssize_t chart;
int x = 1;
signal(SIGINT, sigintHandler);
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
else
x = 0;
do {
chart = getline(&buffer, &bufsize, stdin);
check(buffer, chart);
command = parse_line(buffer);
create_child(command);
if (x != 0)
write(STDOUT_FILENO, "$ ", 2);
} while (1);
if (x != 0)
write(STDOUT_FILENO, "\n", 1);
return (0);
}
