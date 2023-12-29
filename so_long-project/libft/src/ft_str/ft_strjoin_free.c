/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:00:48 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 15:00:50 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	x;
	size_t	y;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	x = ft_strlen(s1);
	y = ft_strlen(s2) + 1;
	str = (char *)malloc(x + y);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, x + 1);
	ft_strlcpy(str + x, s2, y);
	free(s1);
	return (str);
}
/*
Verilen iki parametrenin toplam uzunluğunu tutacak bir yeni array oluşturur.
Sırasıyla iki parametreyi bu arraye atar ve oluşturduğu arrayı döndürür.
*/