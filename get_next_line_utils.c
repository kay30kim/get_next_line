/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:06:39 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/31 18:08:46 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *tmp, char *buf)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = -1;
	len = ft_strlen(tmp) + ft_strlen(buf);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	len = ft_strlen(tmp);
	while (++i < len)
		res[i] = tmp[i];
	len = ft_strlen(buf);
	j = 0;
	while (j < len)
		res[i++] = buf[j++];
	res[i] = '\0';
	free(tmp);
	return (res);
}