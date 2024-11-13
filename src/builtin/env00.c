/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:37:01 by caliman           #+#    #+#             */
/*   Updated: 2024/11/12 23:37:05 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp(t_program *pgr)
{
	t_envp	*temp;

	temp = pgr->env_unsorted;
	while (temp)
	{
		ft_putstr_fd(temp->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(temp->value, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

char	*get_env(char *name, t_program *pgr)
{
	t_envp	*temp;

	temp = pgr->env_unsorted;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_env(t_program *pgr, char** cmd)
{
	if (cmd[1])
		print_error(ERROR_ENV_ARGS);
	else
	{
		if (get_env("PATH", pgr))
			print_envp(pgr);
	}
}
