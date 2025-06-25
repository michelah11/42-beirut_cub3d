/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:34:30 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/06/26 00:38:58 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_nb_lines(const char *arg)
{
	int		fd;
	int		count;
	char	*line;

	if (!arg)
		return (err_msg("Argument", "is NULL", 1));
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (err_msg(arg, strerror(errno), 1));
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}