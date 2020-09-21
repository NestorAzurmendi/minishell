/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/09/21 18:49:11 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char  *read_path(t_tab *t, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			t->path = ft_split(&env[i][5], ':');
		i++;
	}
	return (*t->path);
}