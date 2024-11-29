/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:38:25 by caliman           #+#    #+#             */
/*   Updated: 2024/11/29 02:34:11 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static bool	ft_isnumber(char str)
{
	if (!str)
		return (false);
	if (!ft_isdigit(str))
		return (false);
	return (true);
}
*/

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

/*
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
*/
//################

bool	arg_is_nbr(char *arg)
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
void	check_exit_args(char **args)
{
		if ((args[0][0] == '-' || args[0][0] == '+'))
		{
			if (args[0][0] == '-' && arg_is_nbr(&args[0][1]))
				g_exit_status = 256 - ft_atoi(&args[0][1]);
			else if (args[0][0] == '+' && arg_is_nbr(&args[0][1]))
				g_exit_status = ft_atoi(&args[0][1]);
			else if (!arg_is_nbr(&args[0][1]))
				ft_error_dig(args[0], 2);
		}
		else
		{
			if (arg_is_nbr(&args[0][0]))
				ft_error_dig(args[0], 2);
			else
				g_exit_status = ft_atoi(args[0]);
		}
}

void	handle_exit_error(t_organize *program , char **args)
{
	ft_putstr_fd("exit\n", STDERR);
	print_error(ERROR_EXIT_ARGS, 1);
	free_array(args);
	free_organize(program);
}

void	handle_exit_success_args(t_organize *program , char **args)
{
	ft_putstr_fd("exit\n", STDERR);
	ft_error_dig(args[0], 2);
	free_array(args);
	free_organize(program);
}

void	handle_single_arg_exit(t_organize *program, char **args)
{
	if (!arg_is_nbr(args[0]))
		check_exit_args(args);
	free_array(args);
	free_organize(program);
}

int ft_exit(t_organize *program, char *str)
{
	char	**args;

	if (!str)
	{
		g_exit_status = 0;
		free_organize(program);
		return (EXIT_SUCCESS);
	}
	args = ft_new_split(str, ' ');
	if (arg_is_nbr(args[0]) && args[1])
	{
		handle_exit_error(program, args);
		return (EXIT_FAILURE);
	}
	else if (args[1])
	{
		handle_exit_success_args(program, args);
		return (EXIT_SUCCESS);
	}
	else
	{
		handle_single_arg_exit(program, args);
		return (EXIT_SUCCESS);
	}
}
