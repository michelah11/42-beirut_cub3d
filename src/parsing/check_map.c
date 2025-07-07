/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:29:37 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/07 17:15:22 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_closed_map(char **map_arr, int i, int j)
{
	int	r;
	int	c;

	if (ft_strchr("0NSEW", map_arr[i][j]))
	{
		r = i - 1;
		while (r <= i + 1)
		{
			c = j - 1;
			while (c <= j + 1 && c != j)
			{
				if (map_arr[r][c] == '2')
					return (FAILURE);
				c++;
			}
			r++;
		}
	}
	return (SUCCESS);
}

static int	check_map_elem(t_data *data, char **map_arr)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (!(ft_strchr("210NSEW", map_arr[i][j])))
				return (err_msg(data->mapinfo.path, "Invalid map characters", FAILURE));
			if (ft_strchr("NSEW", map_arr[i][j]) && data->player.dir != '0')
				return (err_msg(data->mapinfo.path, "More than one player", FAILURE));
			if (ft_strchr("NSEW", map_arr[i][j]) && data->player.dir == '0')
				data->player.dir = map_arr[i][j];
			if (check_closed_map(map_arr, i, j) == FAILURE)
				return ((err_msg(data->mapinfo.path, "Map walls not closed", FAILURE)));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_pl_pos(t_data *data, char **map_arr)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (err_msg(data->mapinfo.path, "No player found", FAILURE));
	i = 0;
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (ft_strchr("NSEW", map_arr[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_arr[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data, char **map_arr)
{
	if (!data->map)
		return (err_msg(data->mapinfo.path, "No map", FAILURE));
	if (check_map_borders(&data->mapinfo, map_arr) == FAILURE)
		return (FAILURE);
	if (data->mapinfo.height < 3)
		return (err_msg(data->mapinfo.path, "Height too small", FAILURE));
	if (check_map_elem(data, map_arr) == FAILURE)
		return (FAILURE);
	if (check_pl_pos(data, map_arr) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
