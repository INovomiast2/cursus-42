/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:11:30 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/03/28 12:58:31 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *buffer, char *bff)
{
	char	*temp;

	temp = ft_strjoin(buffer, bff);
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (temp);
}

char	*ft_read_fd(int fd, char *res)
{
	char	*buff;
	int		r_byte;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!buff)
		return (NULL);
	r_byte = 1;
	while (r_byte > 0)
	{
		r_byte = read(fd, buff, BUFFER_SIZE);
		if (r_byte == -1)
		{
			free(buff);
			return (buff = NULL, NULL);
		}
		buff[r_byte] = '\0';
		res = ft_free(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (free(buff), res);
}

char	*ft_next_line(char *buff)
{
	int		y;
	int		x;
	char	*line;

	y = 0;
	while (buff[y] && buff[y] != '\n')
		y++;
	if (!buff[y])
	{
		free(buff);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buff) - y + 2), sizeof(char));
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	y++;
	x = 0;
	while (buff[y])
		line[x++] = buff[y++];
	line[x] = '\0';
	free(buff);
	return (line);
}

char	*ft_current_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read_fd(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_current_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
