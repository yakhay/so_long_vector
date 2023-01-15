/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:02:26 by yakhay            #+#    #+#             */
/*   Updated: 2023/01/11 14:50:26 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include<unistd.h>
# include <stdio.h>
#include <mlx.h>
# include "libft/libft.h"

int ft_check_map(char **sp);
char	*get_next_line(int fd);
char	*ft_strjoine(char *s1, char *s2);
size_t	ft_strlene(const char *s);
char	*ft_strdupe(const char *src);

#endif
