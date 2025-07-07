/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:33:41 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/07/07 16:46:57 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_data(const t_data *d)
{
	printf("Window size: %d × %d\n", d->win_width, d->win_height);
	printf("MapInfo:\npath:           %s\nfd:             %d\nline_count:     %d\ndimensions:     %d × %d\nindex_end_map:  %d\n",
		d->mapinfo.path, d->mapinfo.fd, d->mapinfo.line_count, d->mapinfo.width, d->mapinfo.height, d->mapinfo.index_end_of_map);
	print_map(d->map);
	printf("Player:\ndir char:       %c\npos:            (%.3f, %.3f)\ndir vector:     (%.3f, %.3f)\nplane vector:   (%.3f, %.3f)\nmoved:          %d\nmove flags:     x=%d y=%d\nrotate flag:    %d\n",
		d->player.dir, d->player.pos_x, d->player.pos_y, d->player.dir_x, d->player.dir_y, d->player.plane_x, d->player.plane_y, d->player.has_moved, d->player.move_x, d->player.move_y, d->player.rotate);
	printf("Ray:\ncam_x:          %.3f\ndir:            (%.3f, %.3f)\nmap cell:       (%d, %d)\nstep:           (%d, %d)\nsideDist:       (%.3f, %.3f)\ndeltaDist:      (%.3f, %.3f)\nwall_dist:      %.3f\nwall_x:         %.3f\nside hit:       %d\ndraw line:      %d → %d (height %d)\n",
		d->ray.camera_x, d->ray.dir_x, d->ray.dir_y, d->ray.map_x, d->ray.map_y, d->ray.step_x, d->ray.step_y, d->ray.sidedist_x, d->ray.sidedist_y,
		d->ray.deltadist_x, d->ray.deltadist_y, d->ray.wall_dist, d->ray.wall_x, d->ray.side, d->ray.draw_start, d->ray.draw_end, d->ray.line_height);
	printf("TexInfo:\nNorth:          %s\nSouth:          %s\nWest:           %s\nEast:           %s\nhex_floor:      0x%lX\nhex_ceiling:    0x%lX\nsize:           %d\nindex:          %d\nstep:           %.3f\npos:            %.3f\ntex coord:      (%d, %d)\n",
		d->texinfo.north, d->texinfo.south, d->texinfo.west, d->texinfo.east, d->texinfo.hex_floor, d->texinfo.hex_ceiling,
		d->texinfo.size, d->texinfo.index, d->texinfo.step, d->texinfo.pos, d->texinfo.x, d->texinfo.y);
}
