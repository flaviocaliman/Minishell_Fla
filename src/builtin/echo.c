/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:25 by caliman           #+#    #+#             */
/*   Updated: 2024/09/10 16:18:04 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função que exibe uma string na saída padrão. Com ou sem
// quebra de linha (-n).
void ft_echo(char **line)
{
	int i;
	
	i = 1;
	if (line[0] && !ft_strcmp(line[0], "-n"))
		i++;
	while (line[i])
	{
		printf("%s", line[i]);
		if (line[i + 1])
			printf(" ");
		i++;
	}
	if (!line[0] || ft_strcmp(line[0], "-n") != 0)
		printf("\n");
}
