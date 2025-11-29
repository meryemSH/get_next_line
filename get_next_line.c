/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:58:45 by mseghrou          #+#    #+#             */
/*   Updated: 2025/11/29 17:53:56 by mseghrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*box;
	char		*buffer;
	char		*line;
	// char		*tmp;
	int			bytes;

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
	// tmp = box;
	box = ft_strjoin(box, buffer);
	// free(tmp);
	line = extract_line(box);
	box = update_box(box);
	free(buffer);
	return (line);
}
