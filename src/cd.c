/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:04:47 by nazurmen          #+#    #+#             */
/*   Updated: 2020/10/06 18:06:36 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args)
{
	char *path;
	int i;

	path = args[0];
	i = 1;
	if (-1 == chdir(path))
	{
		ft_putstr_fd("cd: no such file or directory: ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd('\n', 1);
	}
	else 
	{
		while (args[i])
		{
			path = ft_strjoin(path, args[i]);
			if (args[++i])
				path = ft_strjoin(path, " ");
		}
	}
	return(0);
}
