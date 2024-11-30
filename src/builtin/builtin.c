/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:15:33 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/30 15:00:24 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_exit(int exit_return)
{
	printf("g_exit_status: %d\n", g_exit_status);
	if (exit_return == EXIT_SUCCESS)
	{
		exit (g_exit_status);
	}
}

int	run_builtin(t_program *mini, t_organize *program)
{
	int	exit_return;

	exit_return = 0;
	if (ft_strcmp(program->cmds, "unset") == 0)
		ft_unset(mini->env_list, program);
	else if (ft_strcmp(program->cmds, "export") == 0)
		ft_export(mini->env_list, program->args);
	else if (ft_strcmp(program->cmds, "env") == 0)
		ft_env(mini->env_list, program);
	else if (ft_strcmp(program->cmds, "echo") == 0)
		ft_echo(program);
	else if (ft_strcmp(program->cmds, "cd") == 0)
		ft_cd(mini->env_list, program);
	else if (ft_strcmp(program->cmds, "pwd") == 0)
		ft_pwd(program);
	else if (ft_strcmp(program->cmds, "exit") == 0)
	{
		exit_return = ft_exit(program, program->args);
		handle_exit(exit_return);
	}
	else
		ft_error_cmds(program->cmds, 127);
	return (0);
}
