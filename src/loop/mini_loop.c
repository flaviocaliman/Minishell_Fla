/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/09/20 13:50:29 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_loop(t_program *mini, t_input_organize *program)
{
	while(mini->loop == ON)
	{
		if (parseline(mini))
			continue;
		init_organize(program);
		parse_input(mini, program);
		if (is_builtins(program->cmd_split[0]))
			run_bultin(mini, program, program->cmd_split);
		if(ft_strcmp(mini->user_input, "exit") == 0 || ft_strncmp(mini->user_input, "exit ", 5) == 0)
			break;
		free_organize(program);
		free(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
