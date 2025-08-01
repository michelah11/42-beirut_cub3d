/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <tayoub@@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:39:34 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/08/01 18:59:10 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (val_file(av[1], true) == 1)
		clean_cub3d(data, 1);
	parse_data(av[1], data);
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data));
	if (check_map(data, data->map) == FAILURE)
		return (free_data(data));
	if (check_tex(data, &data->texinfo) == FAILURE)
		return (free_data(data));
	init_player_direction(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", "./cub3d <path/to/map.cub>", FAILURE));
	init_data(&data);
	if (parse_args(&data, av) != 0)
		return (FAILURE);
	init_mlx(&data);
	init_textures(&data);
	input_listener(&data);
	render_raycast(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (SUCCESS);
}
