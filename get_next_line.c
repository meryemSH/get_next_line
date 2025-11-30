/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:58:45 by mseghrou          #+#    #+#             */
/*   Updated: 2025/11/30 17:29:57 by mseghrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.h" // Assuming this contains includes and BUFFER_SIZE
#include "get_next_line.h"
// Assuming this contains helper declaration and BUFFER_SIZE
#include <stdlib.h>
#include <string.h> // for strchr
#include <string.h>
#include <unistd.h>

static char	*append_buffer(char *buf, size_t buf_len, char *tmp, ssize_t r)
{
	char	*new_buf;

	new_buf = malloc(buf_len + r + 1);
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	if (buf)
		memcpy(new_buf, buf, buf_len);
	memcpy(new_buf + buf_len, tmp, r);
	new_buf[buf_len + r] = '\0';
	free(buf);
	return (new_buf);
}

// ------------------ Helper: read_into_buffer ------------------
static char	*read_into_buffer(int fd, char **buf, size_t *buf_len)
{
	char	*tmp;
	ssize_t	r;

	tmp = malloc(BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	while (!*buf || !memchr(*buf, '\n', *buf_len))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
			break ;
		*buf = append_buffer(*buf, *buf_len, tmp, r);
		if (!*buf)
		{
			*buf_len = 0;
			free(tmp);
			return (NULL);
		}
		*buf_len += r;
	}
	free(tmp);
	return (*buf);
}

// ------------------ Helper: extract_line_part ------------------
static char	*extract_line_part(char *buf, size_t buf_len, size_t *line_len)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < buf_len && buf[i] != '\n')
		i++;
	if (i < buf_len && buf[i] == '\n')
		i++;
	*line_len = i;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	memcpy(line, buf, i);
	line[i] = '\0';
	return (line);
}

// ------------------ Helper: shift_buffer ------------------
static void	shift_buffer(char **buf, size_t *buf_len, size_t line_len)
{
	char	*new_buf;

	if (line_len < *buf_len)
	{
		*buf_len -= line_len;
		new_buf = malloc(*buf_len + 1);
		if (!new_buf)
		{
			free(*buf);
			*buf = NULL;
			*buf_len = 0;
			return ;
		}
		memcpy(new_buf, *buf + line_len, *buf_len);
		new_buf[*buf_len] = '\0';
		free(*buf);
		*buf = new_buf;
	}
	else
	{
		free(*buf);
		*buf = NULL;
		*buf_len = 0;
	}
}

// ------------------ Helper: extract_line_and_shift ------------------
static char	*extract_line_and_shift(char **buf, size_t *buf_len)
{
	size_t	line_len;
	char	*line;

	line = extract_line_part(*buf, *buf_len, &line_len);
	if (!line)
	{
		free(*buf);
		*buf = NULL;
		*buf_len = 0;
		return (NULL);
	}
	shift_buffer(buf, buf_len, line_len);
	return (line);
}

// ------------------ Main: get_next_line ------------------
char	*get_next_line(int fd)
{
	static char *buf = NULL;
	static size_t buf_len = 0;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!read_into_buffer(fd, &buf, &buf_len))
		return (NULL);
	if (!buf || buf_len == 0)
	{
		free(buf);
		buf = NULL;
		buf_len = 0;
		return (NULL);
	}
	line = extract_line_and_shift(&buf, &buf_len);
	return (line);
}