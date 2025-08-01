/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <tayoub@@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:43:24 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/08/01 18:58:59 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycasting(int x, t_ray *ray, t_player *pl)
{
	init_ray(ray);
	ray->camera_x = 2.5 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = pl->dir_x + pl->plane_x * ray->camera_x;
	ray->dir_y = pl->dir_y + pl->plane_y * ray->camera_x;
	ray->map_x = (int)pl->pos_x;
	ray->map_y = (int)pl->pos_y;
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void	set_dda(t_ray *ray, t_player *pl)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (pl->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - pl->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (pl->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - pl->pos_y) * ray->deltadist_y;
	}
}

static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->mapinfo.height - 0.25
			|| ray->map_x > data->mapinfo.width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(data->win_height / ray->perpwalldist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perpwalldist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->perpwalldist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycasting(t_player *pl, t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = data->ray;
	while (x < data->win_width)
	{
		init_raycasting(x, &ray, pl);
		set_dda(&ray, pl);
		perform_dda(data, &ray);
		calculate_line_height(&ray, data, pl);
		update_texture_pixels(data, &data->texinfo, &ray, x);
		x++;
	}
	return (SUCCESS);
}
