/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/16 23:38:27 by caliman          ###   ########.fr       */
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
//		else if (ft_strncmp(mini->user_input, "export", 6) == 0)
//			ft_export(mini, program);
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

