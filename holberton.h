#ifndef __SHELL__
#define __SHELL__
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>


extern char **environ;

char **parse_line(char *buffer);
int create_child(char **t);
void check(char *buffer, ssize_t chart);
void pt_gv(void);
char *recu(const char *);
char *__strcat(char *str1, char *str2);
int _strlen(char *chaine);
char *__strdup(char *st);
void sigintHandler(int sigintHandler);
int __strcmp(char *s1, const char *s2);




#endif
