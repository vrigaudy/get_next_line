/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:22 by vrigaudy          #+#    #+#             */
/*   Updated: 2022/01/07 11:41:28 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buffer_update(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strchr(buffer);
	if (j > 0)
	{
		while (buffer[j])
			buffer[i++] = buffer[j++];
	}
	buffer[i] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			reader;

	reader = 1;
	line = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(line, buffer);
	while (reader > 0 && ft_strchr(line) == 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			return (free(line), NULL);
		buffer[reader] = 0;
		line = ft_strjoin(line, buffer);
	}
	ft_buffer_update(buffer);
	return (line);
}
