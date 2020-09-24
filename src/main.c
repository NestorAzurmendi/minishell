/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/24 18:59:37 by nazurmen         ###   ########.fr       */
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
	while (1)
	{
		ft_putstr_fd("marishell% ", 1);
		t->line = read_line(t);
		read_path(t, env);
		//argv = ft_split(t->line, ' ');
		splits = split_line(t->line);
		if(ft_strncmp(splits[0], "pwd", 3) == 0)
			ft_pwd();
		if(ft_strncmp(splits[0], "echo", 4) == 0)
			ft_echo(&splits[1]);
		if(ft_strncmp(splits[0], "cd", 2) == 0)
			ft_cd(&splits[1]);
	}
}
