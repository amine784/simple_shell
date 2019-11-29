#include "holberton.h"
/**
* recu-function that get envirement and path.
*@path: const char name "path".
*Return: Always success.
**/
char *recu(const char *path)
{
int i = 0;
int rest;
char *token;
char *envt;
char *delim = "=";
char *ret;
while (environ[i])
{
envt = __strdup(environ[i]);
token = strtok(envt, delim);
rest = __strcmp(token, path);
if (rest == 0)
{
ret = strtok(NULL, delim);
return (ret);
}
i++;
}
return (NULL);
}
/**
*__strcat-function that concatiin 2 string.
*@s1:char type.
*@s2:char type.
*Return: Always success
**/
char *__strcat(char *s1, char *s2)
{
int x, y;
int total = 0;
int i;
char *chaine;
for (x = 0; s1[x] != '\0'; x++)
{};
for (y = 0; s2[y] != '\0'; y++)
{};
total = x + y + 1;
chaine = malloc(sizeof(char) * (total));
for (i = 0; i < total - 1; i++)
{
if (i < x)
{
chaine[i] = s1[i];
}
else
{
chaine[i] = s2[i - x];
}
}
chaine[total - 1] = '\0';
return (chaine);
}
/**
*_strlen-function that count length of a string.
*@chaine:char type
*Return: Always succes.
**/
int _strlen(char *chaine)
{
int count;
char delim = '\0';
for (count = 0; chaine[count] != delim ; count++)
{};
return (count);
}
/**
*__strdup-function return a pointer to the first word in the string.
*@st:char type input.
*Return:Always success
**/
char *__strdup(char *st)
{
int h = 0, l;
char *chaine;
char delim = '\0';
l = _strlen(st);
chaine = malloc(sizeof(char) * (l + 1));
while (st[h] != delim)
{
chaine[h] = st[h];
h++;
}
chaine[h] = delim;
return (chaine);
}
/**
*__strcmp-function to compare 2 string
*@s1:string 1 char type.
*@s2:string 2 char type.
*Return: Always 0.
**/
int __strcmp(char *s1, const char  *s2)
{
int l;
int len = 0;
int a = 0;
for (l = 0 ; s1[l] != '\0' ; l++)
{};
while (len < l && a == 0)
{
a = s1[len] - s2[len];
len++;
}
return (a);
}
