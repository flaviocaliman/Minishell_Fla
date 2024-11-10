/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:31:49 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/10 15:05:03 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função para verificar se um caractere é um dígito.
static bool ft_isnumber(char *str)
{
	int i;
	
	i = 0;
	if (!str[i])
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

// Função para sair do shell.
void ft_exit(t_program *mini, t_organize *pgr, char **cmd)
{
	int i;

	i = 0;
	if (cmd[0])
	{
		if (cmd[2])
		{
			print_error(ERROR_EXIT_ARGS);
			return;
		}
		if (cmd[1])
		{
			while (cmd[1][i])
			{
				if (!ft_isnumber(cmd[1]))
				{
					print_error(ERROR_EXIT_DIGIT);
					return;
				}
				i++;
			}
		}	
	}
	free_program(mini, pgr);
}