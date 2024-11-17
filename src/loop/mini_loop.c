/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:15 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/17 19:45:39 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

#include "minishell.h"

t_env	*new_env_node_with_content(char *content)
{
    t_env	*new;

    new = new_env_node();
    new->content = ft_strdup(content);
    return (new);
}

void	sort_env_array(char **env_array, int count)
{
    int		i;
    int		j;
    char	*temp;

    i = 0;
    while (i < count - 1)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (ft_strcmp(env_array[j], env_array[j + 1]) > 0)
            {
                temp = env_array[j];
                env_array[j] = env_array[j + 1];
                env_array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void	print_sorted_env_list(t_env *env_list)
{
    t_env	*tmp;
    char	**env_array;
    int		count;
    int		i;

    count = 0;
    tmp = env_list;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }

    env_array = (char **)malloc(sizeof(char *) * (count + 1));
    if (!env_array)
        return ;

    i = 0;
    tmp = env_list;
    while (tmp)
    {
        env_array[i++] = tmp->content;
        tmp = tmp->next;
    }
    env_array[i] = NULL;

    sort_env_array(env_array, count);

    i = 0;
    while (env_array[i])
    {
        char *equal_sign = ft_strchr(env_array[i], '=');
        if (equal_sign)
        {
            *equal_sign = '\0';
            ft_printf("declare -x %s=\"%s\"\n", env_array[i], equal_sign + 1);
            *equal_sign = '=';
        }
        else
        {
            ft_printf("declare -x %s\n", env_array[i]);
        }
        i++;
    }

    free(env_array);
}

void	ft_export(t_program *mini)
{
    t_env	*new;
    t_env	*tmp;
    char	*var;
    char	**args;
    int		i;

    args = ft_split(mini->user_input, ' ');
    if (args[1] == NULL)
    {
        print_sorted_env_list(mini->export_list);
        free_array(args);
        return ;
    }
    i = 1;
    while (args[i])
    {
        var = ft_strdup(args[i]);
        new = new_env_node();
        new->content = var;
        if (ft_strchr(var, '='))
        {
            tmp = mini->export_list;
            while (tmp)
            {
                if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
                {
                    free(var);
                    break ;
                }
                tmp = tmp->next;
            }
            if (!tmp)
                add_env_node(mini->export_list, new);

            tmp = mini->env_list;
            while (tmp)
            {
                if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
                {
                    free(var);
                    break ;
                }
                tmp = tmp->next;
            }
            if (!tmp)
                add_env_node(mini->env_list, new_env_node_with_content(var));
        }
        else
        {
            tmp = mini->export_list;
            while (tmp)
            {
                if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
                {
                    free(var);
                    break ;
                }
                tmp = tmp->next;
            }
            if (!tmp)
                add_env_node(mini->export_list, new);
            else
                free(var);
        }
        i++;
    }
    free_array(args);
}
*/

#include "minishell.h"

t_env	*new_env_node_with_content(char *content)
{
    t_env	*new;

    new = new_env_node();
    new->content = ft_strdup(content);
    return (new);
}

void	sort_env_array(char **env_array, int count)
{
    int		i;
    int		j;
    char	*temp;

    i = 0;
    while (i < count - 1)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (ft_strcmp(env_array[j], env_array[j + 1]) > 0)
            {
                temp = env_array[j];
                env_array[j] = env_array[j + 1];
                env_array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int	count_env_list(t_env *env_list)
{
    int		count;
    t_env	*tmp;

    count = 0;
    tmp = env_list;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

char	**create_env_array(t_env *env_list, int count)
{
    char	**env_array;
    t_env	*tmp;
    int		i;

    env_array = (char **)malloc(sizeof(char *) * (count + 1));
    if (!env_array)
        return (NULL);

    i = 0;
    tmp = env_list;
    while (tmp)
    {
        env_array[i++] = tmp->content;
        tmp = tmp->next;
    }
    env_array[i] = NULL;
    return (env_array);
}

void	print_env_array(char **env_array)
{
    int		i;
    char	*equal_sign;

    i = 0;
    while (env_array[i])
    {
        equal_sign = ft_strchr(env_array[i], '=');
        if (equal_sign)
        {
            *equal_sign = '\0';
            ft_printf("declare -x %s=\"%s\"\n", env_array[i], equal_sign + 1);
            *equal_sign = '=';
        }
        else
        {
            ft_printf("declare -x %s\n", env_array[i]);
        }
        i++;
    }
}

void	print_sorted_env_list(t_env *env_list)
{
    int		count;
    char	**env_array;

    count = count_env_list(env_list);
    env_array = create_env_array(env_list, count);
    if (!env_array)
        return ;

    sort_env_array(env_array, count);
    print_env_array(env_array);
    free(env_array);
}

void	add_to_export_list(t_program *mini, char *var)
{
    t_env	*new;
    t_env	*tmp;

    new = new_env_node();
    new->content = var;
    tmp = mini->export_list;
    while (tmp)
    {
        if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
        {
            free(var);
            return;
        }
        tmp = tmp->next;
    }
    add_env_node(mini->export_list, new);
}

void	add_to_env_list(t_program *mini, char *var)
{
    t_env	*tmp;

    tmp = mini->env_list;
    while (tmp)
    {
        if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
        {
            free(var);
            return;
        }
        tmp = tmp->next;
    }
    add_env_node(mini->env_list, new_env_node_with_content(var));
}

void	ft_export(t_program *mini, char *str)
{
    char	**args;
    int		i;
    char	*var;

    args = ft_split(str, ' ');
    if (args[1] == NULL)
    {
        print_sorted_env_list(mini->export_list);
        free_array(args);
        return ;
    }
    i = 1;
    while (args[i])
    {
        var = ft_strdup(args[i]);
        if (ft_strchr(var, '='))
        {
            add_to_export_list(mini, var);
            add_to_env_list(mini, var);
        }
        else
            add_to_export_list(mini, var);
        i++;
    }
    free_array(args);
}

int	mini_loop(t_program *mini)
{
	t_organize	*program;

	program = NULL;
	while (mini->loop == 0)
	{
		if (parseline(mini))
			continue ;
		mini->pipes = pipes_counter(mini->user_input);
		printf("pipes: %d\n", mini->pipes);
		program = init_organize(mini);
		parse_input(mini, program);
		if (ft_strncmp(mini->user_input, "echo", 4) == 0)
			ft_echo(program);
//		else if (ft_strncmp(mini->user_input, "cd", 2) == 0)
//			ft_cd(mini, program);
		else if (ft_strncmp(mini->user_input, "pwd", 3) == 0)
			ft_pwd(program);
		else if (ft_strncmp(mini->user_input, "export", 6) == 0)
			ft_export(mini);
		else if (ft_strncmp(mini->user_input, "unset", 5) == 0)
			ft_unset(mini, program);
		else if (ft_strncmp(mini->user_input, "env", 3) == 0)
			ft_env(mini, program);
		else if (ft_strncmp(mini->user_input, "exit", 4) == 0)
		{
			if (ft_exit(program, mini->user_input) == EXIT_SUCCESS)
				break ;
		}
		free_organize(program);
		free(mini->user_input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
/*
int is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		return (1);
	else
		return (0);
}

int exec_builtin(t_program *mini, char *cmds, char *args)
{
	if (ft_strncmp(cmds, "echo", 4) == 0)
		ft_echo(args);
	else if (ft_strncmp(cmds, "cd", 2) == 0)
		ft_cd(args);
	else if (ft_strncmp(cmds, "pwd", 3) == 0)
		ft_pwd(args);
	else if (ft_strncmp(cmds, "export", 6) == 0)
		ft_export(mini, args);
	else if (ft_strncmp(cmds, "unset", 5) == 0)
		ft_unset(mini, args);
	else if (ft_strncmp(cmds, "env", 3) == 0)
		ft_env(mini, args);
	else if (ft_strncmp(cmds, "exit", 4) == 0)
	{
		if (ft_exit(args, cmds) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void executor(t_program *mini){
	t_organize	*program;
	program = NULL;
	
	while (program->next)
	{
		if (is_builtin(program->cmds) == 1)
			exec_builtin(program->cmds, program->args, mini);
		else
			//executa execve
		program = program->next;
	}
}
*/