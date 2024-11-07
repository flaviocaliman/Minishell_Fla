/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:53:25 by caliman           #+#    #+#             */
/*   Updated: 2024/10/31 00:06:05 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd("\n", STDERR);
}

/*
void	print_error(char *cmd, char *error)
{
	char	**str;
	
	str = ft_split(cmd, ' ');
	if (str == NULL)
        return;
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str[0], STDERR);
	ft_putstr_fd(str[1], STDERR);
	ft_putstr_fd(error, STDERR);
	ft_putstr_fd("\n", STDERR);
	free_array(str);
}
*/