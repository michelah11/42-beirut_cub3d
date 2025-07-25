/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 01:18:01 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/01/13 01:21:32 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*msh_strtrim(char const *s1, char const *set, t_mem *mem)
{
	char	*str;
	size_t	s;
	size_t	e;
	size_t	i;

	s = 0;
	while (in_set(set, s1[s]) && s1[s] != '\0')
		s++;
	e = ft_strlen(s1);
	while (in_set(set, s1[e - 1]) && e > s)
		e--;
	str = (char *)msh_malloc(sizeof(*s1) * (e - s + 1), mem);
	if (!str)
		return (NULL);
	i = 0;
	while (s < e)
		str[i++] = s1[s++];
	str[i] = 0;
	return (str);
}
