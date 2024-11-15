/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/15 23:07:33 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_program *mini, t_organize *program)
{
	t_env	*node;
	// t_env	*prev;
	// t_env	*next;

	if (program->cmds[5])
		ft_error_cmds(program);
	else if (!program->args)
		ft_error_args();
	else
	{
		node = mini->env_list;
		while (node)
		{
			if (ft_strncmp(node->content, program->args, ft_strlen(program->args)) == 0)
			{
				// prev = node->prev;
				// next = node->next;
				if (node->prev)
					node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				if (node == mini->env_list)
					mini->env_list = node->next;
				free(node->content);
				free(node);
				break ;
			}
			node = node->next;
		}
	}
}

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
		// else if (ft_strncmp(mini->user_input, "cd", 2) == 0)
		// 	ft_cd(mini, program);
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
			free_organize(program);
			break ;
		}
		free_organize(program);
		free(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}

