#include "shell.h"

/**
 * get_log_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_log_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(LOG_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, LOG_FILE);
	return (buf);
}

/**
 * log_write - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int log_write(info_t *info)
{
	ssize_t std;
	char *filename = get_log_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	std = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (std == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		puts_std(node->str, std);
		put_std('\n', std);
	}
	put_std(BUFF_FLUSH, std);
	close(std);
	return (1);
}

/**
 * log_read - reads history from file
 * @info: the parameter struct
 *
 * Return: logs on success, 0 otherwise
 */
int log_read(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t std, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_log_file(info);

	if (!filename)
		return (0);

	std = open(filename, O_RDONLY);
	free(filename);
	if (std == -1)
		return (0);
	if (!fstat(std, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(std, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(std);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			log_add(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		log_add(info, buf + last, linecount++);
	free(buf);
	info->logs = linecount;
	while (info->logs-- >= LOG_SIZE)
		delete_node_at_index(&(info->history), 0);
	log_renumber(info);
	return (info->logs);
}

/**
 * log_add - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, logs
 *
 * Return: Always 0
 */
int log_add(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * log_renumber - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new logs
 */
int log_renumber(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->logs = i);
}
