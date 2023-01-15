/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:16:55 by yakhay            #+#    #+#             */
/*   Updated: 2022/10/25 12:44:04 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searsh(char const *s, char c, int j, int i)
{
	int	h;

	h = 1;
	while (s[j] && j <= i)
	{
		if (s[j] == c && s[j + 1] != c)
			h++;
		j++;
	}
	return (h);
}

static char	**ft_free(char **strs, int res)
{
	int	i;

	i = 0;
	while (i < res && strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

static char	**ft_sp(char const*s, char c, int i, int j)
{
	char	**s1;
	int		k;
	int		res;

	res = ft_searsh(s, c, j, i);
	s1 = (char **)malloc((res + 1) * sizeof(char *));
	if (!s1)
		return (NULL);
	k = 0;
	j = 0;
	while (k < res)
	{
		s += j;
		while (*s && *s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		s1[k] = ft_substr(s, 0, j);
		if (!s1[k])
			ft_free(s1, res);
		k++;
	}
	s1[k] = 0;
	return (s1);
}

static char	**ft_spl(void)
{
	char	**s1;

	s1 = (char **)malloc(sizeof(char *));
	s1[0] = NULL;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!s[0])
		return (ft_spl());
	while (s[j] && s[j] == c)
	{
		if (!s[j + 1])
			return (ft_spl());
		j++;
	}
	i--;
	while (s[i] && s[i] == c && i > 0)
		i--;
	return (ft_sp(s, c, i, j));
}
