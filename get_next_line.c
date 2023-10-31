/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:06:42 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/31 18:24:30 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_next(char **tmp)
{
	char	*line;
	char	*ptr;

	ptr = *tmp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*tmp, 0, (size_t)(ptr - *tmp));
	if (!line)
	{
		free (*tmp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*tmp);
	*tmp = ptr;
	return (line);
}

// when read finish to read then return 0
// static means that only can use in this source file
static char *ft_read(char *tmp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr (tmp, '\n'))
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf)
			return (NULL);
		}
		buf[r] = 0;
		tmp = ft_strjoin_free(tmp, buf);
		if (!tmp)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[BUFFER_SIZE];
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	if (!tmp[fd])
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(tmp[fd]);
		return(NULL);
	}
	tmp[fd] = ft_read (tmp[fd], fd, buf);
	if (!tmp[fd])
		return (NULL);
	return (ft_next(&tmp[fd]));
}

#include "get_next_line.h"

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE];
    static char line[LINE_SIZE];
    static int index = 0;
    static int line_length = 0;
    int bytes_read;

    while (1) {
        if (index >= line_length) {
            // The current line has been processed, read a new line
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0) {
                // No more to read or an error occurred
                if (line_length == 0) {
                    return NULL; // Nothing to read or error
                }
                line[line_length] = '\0';
                return line; // Return the last line
            }
            index = 0;
            line_length = 0;
        }

        while (index < bytes_read) {
            if (buffer[index] == '\n') {
                // End of line found
                line[line_length] = '\0';
                index++; // Move past '\n'
                return line; // Return the line (including '\n')
            } else {
                line[line_length] = buffer[index];
                index++;
                line_length++;
            }
        }
    }
}
