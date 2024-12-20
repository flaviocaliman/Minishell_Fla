/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:32:32 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/12/04 21:46:55 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_var_len(char *var)
{
	char	*equal_sign;
	int		var_len;

	equal_sign = ft_strchr(var, '=');
	if (equal_sign)
		var_len = equal_sign - var;
	else
		var_len = ft_strlen(var);
	return (var_len);
}

void	update_env_node(t_env *tmp, char *var)
{
	free_ptr(tmp->content);
	tmp->content = ft_strdup(var);
}

void	update_or_add_env_node(t_program *mini, char *var, int replace)
{
	t_env	*tmp;
	int		var_len;

	var_len = get_var_len(var);
	tmp = mini->env_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var, var_len) == 0
			&& (tmp->content[var_len] == '=' || tmp->content[var_len] == '\0'))
		{
			if (replace)
				update_env_node(tmp, var);
			return ;
		}
		tmp = tmp->next;
	}
	add_env_node(mini->env_list, new_env_node_with_content(var));
}

void	handle_export_args(t_program *mini, char **args)
{
	int		i;
	char	*var;
	int		replace;

	i = 0;
	while (args[i])
	{
		var = ft_strdup(args[i]);
		replace = ft_strchr(var, '=') != NULL;
		update_or_add_env_node(mini, var, replace);
		free_ptr(var);
		i++;
	}
}

void	ft_export(t_program *mini, char *input)
{
	char	**args;

	args = ft_split(input, ' ');
	if (!args)
	{
		print_sorted_env_list(mini->env_list);
		return ;
	}
	else if (ft_strcmp(args[0], "=") == 0)
	{
		ft_error_exp_equal(args[0], 1);
		if (args)
		{
			free_array(args);
			args = NULL;
		}
		return ;
	}
	handle_export_args(mini, args);
	if (args)
	{
		free_array(args);
		args = NULL;
	}
}
