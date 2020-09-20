/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:21:32 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/21 15:36:28 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*gon;
	t_list	*aux;
	t_list	*auxgon;

	aux = lst;
	if (!(gon = malloc(sizeof(t_list))))
		return (0);
	auxgon = gon;
	while (aux)
	{
		auxgon->content = f(aux->content);
		if (!(auxgon->next = malloc(sizeof(t_list))))
			ft_lstclear(&auxgon, del);
		aux = aux->next;
		auxgon = auxgon->next;
	}
	return (gon);
}
