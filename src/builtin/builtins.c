/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:09:17 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/05 20:45:08 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtins(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) == 0 || ft_strncmp(cmd, "cd", 2) == 0
		|| ft_strncmp(cmd, "pwd", 3) == 0 || ft_strncmp(cmd, "export", 6) == 0
		|| ft_strncmp(cmd, "unset", 5) == 0 || ft_strncmp(cmd, "env", 3) == 0
		|| ft_strncmp(cmd, "exit", 4) == 0)
	{
		return (true);
	}
	return (false);
}


void	run_bultin(t_program *mini, t_input_organize *pgr, char **cmd)
{
	(void)mini;
	(void)pgr;
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		ft_cd(mini, cmd);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ft_pwd();
//	else if (ft_strncmp(cmd, "export", 6) == 0)
//		ft_export(mini, cmd);
//	else if (ft_strncmp(cmd, "unset", 5) == 0 == 0)
//		ft_unset(mini, cmd);
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		ft_env(mini);
	else if (ft_strncmp(cmd[0], "exit", 4) == 0)
		ft_exit(mini, cmd);
}
