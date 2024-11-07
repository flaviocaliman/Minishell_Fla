/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:09:17 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/04 22:14:52 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função que retorna o tamanho de uma string.
int line_len(char **cmd)
{
	int i;
	if (!cmd)
		return (0);
	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

// Muda o diretório de trabalho atual e atualiza as variáveis de ambiente OLDPWD e PWD.
bool change_dir(t_program *mini, char *path)
{
	char *temp_pwd;
	
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

// Implementa o comando cd, mudando o diretório de trabalho com base nos
// argumentos fornecidos e tratando erros adequadamente.
void ft_cd(t_program *mini, char **cmd)
{
	if (line_len(cmd) > 1)
		return (print_error(ERROR_CD_ARGS));
	if (cmd[1] == NULL || ft_strncmp(cmd[1], "~", 1) == 0)
	{
		if (change_dir(mini, getenv("HOME")) != 0)
			print_error(ERROR_CD_HOME);	
	}
	else if (ft_strncmp(cmd[1], "-", 1) == 0)
	{
		if (change_dir(mini, getenv("OLDPWD")) != 0)
			print_error(ERROR_CD_OLDPWD);
	}
	else
	{
		if (!change_dir(mini, cmd[1]))
			print_error(ERROR_CD_DIRECTORY);
	}
}
