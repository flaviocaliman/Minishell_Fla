/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:33:02 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/09 13:33:39 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
Print Working Directory: exibe o caminho
completo do diretório de trabalho atual.
*/

void	ft_pwd(void)
{
	char *path;
	
	path = getcwd(NULL, 0);
	if (path)
	{
		printf("%s\n", path);
		free(path);
	}
	else
		printf("%s\n", ERROR_PWD_DIRECTORY);
}