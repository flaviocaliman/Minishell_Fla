/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:48:24 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/20 00:06:50 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, len);
	return (copy);
}
