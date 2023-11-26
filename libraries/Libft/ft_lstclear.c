/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:09:48 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 00:09:48 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr_i;
	t_list	*next;

	if (!*lst)
		return ;
	ptr_i = *lst;
	while (ptr_i)
	{
		next = ptr_i->next;
		(*del)(ptr_i->content);
		free(ptr_i);
		ptr_i = next;
	}
	*lst = NULL;
}
