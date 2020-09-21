/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/20 20:27:55 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*read_line(t_tab *t)
{
	get_next_line(0, &t->line);
	//if(t->line)
	//	printf("%ls\n", (unsigned int *)t->line);
	return(t->line);

}

char *read_line2(void)
{
	char *buff;

	get_next_line(0, &buff);
	return (buff);

}

void	initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
}

int		main(int argc, char **env)
{
	t_tab	*t;
	char *line;

	t = malloc (sizeof(t_tab));
	initt(t);
	(void)argc;
	(void)env;
	while (1)
	{
		ft_putstr_fd("marishell%", 1);
	//	line = read_line2();
		line = read_line(t);
		printf("%s\n", line);

	}
}
