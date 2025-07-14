/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:12:24 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/12 16:14:38 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_top_bot(char **map_arr, int i, int j)
{
	if (!map_arr || !map_arr[i] || !map_arr[i][j])
		return (FAILURE);
	while (map_arr[i][j])
	{
		if (!ft_strchr("12", map_arr[i][j]))
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	check_map_borders(t_mapinfo *map, char **map_arr)
{
	int	i;
	int	j;

	if (check_top_bot(map_arr, 0, 0) == FAILURE)
		return (err_msg(NULL, "Invalid map top border", FAILURE));
	i = 1;
	while (i < (map->height - 1) && *map_arr[i])
	{
		j = 0;
		while (map_arr[i][j] == '2')
			j++;
		if (map_arr[i][j] != '\0' && map_arr[i][j] != '1')
			return (err_msg(NULL, "Invalid map left borders", FAILURE));
		j = ft_strlen(map_arr[i]) - 1;
		while (map_arr[i][j] == '2')
			j--;
		if (map_arr[i][j] != '\0' && map_arr[i][j] != '1')
			return (err_msg(NULL, "Invalid map right borders", FAILURE));
		i++;
	}
	if (check_top_bot(map_arr, map->height - 1, 0) == FAILURE)
		return (err_msg(NULL, "Invalid map bottom border", FAILURE));
	return (SUCCESS);
}
