/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:39:34 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/05 21:10:03 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (val_file(av[1], true) == 1)
		clean_exit(data, 1);
	parse_data(av[1], data);
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data));
	return (0);
}
int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", "./cub3d <path/to/map.cub>" ,1));
	init_data(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	init_mlx(&data);
	init_textures(&data);
	print_data(&data);
	return (0);
}