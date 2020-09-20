/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/09/20 19:06:53 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char    *read_line(t_tab *t)
{
    get_next_line(0, &t->line);
    return(t->line);
    
}

int     main(char **env)
{
    t_tab   *t;
    
    while (1)
    {
        ft_putstr_fd("marishell%", 1);
        read_line(t);
    }
}