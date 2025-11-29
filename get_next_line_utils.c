/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:59:04 by mseghrou          #+#    #+#             */
/*   Updated: 2025/11/29 17:47:23 by mseghrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjon(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_str)
		return (NULL);
	while (str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		new_str[i + j] = str2[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	char *ss;

	char cc;
	i = 0;
	while (ss[i])
	{
		if (ss[i] == cc)
			return (&ss[i]);
		i++;
	}
	if (cc == '\0')
		return (&ss[i]);
	return (NULL);
}