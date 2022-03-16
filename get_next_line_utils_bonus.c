/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:46:39 by vrigaudy          #+#    #+#             */
/*   Updated: 2022/01/04 22:00:43 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return (s1);
	if (ft_strchr(s2) > 0)
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strchr(s2) + 1));
	else
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	while (s1 && s1[i])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j] && s2[j] != '\n')
		ret[i++] = s2[j++];
	if (s2[j] == '\n')
		ret[i++] = s2[j];
	ret[i] = 0;
	free(s1);
	return (ret);
}
