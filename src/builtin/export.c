/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:32:32 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/11/16 22:49:16 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

