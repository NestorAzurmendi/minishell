/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/25 19:08:01 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(t_tab *t)
{
	char	*line;

	line = NULL;
	get_next_line(0, &t->line);
	return(t->line);
}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
}

int		main(int argc, char **argv, char **env)
{
	t_tab	*t;
	int 	i = 0;

	t = malloc (sizeof(t_tab));
	initt(t);
	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		ft_putstr_fd("marishell% ", 1);
		t->line = read_line(t);
		t->tokens = split_line(t->line);
		if(check_our_implement(t))
		{
			read_path(t, env);
			check_path(t, env);
		}
	}

}
