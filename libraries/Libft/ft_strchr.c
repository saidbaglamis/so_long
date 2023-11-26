/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:07 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:12:07 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int argument)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char)argument)
			return ((char *) &str[i]);
		i++;
	}
	if (argument == '\0')
		return ((char *) &str[i]);
	return ((void *) 0);
}
