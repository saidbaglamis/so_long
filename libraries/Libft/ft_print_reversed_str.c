/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reversed_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:11:23 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:11:23 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_reversed_str(char *str)
{
	int	i;
	int	bytes;

	bytes = ft_strlen(str);
	i = bytes - 1;
	while (i >= 0)
		write(1, &str[i--], sizeof(char) * 1);
	return (bytes);
}
