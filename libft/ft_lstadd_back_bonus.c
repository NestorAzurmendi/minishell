/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:07:55 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/21 11:15:24 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*gon;

	if (*alst)
	{
		gon = ft_lstlast(*alst);
		gon->next = new;
		new->next = NULL;
	}
	else
	{
		*alst = new;
		new->next = 0;
	}
}
