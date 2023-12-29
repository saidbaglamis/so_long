/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:00:55 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 15:00:57 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = "";
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1 && s2 && res && s1[++i] != '\0')
		res[i] = s1[i];
	while (s1 && s2 && res && (++j == 0 || s2[j - 1] != '\0'))
		res[i++] = s2[j];
	return (res);
}
/*
Verilen iki parametrenin toplam uzunluğunu tutacak bir yeni array oluşturur.
Sırasıyla iki parametreyi bu arraye atar ve oluşturduğu arrayı döndürür.
*/