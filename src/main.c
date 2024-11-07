/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:32:46 by gcampos-          #+#    #+#             */
/*   Updated: 2024/10/31 00:12:26 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

int main(int argc, char **argv, char **env)
{
	t_program mini;
	t_input_organize program;

	if (argc != 1 || argv[1])
	{
		ft_printf("Error: No arguments needed\n");
		return (EXIT_FAILURE);
	}
	init_struct(&mini, env);
	mini_loop(&mini, &program);
	free_program(&mini, &program);
	return (0);
}
