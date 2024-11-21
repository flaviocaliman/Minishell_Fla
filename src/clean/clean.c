/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:25:00 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/21 18:50:06 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_list(t_env *list)
{
	t_env	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->content)
			free(tmp->content);
		if (tmp)
			free(tmp);
	}
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_organize(t_organize *program)
{
	t_organize	*tmp;

	while (program)
	{
		tmp = program;
		program = program->next;
		if (tmp->input_file)
			free_ptr(tmp->input_file);
		if (tmp->output_file)
			free_ptr(tmp->output_file);
		if (tmp->append_file)
			free_ptr(tmp->append_file);
		if (tmp->heredoc_dlm)
			free_ptr(tmp->heredoc_dlm);
		if (tmp->cmds)
			free_ptr(tmp->cmds);
		if (tmp->args)
			free_ptr(tmp->args);
		if (tmp)
			free(tmp);
	}
}

void	free_program(t_program *mini)  
{
	free_array(mini->path);
	free_ptr(mini->pwd);
	free_ptr(mini->old_pwd);
	delete_list(mini->env_list);
	delete_list(mini->export_list);
	if (mini->user_input)
		free_ptr(mini->user_input);
	// if (mini)
	// 	free(mini);
}
