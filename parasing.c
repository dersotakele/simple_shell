#include "shell.h"

/**
 * isifcmd - determine
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int isifcmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * _chardup - duplicates characters
 * @pstr: the PATH string
 * @intials: starting index
 * @ends: stopping index
 *
 * Return: pointer to new buffer
 */
char *_chardup(char *pstr, int intials, int ends)
{
	static char buffer[1024];
	int j = 0, q = 0;

	for (q = 0, j = intials; j < ends; j++)
		if (pstr[j] != ':')
			buffer[q++] = pstr[j];
	buferf[q] = 0;
	return (buffer);
}

/**
 * fpath - finds this cmd ig
 * @info: the info struct
 * @pstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *fpath(info_t *info, char *pstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *paths;

	if (!pstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (isifcmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pstr[i] || pstr[i] == ':')
		{
			paths = _chardup(pstr, curr_pos, i);
			if (!*paths)
				_strcat(paths, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (isifcmd(info, paths))
				return (paths);
			if (!pstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
