/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_col_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:28:03 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/10 23:18:38 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	non_numeric_char(char *str)
{
	int		i;

	i = 0;
	while (white_spc(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (white_spc(str[i]))
		i++;
	return (str[i] != '\0');
}

static int	*convert_colors(char **rgb_colors, int *rgb)
{
	int		i;

	i = 0;
	while (rgb_colors[i] != NULL)
	{
		if (non_numeric_char(rgb_colors[i]))
		{
			err_msg(NULL,
				"Numeric positive color components are acceptable", 0);
			free_arr((void **)rgb_colors);
			free(rgb);
			return (NULL);
		}
		rgb[i] = ft_atoi(rgb_colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			err_msg(NULL, "Color component out of 0–255 range", 0);
			free_arr((void **)rgb_colors);
			free(rgb);
			return (NULL);
		}
		i++;
	}
	free_arr((void **)rgb_colors);
	return (rgb);
}

static bool	check_w(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!white_spc(str[i++]))
			return (false);
	}
	return (true);
}

static int	*set_colors(char *line, char **rgb_split, int *rgb, int count)
{
	while (white_spc(*line))
		line++;
	rgb_split = ft_split(line, ',');
	if (!rgb_split)
	{
		err_msg(NULL, "Failed to split color line", 0);
		return (NULL);
	}
	count = 0;
	while (rgb_split[count] && !check_w(rgb_split[count]))
		count++;
	if (count != 3)
	{
		err_msg(NULL, "Expected exactly 3 color values", 0);
		free_arr((void **)rgb_split);
		return (NULL);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		err_msg(NULL, "Could not allocate memory", 0);
		free_arr((void **)rgb_split);
		return (NULL);
	}
	return (convert_colors(rgb_split, rgb));
}

int	fill_col_tex(t_data *data, t_texinfo *tex, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]) && white_spc(line[j + 1]))
		return (err_msg(data->mapinfo.path,
				"Invalid floor/ceiling colors", ERROR));
	if (!tex->ceiling && line[j] == 'C')
	{
		tex->ceiling = set_colors(line + j + 1, NULL, NULL, 0);
		if (tex->ceiling == 0)
			return (err_msg(data->mapinfo.path,
					"Invalid floor color", ERROR));
	}
	else if (!tex->floor && line[j] == 'F')
	{
		tex->floor = set_colors(line + j + 1, NULL, NULL, 0);
		if (tex->floor == 0)
			return (err_msg(data->mapinfo.path,
					"Invalid floor colors", ERROR));
	}
	return (SUCCESS);
}
