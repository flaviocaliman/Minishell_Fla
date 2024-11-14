/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/14 21:46:33 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
*/

void	ft_remove_env_node(t_envp **head, t_envp *current, t_envp *previus)
{
	if (previus == NULL)
		*head = current->next;
	else
		previus->next = current->next;
	free(current->name);
	free(current->value);
	free(current);
}

void	ft_unset(t_program *mini, t_organize *program)
{
	char	**args;
	int		i;
	t_envp	*current;
	t_envp	*previus;

	(void)mini;
	i = 0;
	if (program->cmds[5])
		ft_error_cmds(program);
	else if (program->args == NULL)
		return ;
	else
	{
		args = ft_new_split(program->args, ' ');
		while (args[i])
		{
			current = mini->envp;
			previus = NULL;
			while (current && current->name)
			{
				printf("estamos aqui\n");
				if (ft_strncmp(current->name, args[i], ft_strlen(args[i])) == 0)
				{
					ft_remove_env_node(&mini->envp, current, previus);
					break ;
				}
				previus = current;
				current = current->next;
			}
			i++;
		}
		free_array(args);
	}
}

int	mini_loop(t_program *mini)
{
	t_organize	*program; //criado inicio

	program = NULL; //criado fim
	while (mini->loop == 0)
	{
		if (parseline(mini))
			continue ;
		mini->pipes = pipes_counter(mini->user_input);
		printf("pipes: %d\n", mini->pipes);
		printf("mini->user_input: %s\n", mini->user_input);
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
