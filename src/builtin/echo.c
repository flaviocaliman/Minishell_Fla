/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:29:26 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/09 13:29:42 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função que exibe uma string na saída padrão. Com ou sem
// quebra de linha (-n).

void print_args(char **str, int i)
{
	int 	j;

	j = 0;
	while (*str)
	{
		if (str[i] == NULL)
            break;
		if (str[i][j] != '\0')
		{
			if (str[i][j] == '"')
			{
				while (str[i][j] == '"')
					j++;
			}
			else
				write(1, &str[i][j++], 1);
		}
		else
		{
			if (str[i + 1] != NULL)
				write(1, " ", 1);
			i++;
			j = 0;
		}
	}
}

void ft_echo(char **cmd)
{
	char	**str;
	int 	n;
	int 	i;
	
	i = 0;
	n = 0;
	if (cmd == NULL || cmd[0] == NULL)
        return;
	if (ft_strncmp(cmd[0], "echo -n", 7) == 0)
		n = 1;
	str = ft_split(cmd[0], ' ');
	if (str == NULL)
        return;
	i++;
	if (n == 1)
		i++;
	print_args(str, i);
	if (n == 0)
		write(1, "\n", 1);
	free_array(str);
}