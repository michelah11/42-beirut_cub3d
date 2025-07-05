/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:55:49 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/05 19:28:19 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	white_spc(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

size_t	find_largest_len(t_mapinfo *map, int i)
{
	size_t	max_len;
	size_t	len;

	max_len = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		len = ft_strlen(map->file[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}
