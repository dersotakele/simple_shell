#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* This prototype used for read,write the buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* This Declararion is used for the command chaining */
#define CMD_NORM	0
#define CMD_OR 		1
#define CMD_AND 	2
#define CMD_CHAIN	3

/* this commands usde for converting numberes */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSINED		2

/* is the condition using "1" if the the system using getline */
#define USE_GETLINE 0
#define USE_STRTOK 0

extern char **enviorn;


typedef struct liststring
{
	int number;
	char *strings;
	struct liststring *next;
}lists_t;
typedef struct passinform
{
	char *args;
	char **argvs;
	char *paths;
	int argcs;
	unsigned int line_counter;
	int error_number;
	int linecounter_flags;
	char *firstname;
	lists_t *envi;
	lists_t *histories;
	lists_t *alias;
	char *enviorn;
	char enviorn_changend;
	int status;

	char *cmd_buffer;
	int readfd;
	int hist_counter;
}info_t;
#define INFO_INI \
{NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL, NULL,NULL, 0, 0, NULL, \
	0, 0,0}


typedef struct builtin
{
	char *type;
	int (*func)(info_t);
}
bulitin_table;
/*stringtoint*/
int interactive_mode(info_t *);
int check_alpha(int);
int _delimeter(char, char *);
int string_toint(char *);
/*strinhtokenizer1*/
char **strword(char *, char *);
char **stword1(char *, char);
/* error handling*/
void pinpustr(char *);
int writechar(char);
int writechare(char ch, int n)
int pinpn(char *strings, int n)
int handlestrtoint(char *);
void errorm(info_t *, char *);
int deciprint(int, int);
char con_num(long int, int, int);
char replace_comm(char *);
#endif

