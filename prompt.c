#include "shell.h"

/**
 * hsh - the main shell
 * @info: parameter
 * @av: the argument vector
 *
 *Return: 0 on success, 1 on error, or error codethe value
 */
int hsh(info_t *info, char **av)
{
	ssize_t n = 0;
	int br = 0;

	while (n != -1 && br != -2)
	{
		clear_info(info);
		if (interactive_mode(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			br = findb(info);
			if (br == -1)
				fcmd(info);
		}
		else if (interactive_mode(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive_mode(info) && info->status)
		exit(info->status);
	if (br == -2)
	{
		if (info->error_number == -1)
			exit(info->status);
		exit(info->error_number);
	}
	return (br);
}

/**
 * findb -  a builtin command
 * @info: the paramete
 *
 * Return: value
 */
int findb(info_t *info)
{
	int n, br = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (n = 0; builtintbl[i].type; n++)
		if (_strcmp(info->argvs[0], builtintbl[i].type) == 0)
		{
			info->line_counter++;
			br = builtintbl[i].func(info);
			break;
		}
	return (br);
}

/**
 * fcmd - finds a command in PATH
 * @info: the parameter
 *
 * Return: void
 */
void fcmd(info_t *info)
{
	char *paths = NULL;
	int j, q;

	info->paths = info->argvs[0];
	if (info->linecount_flag == 1)
	{
		info->line_counter++;
		info->linecount_flag = 0;
	}
	for (j = 0, q = 0; info->args[j]; j++)
		if (!is_delim(info->args[j], " \t\n"))
			q++;
	if (!q)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argvs[0]);
	if (paths)
	{
		info->paths = paths;
		fork_cmd(info);
	}
	else
	{
		if ((interactive_mode(info) || _getenv(info, "PATH=")
			|| info->argvs[0][0] == '/') && is_cmd(info, info->argvs[0]))
			fork_cmd(info);
		else if (*(info->args) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * ficmd - forks a an exec thread to run cmd
 * @info: the parameter
 *
 * Return: void
 */
void ficmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
