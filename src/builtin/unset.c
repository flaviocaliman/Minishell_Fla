/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:35:08 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/09 14:51:43 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Esta função é responsável por remover uma variável de ambiente da
lista encadeada de variáveis de ambiente:
1. Verifica se o número de argumentos é diferente de 2.
2. Encontra o nó da variável de ambiente a ser removida.
3. Se o nó não for encontrado, exibe uma mensagem de erro.
4. Remove o nó da lista encadeada.
5. Libera a memória associada ao nó removido.
6. "unset with NO OPTIONS"
*/
void ft_unset(t_program *pgr, char **line)
{
    if (line_len(line) != 2) {
        return error(ERROR_UNSET_ARGS, NULL, 1);
    }

    t_envp *node_to_remove = find_envp_node(line[1], pgr->envp);
    if (node_to_remove == NULL)
        return error(ERROR_UNSET_VAR, line[1], 1);
    remove_envp_node(&(pgr->envp), node_to_remove);
}