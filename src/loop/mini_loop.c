/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/21 20:15:15 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fd_signals(int const fd, int const fd1)
{
	// ft_handle_signals(MAIN);
	dup2(fd, STDIN_FILENO);
	dup2(fd1, STDOUT_FILENO);
}

int	mini_loop(t_program *mini, int fd1, int fd2)
{
	t_organize	*program;
	//char		*input;

	while (mini->loop == 0)
	{
		reset_fd_signals(fd1, fd2);
		program = NULL;
		//input = readline("minishell$ ");
		if (parseline(mini))
			continue ;
		program = init_organize(mini);
		parse_input(mini->user_input, program);
		if (ft_strncmp(mini->user_input, "echo", 4) == 0)
			ft_echo(program);
		// else if (ft_strncmp(mini->user_input, "cd", 2) == 0)
		// 	ft_cd(mini, program);
		else if (ft_strncmp(mini->user_input, "pwd", 3) == 0)
			ft_pwd(program);
		else if (ft_strncmp(mini->user_input, "export", 6) == 0)
		{
			printf("export: No arguments\n");
			ft_export(mini, program);
		}
		else if (ft_strncmp(mini->user_input, "unset", 5) == 0)
			ft_unset(mini, program);
		else if (ft_strncmp(mini->user_input, "env", 3) == 0)
			ft_env(mini, program);
		else if (ft_strncmp(mini->user_input, "exit", 4) == 0)
		{
			if (ft_exit(program, program->args) == EXIT_FAILURE)
				break;
		}
		// executor(program, mini);
		if (program)
			free_organize(program);
		if (mini->user_input)
			free_ptr(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}

