/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_our_implement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:47:06 by nazurmen          #+#    #+#             */
/*   Updated: 2020/09/25 18:55:10 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_our_implement(t_tab *t)
{
	if(ft_strncmp(t->tokens[0], "pwd", 3) == 0)
		return(ft_pwd());
	if(ft_strncmp(t->tokens[0], "cd", 2) == 0)
		return(ft_cd(&t->tokens[1]));
	if(ft_strncmp(t->tokens[0], "echo", 4) == 0)
		return(ft_echo(&t->tokens[1]));
	else
		return (1);
}
