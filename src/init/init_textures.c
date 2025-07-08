/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:10:36 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/09 01:25:06 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof(int) * data->texinfo.size * data->texinfo.size);
	if (!buffer)
		clean_cub3d(data, err_msg(NULL, "Could not allocate memory", 1));
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x]
				= tmp.addr[y * data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_cub3d(data, err_msg(NULL, "Could not allocate memory", 1));
	data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
	data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
	data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
}

void	init_texinfo(t_texinfo *tex)
{
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->floor = 0;
	tex->ceiling = 0;
	tex->hex_floor = 0x0;
	tex->hex_ceiling = 0x0;
	tex->size = TEX_SIZE;
	tex->index = 0;
	tex->step = 0.0;
	tex->pos = 0.0;
	tex->x = 0;
	tex->y = 0;
}
