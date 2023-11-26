/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:10:45 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:10:45 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int argument, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *) str;
	while (i < size)
	{
		if (*(s + i) == (unsigned char) argument)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
