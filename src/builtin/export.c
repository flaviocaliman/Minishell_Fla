/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:32:32 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/13 22:24:42 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função para listar as variáveis de ambiente exportadas.
void list_exp_var(t_program *pgr)
{
	t_envp *envp;

	envp = pgr->envp;
	
	while (envp)
	{
		if (envp->visible)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(envp->name, STDOUT_FILENO);
			if (envp->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(envp->value, STDOUT_FILENO);
				ft_putstr_fd("\"", STDOUT_FILENO);
			}
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		envp = envp->next;
	}
}

// Função para exportar uma variável de ambiente. Adiciona ou atualiza
// uma variável de ambiente na lista encadeada.
void env_export(t_program *pgr, char *name, char *value, int visible)
{
	t_envp *envp;
	
	envp = find_envp_node(name, pgr->envp);
	if (envp)
	{
		if (visible)
		{
			free(envp->value);
			envp->value = ft_strdup(value);
		}
	}
	else
	{
		envp = new_envp_node(name, value);
		add_envp_node(envp, pgr->envp);
	}
}

/*
O comando export é usado para:
1. Definir uma variável de ambiente: export VARIAVEL=valor
2. Marcar uma variável de ambiente para exportação
   para ambientes de processos filho: export VARIAVEL
3. Exibir todas as variáveis de ambiente exportadas: export

Quando você usa export, a variável especificada
é adicionada ao ambiente do shell e estará disponível para
qualquer processo iniciado a partir desse shell.
*/
void ft_export(t_program *pgr, char **line)
{
	int i = 1;
	char *name;
	char *value;
	char *equal_sign;
	
	if (line[1] == NULL)
    {
        list_exp_var(pgr);
        return;
    }
	while (line[i])
	{
		equal_sign = ft_strchr(line[i], '=');
		if (equal_sign)
		{
			name = ft_strndup(line[i], equal_sign - line[i]);
			value = ft_strdup(equal_sign + 1);
			env_export(pgr, name, value, 1);
			free(name);
			free(value);
		}
		else
			env_export(pgr, line[i], "", 1);
		i++;
	}
}