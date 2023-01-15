/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:20:06 by yakhay            #+#    #+#             */
/*   Updated: 2023/01/09 13:59:49 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlene(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoine(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[i] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlene(s2) + ft_strlene(s1) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdupe(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i])
		i++;
	dest = malloc(i * sizeof(char) + 1);
	if (dest)
	{
		i = 0;
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
