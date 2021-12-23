/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <vrigaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:33 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/24 00:37:09 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_save_update(char *save);
char	*ft_return_line(char **save);
char	*ft_strjoin(char *s1, char *s2);

int		ft_strlen(char *str);
int		ft_strchr(char *str);

void	*ft_memmove(void *dst, const void *src, size_t len)

#endif
