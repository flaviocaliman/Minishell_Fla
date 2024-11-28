/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:38:25 by caliman           #+#    #+#             */
/*   Updated: 2024/11/28 22:31:11 by fgomes-c         ###   ########.fr       */
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

// static int	handle_exit_sign(char **args, int i)
// {
// 	printf("entrei no handle_exit_sign\n");
//     if ((args[0][0] == '-' || args[0][0] == '+'))
//     {
//         i++;
//         if (args[0][0] == '-' && (args[0][i] >= '0' && args[0][i] <= '9') && ft_atoi(&args[0][i]) != 0)
//             g_exit_status = 256 - ft_atoi(&args[0][i]);
//         else if (args[0][0] == '+' && (args[0][i] >= '0' && args[0][i] <= '9') && ft_atoi(&args[0][i]) != 0)
//             g_exit_status = ft_atoi(&args[0][i]);
//         return (1);
//     }
//     return (0);
// }

// static int	validate_exit_args(char **args)
// {
//     int	i;

//     i = 0;
//     while (args[0][i])
//     {
//         if (handle_exit_sign(args, i))
//             ;
//         if (!ft_isnumber(args[0][i]))
//         {
//             ft_error_args(args[0], 2);
//             return (EXIT_SUCCESS);
//         }
//         i++;
//     }
//     g_exit_status = ft_atoi(args[0]);
//     return (EXIT_SUCCESS);
// }

// int	check_exit_args(char **args)
// {
//     if (args[1])
//     {
//         ft_putstr_fd("exit\n", STDERR);
//         print_error(ERROR_EXIT_ARGS, 1);
//         return (EXIT_FAILURE);
//     }
//     return validate_exit_args(args);
// }

int	check_exit_args(char **args)
{
	int	i;

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
			if ((args[0][0] == '-' || args[0][0] == '+'))
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

	if (!str)
	{
		g_exit_status = 0;
		free_organize(program);
		return (EXIT_SUCCESS);
	}
	args = ft_new_split(str, ' ');
	if (args[1])
	{
		ft_putstr_fd("exit\n", STDERR);
		print_error(ERROR_EXIT_ARGS, 1);
		free_array(args);
		free_organize(program);
		return (EXIT_FAILURE);
	}
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
//################

void	arg_is_nbr(char *arg)
{
	int i;

	i = 0;
	if (!arg)
		return (false);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}
int	check_exit_args(char **args)
{
	int	i;

	if (args[0])
	{
		i = 0;
		while (args[0][i])
		{
			if ((args[0][0] == '-' || args[0][0] == '+'))
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


int ft_exit(t_organize *program, char *str)
{
	char	**args;
	long	arg00;

	if (!str)
	{
		g_exit_status = 0;
		free_organize(program);
		return (EXIT_SUCCESS);
	}
	args = ft_new_split(str, ' ');
	arg00 = ft_atoi(args[0]);
	if (arg00 && arg00 != 0 && args[1])
	{
		ft_putstr_fd("exit\n", STDERR);
		print_error(ERROR_EXIT_ARGS, 1);
		return (EXIT_FAILURE);
	}
	else
	{
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
}
