/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:16:31 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/07 17:16:50 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned long	itohex(int	*rgb_arr)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_arr[0];
	g = rgb_arr[1];
	b = rgb_arr[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	check_tex(t_data *data, t_texinfo *tex)
{
	if (!tex->north || !tex->south || !tex->east || !tex->west)
		return (err_msg(data->mapinfo.path, "Missing texture(s)", FAILURE));
	if (!tex->floor || !tex->ceiling)
		return (err_msg(data->mapinfo.path, "Missing floor/ceiling color", FAILURE));
	if (val_file(tex->north, false) == FAILURE
		|| val_file(tex->south, false) == FAILURE
		|| val_file(tex->west, false) == FAILURE
		|| val_file(tex->east, false) == FAILURE)
		return (FAILURE);
	tex->hex_floor = itohex(tex->floor);
	tex->hex_ceiling = itohex(tex->ceiling);
	return (SUCCESS);
}