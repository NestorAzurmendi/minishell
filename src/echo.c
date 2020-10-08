/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:32:51 by nazurmen          #+#    #+#             */
/*   Updated: 2020/10/08 19:18:31 by emartin-         ###   ########.fr       */
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
		if (ft_strchr(args[i], 34) || ft_strchr(args[i], 39))
		{
			ft_split_com(args[i], 34);
			printf("args   : %s\n", args[i]);
		}	
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
