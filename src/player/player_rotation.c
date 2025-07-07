/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:38:36 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/07 18:46:17 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void apply_rotation(t_data *data, double speed)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &data->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = old_dir_x * sin(speed) + p->dir_y * cos(speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
	p->plane_y = old_plane_x * sin(speed) + p->plane_y * cos(speed);
	return ;
}

int	rotate(t_data *data, double rotdir)
{
	double	speed;

	speed = ROTSPEED * rotdir;
	apply_rotation(data, speed);
	return (1);
}
