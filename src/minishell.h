/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:44:16 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/22 18:21:10 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	"../libft/libft.h"
# include	"../libft/get_next_line/get_next_line.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>

typedef struct		s_tab
{
	char	*line;
	char	**our_env;
	char	**path;
	char	**argv;
	char	*join;
}					t_tab;

char	*read_line(t_tab *t);
void	read_path(t_tab *t, char **env);
void	check_path(t_tab *t);


#endif
