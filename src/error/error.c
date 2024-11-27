/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:40:54 by caliman           #+#    #+#             */
/*   Updated: 2024/11/27 18:41:57 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *cmd, int status)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}

void	ft_error_cmds(t_organize *program, int status)
{
	ft_putstr_fd(program->cmds, STDERR);
	ft_putstr_fd(": command not found", STDERR);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}

void	ft_error_args(char *str, int status)
{
	ft_printf("minishell: %s: invalid argument\n", str);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}
