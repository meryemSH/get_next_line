/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:59:04 by mseghrou          #+#    #+#             */
/*   Updated: 2025/11/30 16:24:34 by mseghrou         ###   ########.fr       */
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

// char	*ft_strjoin(char *str1, char *str2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new_str;
// 	size_t	len1;
// 	size_t	len2;

// 	len1 = ft_strlen(str1);
// 	len2 = ft_strlen(str2);
// 	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
// 	if (!new_str)
// 	{
// 		// if allocation fails, we should not free str1 here because caller still owns it.
// 		return (NULL);
// 	}
// 	i = 0;
// 	if (str1)
// 	{
// 		while (i < len1)
// 		{
// 			new_str[i] = str1[i];
// 			i++;
// 		}
// 	}
// 	j = 0;
// 	while (j < len2)
// 	{
// 		new_str[i + j] = str2[j];
// 		j++;
// 	}
// 	new_str[i + j] = '\0';
// 	free(str1);
// 	return (new_str);
// }


char	*ft_strchr(const char *s, int c)
{
	size_t i;
	char *ss;
	char cc;
	
	i = 0;
	ss = (char *)s;
    cc = (char)c; 
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