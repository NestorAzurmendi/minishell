/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/09/21 19:22:02 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_path(t_tab *t, char **env)
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
