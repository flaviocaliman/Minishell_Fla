/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:53:46 by caliman           #+#    #+#             */
/*   Updated: 2024/11/05 21:38:38 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função para liberar a memória alocada para
// a estrutura t_program.

void free_pgr(t_program *pgr)
{
	t_envp *envp;
	t_envp *temp;

	envp = pgr->envp;
	while (envp)
	{
		temp = envp;
		envp = envp->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
	free(pgr->path);
}

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
void ft_exit(t_program *mini, char **cmd)
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
	free_pgr(mini);
}
