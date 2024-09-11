/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:53:46 by caliman           #+#    #+#             */
/*   Updated: 2024/09/10 16:18:24 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função para liberar a memória alocada para
// a estrutura t_program.
void free_program(t_program *pgr)
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
void ft_exit(t_program *pgr, char **line)
{
	int i;

	i = 0;
	if (line[1])
	{
		if (line[2])
			return (error(RED, ERROR_EXIT_ARGS, NULL, 1));
		while (line[1][i])
		{
			if (!ft_isnumber(line[1][i]))
				return (error(RED, ERROR_EXIT_DIGIT, NULL, 1));
			i++;
		}
		g_exit_status = ft_atoi(line[1]) % 256;
	}
	else
		g_exit_status = 0;
	free_program(pgr);
	exit(g_exit_status);
}