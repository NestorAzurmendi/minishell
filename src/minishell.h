/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:44:16 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/20 19:00:29 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include   <stdio.h>
# include   <unistd.h>
# include   <string.h>
# include   <stdlib.h>

typedef struct      s_tab
{
    char    **line;
    char    *path;
}                   t_tab;

char    *read_line(t_tab *t);


#endif