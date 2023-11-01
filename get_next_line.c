/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:38:12 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/01 17:39:56 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

static char	*ft_read(char *temp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr (temp, '\n'))
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free_s1 (temp, buf);
		if (!temp)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (NULL);
	buf = malloc (sizeof (*buf) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read (temp[fd], fd, buf);
	if (!temp[fd])
		return (NULL);
	if (!*temp[fd])
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));
}

#include "get_next_line.h"

/*

static char	*read_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	int		bytes_read;
	int		i;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buf[bytes_read] = '\0';
	line = malloc(BUFFER_SIZE);
	if (!line)
		return (NULL);
	i = 0;
	while (i < bytes_read && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*tmp;
	int			offset;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
    offset = 0;
	while (!line)
    {
        if (!remainder)
            tmp = ft_strdup("");
        else
            tmp = ft_strdup(remainder);
        
        free(remainder);
        remainder = NULL;
        
        tmp = ft_strjoin(tmp, read_line(fd));
        
        if (!tmp || !tmp[0])
        {
            free(tmp);
            return (NULL);
        }
        
        while (tmp[offset] && tmp[offset] != '\n')
            offset++;
        
        if (tmp[offset] == '\n')
        {
            tmp[offset] = '\0';
            remainder = ft_strdup(tmp + offset + 1);
        }
        
        if (line)
            free(line);
        line = tmp;
        
        if (tmp[offset] == '\n')
            break;
    }
	return (line);
}

*/

