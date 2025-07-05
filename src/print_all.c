#include "cub3d.h"

static void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		int j = 0;
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
	/* Window */
	printf("Window size: %d × %d\n",
		d->win_width,
		d->win_height);

	/* MapInfo */
	printf("MapInfo:\n"
	       "  path:           %s\n"
	       "  fd:             %d\n"
	       "  line_count:     %d\n"
	       "  dimensions:     %d × %d\n"
	       "  index_end_map:  %d\n",
		d->mapinfo.path,
		d->mapinfo.fd,
		d->mapinfo.line_count,
		d->mapinfo.width,
		d->mapinfo.height,
		d->mapinfo.index_end_of_map);
	print_map(d->map);

	/* Player */
	printf("Player:\n"
	       "  dir char:       %c\n"
	       "  pos:            (%.3f, %.3f)\n"
	       "  dir vector:     (%.3f, %.3f)\n"
	       "  plane vector:   (%.3f, %.3f)\n"
	       "  moved:          %d\n"
	       "  move flags:     x=%d y=%d\n"
	       "  rotate flag:    %d\n",
		d->player.dir,
		d->player.pos_x,    d->player.pos_y,
		d->player.dir_x,    d->player.dir_y,
		d->player.plane_x,  d->player.plane_y,
		d->player.has_moved,
		d->player.move_x,   d->player.move_y,
		d->player.rotate);

	/* Ray */
	printf("Ray:\n"
	       "  cam_x:          %.3f\n"
	       "  dir:            (%.3f, %.3f)\n"
	       "  map cell:       (%d, %d)\n"
	       "  step:           (%d, %d)\n"
	       "  sideDist:       (%.3f, %.3f)\n"
	       "  deltaDist:      (%.3f, %.3f)\n"
	       "  wall_dist:      %.3f\n"
	       "  wall_x:         %.3f\n"
	       "  side hit:       %d\n"
	       "  draw line:      %d → %d (height %d)\n",
		d->ray.camera_x,
		d->ray.dir_x,       d->ray.dir_y,
		d->ray.map_x,       d->ray.map_y,
		d->ray.step_x,      d->ray.step_y,
		d->ray.sidedist_x,  d->ray.sidedist_y,
		d->ray.deltadist_x, d->ray.deltadist_y,
		d->ray.wall_dist,
		d->ray.wall_x,
		d->ray.side,
		d->ray.draw_start,  d->ray.draw_end,
		d->ray.line_height);

	/* Texture info */
	printf("TexInfo:\n"
	       "  North:          %s\n"
	       "  South:          %s\n"
	       "  West:           %s\n"
	       "  East:           %s\n"
	       "  hex_floor:      0x%lX\n"
	       "  hex_ceiling:    0x%lX\n"
	       "  size:           %d\n"
	       "  index:          %d\n"
	       "  step:           %.3f\n"
	       "  pos:            %.3f\n"
	       "  tex coord:      (%d, %d)\n",
		d->texinfo.north,
		d->texinfo.south,
		d->texinfo.west,
		d->texinfo.east,
		d->texinfo.hex_floor,
		d->texinfo.hex_ceiling,
		d->texinfo.size,
		d->texinfo.index,
		d->texinfo.step,
		d->texinfo.pos,
		d->texinfo.x,
		d->texinfo.y);
}
