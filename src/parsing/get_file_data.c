/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:28:44 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/11 01:01:13 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_end_file(t_mapinfo *mapinfo)
{
	int 	i;
	int		j;

	i = mapinfo->index_end_of_map;
	while (mapinfo->file[i])
	{
		j = 0;
		while (white_spc(mapinfo->file[i][j]))
			j++;
		if (ft_isprint(mapinfo->file[i][j]))
			return (FAILURE) ;
		i++;
	}
	return (SUCCESS);
}

static int	get_data(t_data *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j + 1]))
		{
			if (fill_dir_tex(&data->texinfo, map[i], j) == ERROR)
				return (err_msg(data->mapinfo.path, "Inv texture", FAILURE));
			return (BREAK);
		}
		else
		{
			if (fill_col_tex(data, &data->texinfo, map[i], j) == ERROR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(data, map, i) == 1)
			return (err_msg(data->mapinfo.path, "Map description is wrong", 1));
		if (check_end_file(&data->mapinfo) == FAILURE)
			return (err_msg(data->mapinfo.path, "Map is not the last elem", 1));
		return (0);
	}
	return (4);
}

int	get_file_data(t_data *data, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = get_data(data, map, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == FAILURE)
				return (FAILURE);
			else if (ret == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
