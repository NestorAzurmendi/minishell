/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:17:42 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/21 11:17:18 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int			i;
	t_list		*gon;

	i = 0;
	gon = lst;
	while (gon != NULL)
	{
		i++;
		gon = gon->next;
	}
	return (i);
}
