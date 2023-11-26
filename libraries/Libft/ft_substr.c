/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:13:30 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:13:30 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_length;
	char	*substr;

	if (!s)
		return (NULL);
	substr_length = ft_strlen(s) - start;
	if (ft_strlen(s) > start)
	{
		if (substr_length > len)
			substr = (char *) ft_calloc(len + 1, sizeof(char));
		else
			substr = (char *) ft_calloc(substr_length + 1, sizeof(char));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
	}
	else
		substr = (char *) ft_calloc(1, sizeof(char));
	return (substr);
}
