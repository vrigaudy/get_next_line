/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:02 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/21 19:42:17 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_search(char *str)
{
	int	i;

	i = 0;
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
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_search(s2) == 0)
		dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	else
		dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_search(s2) + 1));
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		dst[i++] = s2[j++];
	if (s2[j] == '\n')
		dst[i++] = '\n';
	dst[i] = 0;
	return (dst);
}
