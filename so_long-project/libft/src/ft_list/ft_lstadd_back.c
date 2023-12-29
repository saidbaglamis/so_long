/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:10 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 14:58:11 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_lst;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		aux_lst = ft_lstlast(*lst);
		aux_lst->next = new;
	}
}
