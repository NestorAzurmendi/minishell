/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/23 19:43:26 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(t_tab *t)
{
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
}

int		main(int argc,char **argv, char **env)
{
	t_tab	*t;
	char **splits;

	t = malloc (sizeof(t_tab));
	initt(t);
	(void)argc;
	(void)argv;
	(void)env;
	(void)splits;
		ft_pwd();
	while (1)
	{
		ft_putstr_fd("marishell% ", 1);
		t->line = read_line(t);
		read_path(t, env);
		//argv = ft_split(t->line, ' ');
		split_line(t->line);
		printf("%s %s %s\n", splits[0], splits[1], splits[2]);
	}
}
