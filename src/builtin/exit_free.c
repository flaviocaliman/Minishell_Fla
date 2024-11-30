/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:38:25 by caliman           #+#    #+#             */
/*   Updated: 2024/11/30 01:53:59 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_and_exit(t_organize *pgr, int status)
{
	free_organize(pgr);
	exit(status);
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
	ft_error_digit(args[0], 2);
	free_array(args);
	free_organize(program);
}
