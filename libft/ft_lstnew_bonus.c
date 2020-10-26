/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:46:00 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/21 17:35:52 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content)
{
	t_list	*gon;

	if (!(gon = (t_list *)malloc(sizeof(t_list))))
		return (0);
	gon->content = (void*)content;
	gon->next = NULL;
	return (gon);
}
