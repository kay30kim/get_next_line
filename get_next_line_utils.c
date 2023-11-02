/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:38:14 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/02 14:34:35 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	l;

	if (!s || !*s)
		return (NULL);
	l = ft_strlen(s);
	r = (char *)malloc((l + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r[l] = '\0';
	while (l--)
		r[l] = s[l];
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*r;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!r)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	r[len1 + len2] = '\0';
	while (len2--)
		r[len1 + len2] = s2[len2];
	while (len1--)
		r[len1] = s1[len1];
	if (s1)
		free(s1);
	return (r);
}
