/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:32:58 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/17 23:54:18 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(t_data *data, char **file, int i)
{
	int	index_value;
	int	j;

	index_value = i;
	while (file[i])
	{
		j = 0;
		while (white_spc(file[i][j]))
			j++;
		if (!ft_strchr("10NNSEW", file[i][j]))
			break ;
		i++;
	}
	data->mapinfo.index_end_of_map = i;
	return (i - index_value);
}

static int	fill_map_arr(t_mapinfo *mapinfo, char **map_arr, int index)
{
	int	i;
	int	j;

	mapinfo->width = find_largest_len(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map_arr[i] = malloc(sizeof(char) * (mapinfo->width + 1));
		if (!map_arr[i])
			return (err_msg(NULL, "Cannot allocate memory", FAILURE));
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map_arr[i][j] = mapinfo->file[index][j];
			j++;
		}
		while (j < mapinfo->width)
			map_arr[i][j++] = '\0';
		i++;
		index++;
	}
	map_arr[i] = NULL;
	return (SUCCESS);
}

static int	get_map(t_data *data, char **file, int i)
{
	data->mapinfo.height = count_lines(data, file, i);
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (err_msg(NULL, "Cannot allocate memory", FAILURE));
	if (fill_map_arr(&data->mapinfo, data->map, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	change_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (j < data->mapinfo.width - 1)
		{
			if ((white_spc(data->map[i][j]) || (data->map[i][j] == '\0')))
				data->map[i][j] = '2';
			j++;
		}
		i++;
	}
}

int	create_map(t_data *data, char **file, int index)
{
	int	i;
	int	j;

	if (get_map(data, file, index) == FAILURE)
		return (FAILURE);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!(ft_strchr("10NSEW", data->map[i][j]))
				&& !white_spc(data->map[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	change_spaces(data);
	return (SUCCESS);
}
