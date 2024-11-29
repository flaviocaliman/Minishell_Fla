/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:40:54 by caliman           #+#    #+#             */
/*   Updated: 2024/11/29 01:17:27 by caliman          ###   ########.fr       */
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

void	ft_error_dir(char *dir, int status)
{
	ft_putstr_fd("minishell: cd: ", STDERR);
	ft_putstr_fd(dir, STDERR);
	ft_putstr_fd(": No such file or directory\n", STDERR);
	g_exit_status = status;
	return ;
}

void	ft_error_args(char *str, int status)
{
	ft_printf("minishell: %s: invalid argument", str);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}

void	ft_error_opt(char *str, int status)
{
	ft_printf("minishell: cd: %s: invalid option", str);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}

void	ft_error_dig(char *str, int status)
{
	ft_printf("minishell: exit: %s: numeric argument required", str);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}