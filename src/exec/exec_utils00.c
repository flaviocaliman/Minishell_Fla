/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:33:26 by gcampos-          #+#    #+#             */
/*   Updated: 2024/12/04 23:27:06 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_list_size(t_organize *program)
{
	t_organize	*tmp;
	int			i;

	i = 0;
	tmp = program;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	msg(char *msg, int check, int output)
{
	write(output, msg, ft_strlen(msg));
	if (check == 0)
		exit(1);
}

char	**ft_getenv(t_env *env)
{
	char	**ret;
	int		i;
	t_env	*tmp;

	tmp = env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	tmp = env;
	while (tmp)
	{
		ret[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	nopath(char **envp)
{
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			return (0);
		envp++;
	}
	return (1);
}

char	*find_path(char *cmd, char **envp, int count)
{
	char	*part_path;
	char	*cmd_path;
	char	**envp_path;

	if (nopath(envp))
	{
		ft_error_path_cmd(cmd, 127);
		return (NULL);
	}
	while (!ft_strnstr(*envp, "PATH=", 5))
		envp++;
	envp_path = ft_split(*envp + 5, ':');
	while (envp_path[++count] && cmd[0] != '/')
	{
		part_path = ft_strjoin(envp_path[count], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free_ptr(part_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_array(envp_path);
			return (cmd_path);
		}
		free_ptr(cmd_path);
	}
	free_array(envp_path);
	if (cmd[0] == '/' && access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	ft_error_path_cmd(cmd, 127);
	return (NULL);
}


int	exec_cmd(char *cmd, char *args, t_env *envp)
{
	char	*path;
	char	*cmd_arg;
	char	*tmp;
	char	**cmd_split;
	char	**env;

	tmp = ft_strjoin(cmd, " ");
	cmd_arg = ft_strjoin(tmp, args);
	free_ptr(tmp);
	printf("cmd_arg: %s\n", cmd_arg);
	cmd_split = ft_split(cmd_arg, ' ');
	free_ptr(cmd_arg);
	env = ft_getenv(envp);
	path = find_path(cmd, env, -1);
	if (!path)
	{
		free_array(cmd_split);
		free_array(env);
		return (0);
	}
	if (execve(path, cmd_split, env) == -1)
		free_ptr(path);
	free_array(cmd_split);
	return (0);
}
