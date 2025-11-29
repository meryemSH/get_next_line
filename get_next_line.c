/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:58:45 by mseghrou          #+#    #+#             */
/*   Updated: 2025/11/29 18:11:15 by mseghrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *box)
{
	int		i;
	char	*line;

	i = 0;
	if (!box)
		return (NULL);
	while (box[i] && box[i] != '\n')
		i++;
	line = malloc(i + 2); // +1 for '\n' +1 for '\0'
	if (!line)
		return (NULL);
	i = 0;
	while (box[i] && box[i] != '\n')
	{
		line[i] = box[i];
		i++;
	}
	if (box[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_box(char *box)
{
	int		i;
	int		j;
	char	*new_box;

	i = 0, j = 0;
	if (!box)
		return (NULL);
	while (box[i] && box[i] != '\n')
		i++;
	if (!box[i])
	{
		free(box);
		return (NULL);
	}
	new_box = malloc(ft_strlen(box) - i + 1);
	if (!new_box)
		return (NULL);
	i++; // skip '\n'
	while (box[i])
		new_box[j++] = box[i++];
	new_box[j] = '\0';
	free(box);
	return (new_box);
}

char	*get_next_line(int fd)
{
	static char *box;
	char *buffer;
	char *line;
	int bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	box = ft_strjoin(box, buffer);
	line = extract_line(box);
	box = update_box(box);
	free(buffer);
	return (line);
}