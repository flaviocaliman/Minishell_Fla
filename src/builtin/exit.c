/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:38:25 by caliman           #+#    #+#             */
/*   Updated: 2024/11/21 19:05:03 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	bool ft_isnumber(char str)
{
	if (!str)
		return (false);
	if (!ft_isdigit(str))
		return (false);
	return (true);
}

void	free_and_exit(t_organize *pgr, int status)
{
	if (pgr)
		free_organize(pgr);
	exit(status);
}

int	check_exit_args(char *arg)
{
	int		i;
	char	**args_array;
	
	args_array = ft_new_split(arg, ' ');
	if (args_array[1])
	{
		print_error(ERROR_EXIT_ARGS);
		return (EXIT_FAILURE);
	}
	if (args_array[0])
	{
		i = 0;
		while (args_array[0][i])
		{
			if (args_array[0][0] == '-' || args_array[0][0] == '+')
				i++;
			if (!ft_isnumber(args_array[0][i]))
			{
				print_error(ERROR_EXIT_DIGIT);
				return (EXIT_SUCCESS);
			}
			i++;
		}
	}
	if (args_array)
		free_array(args_array);
	return (EXIT_SUCCESS);
}

int	ft_exit(t_organize *program, char *str)
{
	char	*arg;

	arg = str;
	if (program->cmds[4])
	{
		ft_error_cmds(program);
		return (EXIT_FAILURE);
	}
	if (arg)
	{
		if (check_exit_args(arg) == EXIT_FAILURE)
		{
			if (arg)
				free_ptr(arg);
			return (EXIT_FAILURE);
		}
	}
	// if (program)
	// 	free_organize(program);
	return (EXIT_SUCCESS);
}
