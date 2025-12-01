/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:58:45 by mseghrou          #+#    #+#             */
/*   Updated: 2025/12/01 16:57:36 by mseghrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append_buffer(char *buf, size_t *buf_len, char *tmp, ssize_t r)
{
	char	*new_buf;

	new_buf = malloc(*buf_len + r + 1);
	if (!new_buf)
	{
		free(buf);
		*buf_len = 0;
		return (NULL);
	}
	if (buf)
		ft_memcpy(new_buf, buf, *buf_len);
	ft_memcpy(new_buf + *buf_len, tmp, r);
	new_buf[*buf_len + r] = '\0';
	*buf_len += r;
	free(buf);
	return (new_buf);
}

static char	*read_until_newline(int fd, char *buf, size_t *buf_len)
{
	char	*tmp;
	ssize_t	r;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!buf || !ft_memchr(buf, '\n', *buf_len))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buf = append_buffer(buf, buf_len, tmp, r);
		if (!buf)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	if (!buf || *buf_len == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
static char	*extract_line(char *buf, size_t *buf_len)
{
	size_t	line_len;
	char	*newline;
	char	*line;

	line_len = 0;
	newline = ft_memchr(buf, '\n', *buf_len);
	if (newline)
		line_len = newline - buf + 1;
	else
		line_len = *buf_len;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buf, line_len);
	line[line_len] = '\0';
	*buf_len -= line_len;
	if (*buf_len > 0)
		ft_memmove(buf, buf + line_len, *buf_len);
	else
		buf[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buf = {NULL};
	static size_t	buf_len = {0};
	char			*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_until_newline(fd, buf, &buf_len);
	if (!buf)
		return (NULL);  
	line = extract_line(buf, &buf_len);
	if (buf_len == 0 && buf)
	{
		free(buf);
		buf = NULL;
	}
	return (line);
}



#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("oo.txt",O_RDWR | O_CREAT , 0777);
	write(fd, "hellow\n world\n",14);
	//////lseek(fd, 0, SEEK_SET);
    if (fd < 0)
    {
        printf("Error: can't open file\n");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
