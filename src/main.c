/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/23 19:42:31 by emartin-         ###   ########.fr       */
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
		read_path(t, env);
		t->tokens = split_line(t->line);
		while (t->tokens[i])
		{
			printf("valor de tokens=    %s\n", t->tokens[i]);
			i++;
		}

		check_path(t);
	}

}
