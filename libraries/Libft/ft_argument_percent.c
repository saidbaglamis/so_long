/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:04:14 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:04:14 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

int	ft_argument_percent(void)
{
	return (write(1, "%", sizeof(char) * 1));
}
