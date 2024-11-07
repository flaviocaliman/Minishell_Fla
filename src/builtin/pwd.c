/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:11:06 by caliman           #+#    #+#             */
/*   Updated: 2024/09/20 09:45:06 by caliman          ###   ########.fr       */
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
