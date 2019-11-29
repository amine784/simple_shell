#include "holberton.h"
/**
* parse_line-function that devide command line for stdin.
*@buffer: char type from stdin.
*Return:Always sucess.
**/
char **parse_line(char *buffer)
{
struct stat statbuffer;
char *path, *env, *new_command, *tokens;
char **t, **directory = NULL;
char *token = NULL;
size_t x = 32;
int i = 0, k = 0, j = 0, lenp = 0;
t = malloc(x * sizeof(char));
token = strtok(buffer, "\n");
token = strtok(token, " ");
t[0] = token;
i = 1;
while (token)
{
token = strtok(NULL, " ");
t[i] = token;
i++;
}
if (t[0] == NULL)
return (t);
path = recu("PATH");
env = __strdup(path);
lenp = _strlen(env);
directory = malloc(sizeof(char) * (lenp + 2));
tokens = strtok(env, ":");
while (tokens != NULL)
{
directory[k] = tokens;
k++;
tokens = strtok(NULL, ":");
}
directory[k + 1] = NULL;
while (directory [j] != NULL)
{
new_command = __strcat(__strcat(directory[j], "/"), t[0]);
if (stat(new_command, &statbuffer) == 0)
t[0] = new_command;
j++;
}
return (t);
}
