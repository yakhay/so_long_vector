/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:19:49 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/27 14:23:53 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_searsh(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_retur_line(char *ptr)
{
	int		i;
	char	*line;
	int		j;

	j = 0;
	i = 0;
	if (!ptr[0])
		return (NULL);
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (ptr[j] && ptr[j] != '\n')
	{
		line[j] = ptr[j];
		j++;
	}
	if (ptr[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_read(int fd, char *ptr)
{
	char	*buffer;
	int		j;

	j = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (j != 0 && ft_searsh(ptr) == 0)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j == -1)
		{
			free(buffer);
			if (!ptr)
				return (NULL);
			return (ptr);
		}
		buffer[j] = '\0';
		ptr = ft_strjoine(ptr, buffer);
	}
	free(buffer);
	return (ptr);
}

char	*ft_static(char *ptr)
{
	char	*re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	re = malloc ((ft_strlene(ptr) - i) * sizeof(char));
	if (!re)
		return (NULL);
	i++;
	while (ptr[i])
		re[j++] = ptr[i++];
	re[j] = '\0';
	free(ptr);
	return (re);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = ft_read(fd, ptr);
	if (!ptr)
		return (NULL);
	line = ft_retur_line(ptr);
	ptr = ft_static(ptr);
	return (line);
}
