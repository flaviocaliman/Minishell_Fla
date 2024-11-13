/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/13 01:51:42 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
*/
void	print_args(const char *args)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = ft_split(args, ' ');
	if (ft_strncmp(str[0], "-n", 2) == 0)
		i = 1;
	while (str[i])
	{
		j = 0;
		write(1, " ", 1);
		while (str[i][j])
		{
			if (str[i][j] == '"')
				j++;
			else
				write(1, &str[i][j++], 1);
		}
		i++;
	}
	free_array(str);
}

void	ft_echo(t_organize *program)
{
	int			n;
	char	*str;

	str = program->args;
	n = 0;
	if (ft_strncmp(str, "-n", 2) == 0)
		n = 1;
	printf("Chegamos aqui\n");
	print_args(str);
	if (n == 0)
		write(1, "\n", 1);
}

int	mini_loop(t_program *mini)
{
	t_organize	*program; //criado inicio

	program = NULL; //criado fim
	while (mini->loop == 0)
	{
		if (parseline(mini))
			continue ;
		mini->pipes = pipes_counter(mini->user_input);
		printf("pipes: %d\n", mini->pipes);
		printf("mini->user_input: %s\n", mini->user_input);
		program = init_organize(mini);
		parse_input(mini, program);
		if (ft_strncmp(mini->user_input, "echo", 4) == 0)
			ft_echo(program);
//		else if (ft_strncmp(mini->user_input, "cd", 2) == 0)
//			ft_cd(mini, program);
//		else if (ft_strncmp(mini->user_input, "pwd", 3) == 0)
//			ft_pwd();
//		else if (ft_strncmp(mini->user_input, "export", 6) == 0)
//			ft_export(mini, program);
//		else if (ft_strncmp(mini->user_input, "unset", 5) == 0)
//			ft_unset(mini, program);
//		else if (ft_strncmp(mini->user_input, "env", 3) == 0)
//			ft_env(mini, program);
		if (ft_strncmp(mini->user_input, "exit", 4) == 0)
		{
			free_organize(program);
			break ;
		}
		free_organize(program);
		free(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
