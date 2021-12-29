/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:22 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/29 21:25:17 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buffer_update(char *buffer)
{
	
}

char	*ft_check_buffer(char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = NULL;
	char		*line;
	int			reader;

	reader = 1;
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (0);
	*line = 0;
	if (*buffer)
	
	while (reader > 0 && ft_strchr(line) == 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		buffer[reader] = 0;
		line = ft_strjoin(line, buffer);
	}
	if ((ft_strchr(line) > 0 || reader == 0) && ft_strlen(line) > 0)
	{
		ft_buffer_update(buffer);
		return (line);
	}
	free(buffer);
	free(line);
	return (0);
}
