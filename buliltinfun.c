#include "shell.h"

/**
 * exitsh -the function that used to for exits the shell
 * @info: structure tha contain potential argument
 *
 * Return: exit satus
 */
int exitsh(info_t *info)
{
	int exitshcheck;

	if (ifo->argvs[1])
	{
		exitshcheck = handlestrtoint(info->argvs[1]);
		if (exitshcheck == -1)
		{
			info->status = 2;
			errorm(info, "no allowed number: ");
			pinpustr(info->argvs[1]);
			writechar('\n');
			return (1);
		}
		info->error_number = handlestrtoint(info->argvs[1]);
		return (-2);
	}
		info->error_number = -1;
		return (-2);
}

/**
 * cdd - chnage the curent directrory of the processor
 * @info: containg poetntial artgument
 *
 * Return: 0
 */
int cdd(info_t *info)
{
	char *ss, *ddir, buffer[1024];
	int cdir_r;

	ss == getcwd(buffer, 1024);
	if (!ss)
		_puts("todo:getcd failure<<\n");
	if (!info->argvs[1])
	{
		ddir = envgetv(info, "Derso");
		if (!ddir)
			cdir_r = chdir((ddir = envgetv(info, "PWD")) ? ddir : "/");
		else
			cdir_r = chdir(ddir);
	}
	else if (coms(info->argvs[1], "-") == 0)
	{
		if (!envgetv(info, "OLDPWD="))
		{
			_puts(ss);
			_putchar('\n');
			return (1);
		}
		_puts(envgetv(info, "OLDPWD=")), _putchar('\n');
		cdir_r = chdir((ddir = envgetv(info, "OLDPWD=")) ? ddir : '/');
	}
	else
	{
		cdir_r = chdir(info->argvs[1]);
	}
	if (cdir_r == -1)
	{
		errorm(info, "cant cd ");
		pinpustr(info->argvs[1]), writechar('\n');
	}
	else
	{
		envi(info, "OLDPWD", envgetv(info, "PWD="));
		envi(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * cdhelp -  a function used for Current dir pg the process
 * @info: potential argument
 *
 * Return: 0
 */
int cdhelp(info_t *info)
{
	char **ara;

	ara = info->argvs;
	_puts("not yet implemented \n");
	if (0)
		_puts(*ara);
	return (0);
}
