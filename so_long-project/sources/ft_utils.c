/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:05:14 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/26 02:05:14 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

int	special_len(t_game *game, int j)
{
	int	i;

	i = 0;
	while ((game->map.full[j][i] == '1' || game->map.full[j][i] == '0'
	|| game->map.full[j][i] == 'P' || game->map.full[j][i] == 'C'
	|| game->map.full[j][i] == 'E') && game->map.full[j][i])
	{
		i++;
	}
	return (i);
}
