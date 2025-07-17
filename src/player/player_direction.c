/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:21:01 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/18 00:10:11 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_n_dir(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
	return ;
}

static void	init_player_s_dir(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
	return ;
}

static void	init_player_w_dir(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
	return ;
}

static void	init_player_e_dir(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return ;
}

void	init_player_direction(t_data *data)
{
	if (data->player.dir == 'N')
		init_player_n_dir(&data->player);
	else if (data->player.dir == 'S')
		init_player_s_dir(&data->player);
	else if (data->player.dir == 'W')
		init_player_w_dir(&data->player);
	else if (data->player.dir == 'E')
		init_player_e_dir(&data->player);
	return ;
}
