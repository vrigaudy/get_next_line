/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:22 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/21 18:14:08 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_get_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_search(buffer);
	if (j == 0)
	{
		buffer[0] = 0;
		return ;
	}
	while (buffer[j])
		buffer[i++] = buffer[j++];
	}
	buffer[i] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1]
	char		*line;
	char		*temp;
	int			end;

	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (0);
	if (buffer[0])
		line = ft_strjoin(line, buffer);
	while (ft_search(buffer) == 0)
	{
		end = ft_search(buffer);
		if (end == 0)
		{
			ft_get_buffer(buffer);
			return (line)
		}
	}
	return (line);
}
