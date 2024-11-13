/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:39:16 by caliman           #+#    #+#             */
/*   Updated: 2024/11/12 23:39:26 by caliman          ###   ########.fr       */
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