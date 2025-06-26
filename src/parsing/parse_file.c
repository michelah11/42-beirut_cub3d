/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:34:30 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/06/27 01:31:36 by mabou-ha         ###   ########.fr       */
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

static void	fill_tab(int row, int col, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->mapinfo.fd);
	while (line != NULL)
	{
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapinfo.file[row])
		{
			err_msg(NULL, "Could not allocate memory", 0);
			return (free_tab((void **)data->mapinfo.file));
		}
		while (line[i] != '\0')
			data->mapinfo.file[row][col++] = line[i++];
		data->mapinfo.file[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(data->mapinfo.fd);
	}
	data->mapinfo.file[row] = NULL;
}

void	parse_data(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	data->mapinfo.line_count = get_nb_lines(path);
	data->mapinfo.path = path;
	data->mapinfo.file = ft_calloc(data->mapinfo.line_count + 1, size_of(char *));
	if (!(data->mapinfo.file))
	{
		err_msg(NULL, "Could not allocate memory", 0);
		return ;
	}
	data->mapinfo.fd = open(path, O_RDONLY);
	if (data->mapinfo.fd < 0)
		err_msg(path, strerror(errno), 1);
	else
	{
		fill_tab(row, col, i, data);
		close(data->mapinfo.fd);
	}
}
