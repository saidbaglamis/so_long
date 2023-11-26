/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:13:39 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:13:39 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int argument)
{
	if (argument >= 'A' && argument <= 'Z')
		argument += 32;
	return (argument);
}
