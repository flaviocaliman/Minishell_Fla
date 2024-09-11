/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:40:30 by caliman           #+#    #+#             */
/*   Updated: 2024/09/10 19:50:09 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_cmd(t_program *mini, t_command *cmd)
{
	if (cmd->type == EXEC)
		run_exec_cmd(mini, (t_exec *)cmd);
	else if (cmd->type == REDIR)
		run_redir_cmd(mini, (t_redir *)cmd);
	else if (cmd->type == PIPE)
		run_pipe_cmd(mini, (t_pipe *)cmd);
	else if (cmd->type == HERE_DOC)
		run_heredoc_cmd(mini, (t_heredoc *)cmd);
}