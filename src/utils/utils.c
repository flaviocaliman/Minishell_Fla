/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:38:37 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/12 23:44:08 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_token(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, original_size);
		free(ptr);
	}
	return (new_ptr);
}

char	*ft_strndup(const char *s, size_t size)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (size > ft_strlen(s))
		len = ft_strlen(s);
	else
		len = size;
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = ((char *)s)[i];
		i++;
	}
	str[i] = 0;
	return (str);
}