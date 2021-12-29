/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:02 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/29 19:27:08 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s2)
		return (0);
	if (ft_strchr(buffer) > 0)
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strchr(s2) + 1));
	else
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (*s2 && *s2 != '\n')
		ret[i++] = *(s2++);
	if (*s2 == '\n')
		ret[i++] = *s2;
	ret[i] = 0;
	free(s1);
	return (ret);
}
