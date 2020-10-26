/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lelemnts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/26 13:40:40 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		simbols(t_tab *t, List *list, int j, int i)
{
	int		simbol;

	if ((t->orders[i][j] == '|') || (t->orders[i][j] == '<') || (t->orders[i][j] == '>'))
		simbol = 1;
	else
		simbol = 0;
	return (simbol);	
}

void		simbols_flags(t_tab *t, List *list, int doubl)
{
	int		y;

	y = 0;
	while (t->index[y])
	{
		//En el MAc cambiar numeros x simbolos xq no se xq coño no los pilla
		if (t->index[y] == 124)
		{
			list->first->pipe_a = 1;
			list->first->next->pipe_b = 1; 
		}	
		else if (t->index[y] == 60)
		{
			list->first->mins_a = 1;
			list->first->next->mins_b = 1;
		}	
		else if (t->index[y] == 32 && doubl == 0)
		{
			list->first->concat_a= 1;
			list->first->next->concat_b = 1; 
		}
		else if (doubl == 1)
		{
			list->first->replace_a = 1;
			list->first->next->replace_b = 1; 
		}
		y++;			
	}
}


void	create_list_elemnts(t_tab *t, List *list, int i)
{
	unsigned int		j;
	int 				y;
	int					x;
	char				*aux;
	int					doubl;

	j = 0;
	y = 0;
	doubl = 0;
	if (!(aux = malloc(sizeof(char*) * ft_strlen(t->orders[i]))))
		return;
	if (!(t->index = malloc(sizeof(char *) * ft_strlen(t->orders[i]))))
		return;
		x = 0;
	while (t->orders[i][j])
	{
		if (simbols(t, list, j, i) == 0) // Esto mira si es un simbolito solo
		{
			aux[x] = t->orders[i][j];
			x++;
		}	
		else
		{
			if (t->orders[i][j] ==  '>' && t->orders[i][++j] == '>')
			{
				printf("d1\n");
				doubl = 1;
				t->index[y] = t->orders[i][++j];
			}
			else
				t->index[y] = t->orders[i][j];
			y++;
			push_back(list, aux);//esto te crea nuevos nodos
			x = 0;
		}
		simbols_flags(t, list, doubl); // esto mira q simbolo es y activa flags 
		j++;
	}
	push_back(list, aux);
	free(aux);
	free(t->index);
}
