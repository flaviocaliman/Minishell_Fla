/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:09:17 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/13 01:25:49 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
bool	ft_is_builtin(char *cmd)
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

void	ft_builtin(t_program *mini, t_organize *program, char **line)
{
	if (ft_strncmp(line[0], "echo", 4) == 0)
		ft_echo(line);
//	else if (ft_strncmp(line[0], "cd", 2) == 0)
//		ft_cd(mini, line);
	else if (ft_strncmp(line[0], "pwd", 3) == 0)
		ft_pwd();
//	else if (ft_strncmp(line[0], "export", 6) == 0)
//	 	ft_export(mini, line);
//	else if (ft_strncmp(line[0], "unset", 5) == 0)
// 		ft_unset(mini, line);
	else if (ft_strncmp(line[0], "env", 3) == 0)
		ft_env(mini,line);
	else if (ft_strncmp(line[0], "exit", 4) == 0)
		ft_exit(mini, program, line);
}
*/

/*
void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	ft_printf("%s\n", cwd);
	free(cwd);
}

void	ft_echo(char **line)
{
	int	i;

	i = 1;
	while (line[i])
	{
		ft_printf("%s", line[i]);
		if (line[i + 1])
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void	ft_cd(char **line)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (line[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else if (ft_strncmp(line[1], "~", 1) == 0)
	{
		chdir(getenv("HOME"));
	}
	else if (ft_strncmp(line[1], "-", 1) == 0)
	{
		chdir(getenv("OLDPWD"));
	}
	else
	{
		if (chdir(line[1]) == -1)
			ft_printf("cd: %s: No such file or directory\n", line[1]);
	}
	free(cwd);
}
*/
