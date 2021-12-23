/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:02 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/24 00:37:01 by vrigaudy         ###   ########.fr       */
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
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d > s)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	while (len--)
		*(d++) = *(s++);
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	if (s1 && s2)
		return (0);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	ft_memmove(ret, s1, ft_strlen(s1));
	ft_memmove(ret + ft_strlen(s1), s2, ft_strlen(s2));
	free(s1);
	return (ret);
}

