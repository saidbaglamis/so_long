/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:28 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 15:01:29 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cnt;
	unsigned int	diff;

	cnt = 0;
	diff = 0;
	while ((cnt < n) && !diff && (s1[cnt] != 0) && (s2[cnt] != 0))
	{
		diff = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
		cnt++;
	}
	if (cnt < n && !diff && (s1[cnt] == 0 || s2[cnt] == 0))
		diff = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
	return (diff);
}
/*
Verilen iki dizeyi belirtilen n uzunluğuna kadar karşılaştırır.
Sonunda dizeler eşitse sıfır bir fark olursa ilk
 farklı indexteki karakterlerin farkını döndürür.
*/