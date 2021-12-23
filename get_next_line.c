/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:22 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/23 17:29:04 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_update(char *save)
{
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(save) - ft_strchr(save) + 1));
	if (!temp)
		return (0);
	ft_strcpy(&save[ft_strchr(save)], temp);
	free(save);
	save = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	if (!save)
		return (0);
	ft_strcpy(temp, save);
	free(temp);
	return (save);
}

char	*ft_return_line(char **save)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strchr(*save) + 1));
	if (!ret)
		return (0);
	while (i < ft_strchr(*save))
	{
		ret[i] = save[0][i];
		i++;
	}
	ret[i] = 0;
	*save = ft_save_update(*save);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			r;

	r = 1;
	while (r > 0 && ft_strchr(save) < 1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = 0;
		save = ft_strjoin(save, buffer);
	}
	if (ft_strchr(save) > 0)
	{
		return (ft_return_line(&save));
	}
	return (0);
}
