/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:32:46 by gcampos-          #+#    #+#             */
/*   Updated: 2024/09/09 19:50:59 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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