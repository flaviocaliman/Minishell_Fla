/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:09:17 by gcampos-          #+#    #+#             */
/*   Updated: 2024/09/10 16:17:35 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função que retorna o tamanho de uma string.
int line_len(char **line)
{
	int i;
	if (!line)
		return (0);
	i = 0;
	while (line[i])
		i++;
	return (i);
}

// Muda o diretório de trabalho atual e atualiza as variáveis de ambiente OLDPWD e PWD.
bool change_dir(t_program *pgr, char *path)
{
	char *temp_pwd;
	
	temp_pwd = getcwd(NULL, 0);
	if (chdir(path) != 0)
	{
		free(temp_pwd);
		error(RED, ERROR_CD_DIRECTORY, path, 1);
		return (false);
	}
	env_export(pgr, "OLDPWD", temp_pwd, 1);
	free(temp_pwd);
	temp_pwd = getcwd(NULL, 0);
	env_export(pgr, "PWD", temp_pwd, 1);
	free(temp_pwd);
	return (true);
}

// Implementa o comando cd, mudando o diretório de trabalho com base nos
// argumentos fornecidos e tratando erros adequadamente.
void ft_cd(t_program *pgr, char **line)
{
	if (line_len(line) > 1)
		return (error(RED, ERROR_CD_ARGS, NULL, 1));
	if (line[1] == NULL || ft_strncmp(line[1], "~", 1) == 0)
	{
		if (change_dir(pgr, getenv("HOME")) != 0)
			error(RED, ERROR_CD_HOME, NULL, 1);	
	}
	else if (ft_strncmp(line[1], "-", 1) == 0)
	{
		if (change_dir(pgr, getenv("OLDPWD")) != 0);
			error(RED, ERROR_CD_OLDPWD, NULL, 1);
	}
	else
	{
		if (change_dir(pgr, line[1]) == -1)
			error(RED, ERROR_CD_DIRECTORY, line[1], 1);
	}
}
