/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:16:51 by bschmid           #+#    #+#             */
/*   Updated: 2023/12/12 16:16:53 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*move_it(char **str)
{
	char	*line;
	char	*newline;
	char	*placeholder_str;

	if (!*str || !**str) //check for invalid pointer and empty string
		return (NULL);
	newline = ft_strchr(*str, '\n');//set newline to pointer to \n
	if (newline)//enter if newline is filled
	{
		line = ft_strndup(*str, newline - *str + 1);//create a line up to that point
		placeholder_str = *str;//needs to be copied to placeholder so it can take new value
		*str = ft_strdup(newline + 1);//new value to str
		free(placeholder_str); // frees the original str (frees memory originaly allocated)
	}
	else
	{//if no newline is found, duplicate the entire content into line
		line = ft_strdup(*str);//line is now new dynamically allocated
		free(*str);//so str can be freed
		*str = NULL;
	}
	return (line);
}
//it is importand to allways free the old version after duplicating a string

static char	*ft_read_join(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes; //this datatype is designed for this purpos so it is big enough
	char	*tmp;

	if (!str)
		str = NULL;
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
		{
			if (bytes == 0 && str && *str)
				return (str);
			free(str);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str); //
		str = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = ft_read_join(fd, str);
	line = move_it(&str);
	return (line);
}
