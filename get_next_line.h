/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseghrou <mseghrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:59:14 by mseghrou          #+#    #+#             */
/*   Updated: 2025/11/30 16:06:10 by mseghrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// حدد buffer size إذا ما محددتش
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

// الدالة الرئيسية
char	*get_next_line(int fd);

// الدوال المساعدة (private)  
// ممكن تخليهم static فـ .c file، هنا غير للتوضيح
// size_t	gnl_strlen(char *s);
// char	*gnl_substr(char *s, size_t n);
// char	*gnl_shift(char *s, size_t n);
// char	*gnl_join(char *buf, char *tmp, int r);

#endif
