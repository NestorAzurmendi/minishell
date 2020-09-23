/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:18:50 by nazurmen          #+#    #+#             */
/*   Updated: 2020/09/24 18:22:08 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_pwd(void)
{
	char *buff;

	buff = malloc(1024);
	getcwd(buff, 1024);
	ft_putstr_fd(buff, 1);
	ft_putchar_fd('\n', 1);
	free(buff);
}
