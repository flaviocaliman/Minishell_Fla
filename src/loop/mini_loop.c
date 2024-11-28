/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/28 22:19:53 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_builtin(t_program *mini, t_organize *program, char *input, int fd1, int fd2)
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
		if (exit_return == EXIT_SUCCESS)
		{
			free_ptr(input);
			free_program(mini);
			exit (g_exit_status);
		}
		else
		{
			free_ptr(input);
			free_program(mini);
		}
	}
	// else
	// 	print_error(ERROR_CMD_NOT_FOUND, 127);
	return (0);
}

void	reset_fd_signals(int const fd, int const fd1)
{
	// ft_handle_signals(MAIN);
	dup2(fd, STDIN_FILENO);
	dup2(fd1, STDOUT_FILENO);
}

int	mini_loop(t_program *mini, int fd1, int fd2)
{
	t_organize	*program;
	char		*input;

	while (mini->loop == 0)
	{
		
		program = NULL;
		reset_fd_signals(fd1, fd2);
		input = readline("minishell$ ");
		if (parse_readline(&input, mini->env_list) == 0)
		{
			program = init_organize(input);
			if (parse_organize(program, input, mini->env_list) == 1)
			{
				free_organize(program);
				free_ptr(input);
				continue ;
			}
			printf("cmds: %s\n", program->cmds);
			if (run_builtin(mini, program, input, fd1, fd2))
				break ;
			//executor(program, mini);
			free_organize(program);
			free_ptr(input);
		}
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
