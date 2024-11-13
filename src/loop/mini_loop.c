/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/13 22:35:50 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	env_export(t_program *mini, char *name, char *value, int visible)
{
	t_envp	*envp;

	envp = find_envp_node(name, mini->envp);
	if (envp)
	{
		if (visible)
		{
			free(envp->value);
			envp->value = ft_strdup(value);
		}
	}
	else
	{
		envp = new_envp_node(name, value);
		add_envp_node(envp, mini->envp);
	}
}

bool	change_dir(t_program *mini, char *path)
{
	char	*temp_pwd;

	temp_pwd = getcwd(NULL, 0);
	if (chdir(path) != 0)
	{
		free(temp_pwd);
		print_error(ERROR_CD_DIRECTORY);
		return (false);
	}
	env_export(mini, "OLDPWD", temp_pwd, 1);
	free(temp_pwd);
	temp_pwd = getcwd(NULL, 0);
	env_export(mini, "PWD", temp_pwd, 1);
	free(temp_pwd);
	return (true);
}

void	ft_cd(t_program *mini, t_organize *program)
{
	char	*path;

	if (program->args[1] == NULL || ft_strncmp(program->args[1], "~", 1) == 0)
	{
		path = ft_strdup(getenv("HOME"));
		if (change_dir(mini, path) != 0)
			print_error(ERROR_CD_HOME);
	}
	else if (ft_strncmp(program->args[1], "-", 1) == 0)
	{
		path = ft_strdup(getenv("OLDPWD"));
		if (change_dir(mini, path) != 0)
			print_error(ERROR_CD_OLDPWD);
	}
	else
	{
		path = ft_strdup(program->args[1]);
		if (change_dir(mini, path) != 0)
			print_error(ERROR_CD_DIRECTORY);
	}
	free(path);
}
*/

int	mini_loop(t_program *mini)
{
	t_organize	*program; //criado inicio

	program = NULL; //criado fim
	while (mini->loop == 0)
	{
		if (parseline(mini))
			continue ;
		mini->pipes = pipes_counter(mini->user_input);
		printf("pipes: %d\n", mini->pipes);
		printf("mini->user_input: %s\n", mini->user_input);
		program = init_organize(mini);
		parse_input(mini, program);
		if (ft_strncmp(mini->user_input, "echo", 4) == 0)
			ft_echo(program);
		// else if (ft_strncmp(mini->user_input, "cd", 2) == 0)
		// 	ft_cd(mini, program);
		else if (ft_strncmp(mini->user_input, "pwd", 3) == 0)
			ft_pwd(program);
//		else if (ft_strncmp(mini->user_input, "export", 6) == 0)
//			ft_export(mini, program);
//		else if (ft_strncmp(mini->user_input, "unset", 5) == 0)
//			ft_unset(mini, program);
//		else if (ft_strncmp(mini->user_input, "env", 3) == 0)
//			ft_env(mini, program);
		else if (ft_strncmp(mini->user_input, "exit", 4) == 0)
		{
			free_organize(program);
			break ;
		}
		free_organize(program);
		free(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
