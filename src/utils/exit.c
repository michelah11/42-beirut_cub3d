/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:55:55 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/10 21:43:55 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_disp(t_data *data)
{
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	return ;
}

void	clean_cub3d(t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->win && data->mlx)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
		destroy_disp(data);
	free_data(data);
	exit(code);
}

int	exit_cub3d(t_data *data)
{
	clean_cub3d(data, 0);
	return (0);
}
