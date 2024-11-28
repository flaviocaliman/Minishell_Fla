/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:28:12 by caliman           #+#    #+#             */
/*   Updated: 2024/11/28 01:51:18 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_env(t_env *env_list, char *name, char *value, int replace)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, name, ft_strlen(name)) == 0)
		{
			if (replace)
			{
				free_ptr(tmp->content);
				tmp->content = ft_strjoin(name, value);
			}
			return ;
		}
		tmp = tmp->next;
	}
}

t_env	*ft_get_env(t_env *env_list, char *name)
{
	t_env	*tmp;
	
	tmp = env_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, name, ft_strlen(name)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
/*
void	handle_cd_errors(char *arg)
{
	if (arg[1])
		print_error(ERROR_CD_DIRECTORY, 1);
	else if ((arg[0] != '-' && arg[0] != '~'))
	{
		printf("arg: %s\n", arg);
		(ERROR_CD_DIRECTORY, 1);
	}
}
*/

bool	can_execute(t_env *env_list, char *arg)
{
	t_env	*oldpwd;
	t_env	*home;

	oldpwd = ft_get_env(env_list, "OLDPWD");
	if (arg)
	{
		if (ft_strlen(arg) == 1 && arg[0] == '-')
		{
			if (oldpwd)
			{
				printf("%s\n", oldpwd->content + 7);
				return (!chdir(oldpwd->content + 7));
			}
			else
			{
				ft_error_args(ERROR_CD_OLDPWD, 2);
				return (false);
			}
		}
		return (!chdir(arg));
	}
	home = ft_get_env(env_list, "HOME");
	if (home)
		return (!chdir(home->content + 5));
	return (false);
}

// qunado entro com o comando cd - 2 vezes ele printa a 
void	ft_cd(t_env *env_list, t_organize *program)
{
	char	dir[PATH_MAX];

	getcwd(dir, sizeof(dir));
	if (program->args && program->args[0] == '-' && program->args[1] != '\0')
	{
		ft_error_opt(program->args, 2);
		return ;
	}
	if (!can_execute(env_list, program->args))
	{
		if (!program->args || ft_strcmp(program->args, "~") == 0)
		{
			handle_home_directory(env_list);
			return ;
		}
		ft_error_dir(program->args, 1);
		return ;
	}
	update_env_vars(env_list, dir, sizeof(dir));
}
