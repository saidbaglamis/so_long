/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:13:46 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:13:46 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int argument)
{
	if (argument >= 'a' && argument <= 'z')
		argument -= 32;
	return (argument);
}
