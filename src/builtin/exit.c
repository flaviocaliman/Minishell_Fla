/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:38:25 by caliman           #+#    #+#             */
/*   Updated: 2024/11/28 02:23:26 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_isnumber(char str)
{
	if (!str)
		return (false);
	if (!ft_isdigit(str))
		return (false);
	return (true);
}

void	free_and_exit(t_organize *pgr, int status)
{
	free_organize(pgr);
	exit(status);
}



int	check_exit_args(char **args)
{
	int	i;

	// if (!args[0])
	// 	return (EXIT_SUCCESS);
	if (args[1])
	{
		ft_putstr_fd("exit\n", STDERR);
		print_error(ERROR_EXIT_ARGS, 1);
		return (EXIT_FAILURE);
	}
	if (args[0])
	{
		i = 0;
		while (args[0][i])
		{
			if ((args[0][0] == '-' || args[0][0] == '+') && i == 0)
			{
				i++;
				if (args[0][0] == '-' && (args[0][i] >= '0' && args[0][i] <= '9') && ft_atoi(&args[0][i]) != 0)
					g_exit_status = 256 - ft_atoi(&args[0][i]);
				else if (args[0][0] == '+' && (args[0][i] >= '0' && args[0][i] <= '9') && ft_atoi(&args[0][i]) != 0)
					g_exit_status = ft_atoi(&args[0][i]);
			}
			else
			{
				if (!ft_isnumber(args[0][i]))
				{
					ft_error_args(args[0], 2);
					return (EXIT_SUCCESS);
				}
				else
				{
					g_exit_status = ft_atoi(args[0]);
					i++;
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_exit(t_organize *program, char *str)
{
	char	**args;

	if (program->cmds[4])
	{
		printf("exit\n");
		ft_error_cmds(program, 127);
		return (EXIT_SUCCESS);
	}
	else if (!str)
	{
		g_exit_status = 0;
		free_organize(program);
		return (EXIT_SUCCESS);
	}
	args = ft_new_split(str, ' ');
	if (args[0] && check_exit_args(args) == EXIT_FAILURE)
	{
		free_array(args);
		free_organize(program);
		return (EXIT_FAILURE);
	}
	free_organize(program);
	free_array(args);
	return (EXIT_SUCCESS);
}
