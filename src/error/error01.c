/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:25:27 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/30 01:19:47 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_digit(char *str, int status)
{
	ft_printf("minishell: exit: %s: numeric argument required", str);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}
void	ft_error_path_cmds(char *cmd, int status)
{
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd(": command not found", STDERR);
	ft_putstr_fd("\n", STDERR);
	g_exit_status = status;
	return ;
}