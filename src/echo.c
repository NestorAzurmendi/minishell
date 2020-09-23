/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:32:51 by nazurmen          #+#    #+#             */
/*   Updated: 2020/09/23 19:41:55 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	if (ft_strncmp("-n", args[i], 2))
	{
		i++;
		flag++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (flag)
	{
		ft_putchar_fd('%', 1);
	}
}
