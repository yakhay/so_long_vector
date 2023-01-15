/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:32:35 by yakhay            #+#    #+#             */
/*   Updated: 2022/10/23 17:27:16 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count > 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}
/*
#include <stdio.h>
int main()
{
	int *d;
	int *c;
	size_t count = 3;
	size_t size = sizeof(int);
	d = ft_calloc(size, count);
	c = calloc(size,count);
	printf("%d",d[8]);
}*/
