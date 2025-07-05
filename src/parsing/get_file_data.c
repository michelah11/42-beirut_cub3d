/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:28:44 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/05 22:26:42 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			{
				return (err_msg(data->mapinfo.path, "Invalid texture(s)", FAILURE));
			}
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
