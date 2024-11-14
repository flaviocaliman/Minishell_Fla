/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:32:46 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/14 21:28:03 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_program			*mini;
	//t_organize			*program;

	//program = NULL;
	mini = calloc(sizeof(t_program), 1);
	if (argc != 1 || argv[1])
	{
		ft_printf("Error: No arguments needed\n");
		return (EXIT_FAILURE);
	}
	if (!env || !*env)
	{
		ft_printf("Error: No environment\n");
		return (EXIT_FAILURE);
	}
	init_struct(mini, env);
	mini_loop(mini);
	free_program(mini);
	return (0);
}
