/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/18 17:47:36 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_loop(t_program *mini)
{
	t_organize	*program;

	program = NULL;
	while (mini->loop == 0)
	{
		if (parseline(mini))
			continue ;
		mini->pipes = pipes_counter(mini->user_input);
		printf("pipes: %d\n", mini->pipes);
		program = init_organize(mini);
		parse_input(mini, program);
		if (ft_strncmp(mini->user_input, "echo", 4) == 0)
			ft_echo(program);
//		else if (ft_strncmp(mini->user_input, "cd", 2) == 0)
//			ft_cd(mini, program);
		else if (ft_strncmp(mini->user_input, "pwd", 3) == 0)
			ft_pwd(program);
		else if (ft_strncmp(mini->user_input, "export", 6) == 0)
			ft_export(mini);
		else if (ft_strncmp(mini->user_input, "unset", 5) == 0)
			ft_unset(mini, program);
		else if (ft_strncmp(mini->user_input, "env", 3) == 0)
			ft_env(mini, program);
		else if (ft_strncmp(mini->user_input, "exit", 4) == 0)
		{
			if (ft_exit(program, mini->user_input) == EXIT_SUCCESS)
				break ;
		}
		free_organize(program);
		free(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
/*
int is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		return (1);
	else
		return (0);
}

int exec_builtin(t_program *mini, char *cmds, char *args)
{
	if (ft_strncmp(cmds, "echo", 4) == 0)
		ft_echo(args);
	else if (ft_strncmp(cmds, "cd", 2) == 0)
		ft_cd(args);
	else if (ft_strncmp(cmds, "pwd", 3) == 0)
		ft_pwd(args);
	else if (ft_strncmp(cmds, "export", 6) == 0)
		ft_export(mini, args);
	else if (ft_strncmp(cmds, "unset", 5) == 0)
		ft_unset(mini, args);
	else if (ft_strncmp(cmds, "env", 3) == 0)
		ft_env(mini, args);
	else if (ft_strncmp(cmds, "exit", 4) == 0)
	{
		if (ft_exit(args, cmds) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void executor(t_program *mini){
	t_organize	*program;
	program = NULL;
	
	while (program->next)
	{
		if (is_builtin(program->cmds) == 1)
			exec_builtin(program->cmds, program->args, mini);
		else
			//executa execve
		program = program->next;
	}
}
*/