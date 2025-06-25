/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:54:24 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/06/26 00:31:58 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_dir(char *arg)
{
	int	fd;

	fd = open(arg, O_DIR);
	if (fd)
	{
		close(fd);
		return (true);
	}
	return (false);
}

static bool	check_file_format(char *arg, bool cub_file)
{
	size_t	len;

	if (!arg)
		return (false);
	len = ft_strlen(arg);
	if (len < 4)
		return (false);
	if (cub_file)
		return (ft_strcmp(arg + len - 4, ".cub") == 0);
	else
		return (ft_strcmp(arg + len - 4, ".xpm") == 0);

}

int	val_file(char *arg, bool cub_file)
{
	int	fd;

	if (!arg)
		return (err_msg("Argument", "is null", 1));
	if (check_dir(arg))
		return (err_msg(arg, "is a directory", 1));
	fd = open(arg, O_RDONLY);
	if (!check_file_format(arg, cub_file))
	{
		if (cub_file)
			return (err_msg(arg, "is not a .cub file", 1));
		else
			return (err_msg(arg, "is not a .xpm file", 1));
	}
	// if (fd < 0)
	// 	return (err_msg(arg, strerror(errno), 1));
	// close(fd);
	return (0);
}


