/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:28:44 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/17 23:23:06 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_end(t_mapinfo *mapinfo)
{
	int		i;
	int		j;

	i = mapinfo->index_end_of_map;
	while (mapinfo->file[i])
	{
		j = 0;
		while (white_spc(mapinfo->file[i][j]))
			j++;
		if (ft_isprint(mapinfo->file[i][j]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	check_mapend(t_data *data, char **map, int i)
{
	if (create_map(data, map, i) == 1)
		return (err_msg(data->mapinfo.path, "Wrong map", 1));
	if (check_end(&data->mapinfo) == 1)
		return (err_msg(data->mapinfo.path, "map not last elem", 1));
	return (0);
}

static int	get_data(t_data *data, char **arr, int i, int j)
{
	while (arr[i][j] == ' ' || arr[i][j] == '\t' || arr[i][j] == '\n')
		j++;
	if (ft_isprint(arr[i][j]) && !ft_isdigit(arr[i][j]))
	{
		if (arr[i][j + 1] && ft_isprint(arr[i][j + 1])
			&& !ft_isdigit(arr[i][j + 1]))
		{
			if (fill_dir_tex(&data->texinfo, arr[i], j) == ERROR)
				return (err_msg(data->mapinfo.path, "Inv texture", FAILURE));
			return (BREAK);
		}
		else
		{
			if (fill_col_tex(data, &data->texinfo, arr[i], j) == ERROR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(arr[i][j]))
		return (check_mapend(data, arr, i));
	return (4);
}

int	get_file_data(t_data *data, char **arr)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			ret = get_data(data, arr, i, j);
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
