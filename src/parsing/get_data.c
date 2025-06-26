/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:42:07 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/06/27 01:54:52 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_tex_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	fill_dir_tex(t_texinfo *tex, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (2);
	if (line[j] == 'N' && line[j + 1] == 'O' && !tex->north)
		tex->north = get_tex_path(line, j + 2);
	if (line[j] == 'S' && line[j + 1] == 'O' && !tex->south)
		tex->north = get_tex_path(line, j + 2);
	if (line[j] == 'W' && line[j + 1] == 'E' && !tex->west)
		tex->north = get_tex_path(line, j + 2);
	if (line[j] == 'E' && line[j + 1] == 'A' && !tex->east)
		tex->north = get_tex_path(line, j + 2);
	else
		return (2);
	return (0);
}