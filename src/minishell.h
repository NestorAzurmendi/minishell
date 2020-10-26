/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:44:16 by hellnhell         #+#    #+#             */
/*   Updated: 2020/10/26 13:38:11 by hellnhell        ###   ########.fr       */
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
#include	<errno.h>

typedef struct		s_tab
{
	char		*line;
	char		**tokens;
	char		**orders;
	char		**path;
	char		**args;
	char		**command;
	char		*index;
}					t_tab;

typedef struct Node
{
    char    *element;
	int		pipe_a;
	int		pipe_b;
	int		concat_b;
	int		concat_a;
	int		replace_b;
	int		replace_a;
	int		mins_b;
	int		mins_a;
    struct Node *next;
} Node;

typedef struct  List {
    Node	*first;
	int 	size;
} List;


char	*read_line(t_tab *t);
void	read_path(t_tab *t, char **env);
int		check_path(t_tab *t, char **env);
char	**split_line(char *line);
void 	*ft_realloc(void *ptr, size_t originalsize, size_t newsize);
char	*ft_strtok(char *str, char *sepa);
char	*ft_strjoin_sl(const char *s1, const char *s2);
int		ft_echo(char **args);
int		ft_pwd(void);
int		ft_cd(char **args);
int		check_our_implement(t_tab *t);
char	**ft_split_com(char const *s, char c, t_tab *t);
int		not_command_error(t_tab *t);
void	simbols_flags(t_tab *t, List *list, int doubl);
int		simbols(t_tab *t, List *list, int j, int i);


List    *new_list(void);
Node    *new_node(char *s);
void    destructor_node(Node *node);
void    destructor_list(List *list);
void    pop_front(List *list);
void    pop_back(List *list);
void    pop_n_element(List *list, int n);
void    push_front(List *list, char *s);
void    push_back(List *list, char *s);
void    push_after_n(List *list, char *s, int n);
List    *copy_list(List *list);
void	create_list_elemnts(t_tab *t,List *list,int i);


#endif
