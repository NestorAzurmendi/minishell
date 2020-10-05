/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:32:51 by nazurmen          #+#    #+#             */
/*   Updated: 2020/10/05 21:22:07 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (args[i])
	{
		if (ft_strncmp("-n", args[i], 2) == 0)
		{
			i++;
			flag++;
		}
		ft_putstr_fd(args[i], 1);
		if(args[++i])
			ft_putchar_fd(' ', 1);
	}
	if (flag)
		ft_putchar_fd('%', 1);
	ft_putchar_fd('\n', 1);
	return(0);
}
