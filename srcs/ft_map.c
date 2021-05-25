/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 10:45:13 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 10:26:37 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_maps_args(char *line)
{
	if (line[0] == 'R')
	{
		if (check_resolution(line) != 2)
			ft_error(3);
	}
	else if (line[0] == 'F')
	{
		if (check_floor(line) != 0)
			ft_error(1);
	}
	else if (line[0] == 'C')
	{
		if (check_ceil(line) != 0)
			ft_error(1);
	}
	else if (ft_strchr("NSWES", line[0]))
	{
		if (line[0] == 'S' && (line[1] == ' '))
		{
			if (check_sprite(line) != 0)
				ft_error2(2);
		}
		if (check_textures(line) != 1)
			ft_error(2);
	}
}

int		check_resolution(char *line)
{
	int i;
	int j;

	i = 0;
	if (ft_strncmp("R ", line, 2) != 0)
		return (-1);
	line = ft_strtrim(line + 1, " ");
	if (invld_line_res(line) != 1)
	{
		free(line);
		return (-1);
	}
	j = 0;
	i = help_res(line, j);
	if (g_win.width <= 0 || g_win.height <= 0)
		return (-1);
	return (i);
}

int		check_floor(char *line)
{
	int i;

	if (ft_strncmp("F ", line, 2) != 0)
		return (-1);
	line = ft_strtrim(line + 1, " ");
	i = 0;
	if (invld_line_cf(line) != 1)
	{
		return (-1);
		free(line);
	}
	g_args.floor_r = ft_atoi(line + i);
	i += num_lenght(line + i) + 1;
	g_args.floor_g = ft_atoi(line + i);
	i += num_lenght(line + i) + 1;
	g_args.floor_b = ft_atoi(line + i);
	i += num_lenght(line + i) + 1;
	if (g_args.floor_r > 255 || g_args.floor_g > 255 || g_args.floor_b > 255
	|| g_args.floor_r < 0 || g_args.floor_g < 0 || g_args.floor_b < 0)
		return (-1);
	if (skip_comma(line) != 2)
		return (-1);
	return (0);
}

int		check_ceil(char *line)
{
	int i;

	if (ft_strncmp("C ", line, 2) != 0)
		return (-1);
	line = ft_strtrim(line + 1, " ");
	i = 0;
	if (invld_line_cf(line) != 1)
	{
		free(line);
		return (-1);
	}
	g_args.ceil_r = ft_atoi(line + i);
	i += num_lenght(line + i) + 1;
	g_args.ceil_g = ft_atoi(line + i);
	i += num_lenght(line + i) + 1;
	g_args.ceil_b = ft_atoi(line + i);
	i += num_lenght(line + i) + 1;
	if (g_args.ceil_r > 255 || g_args.ceil_g > 255 || g_args.ceil_b > 255
	|| g_args.ceil_r < 0 || g_args.ceil_g < 0 || g_args.ceil_b < 0)
		return (-1);
	if (skip_comma(line) != 2)
		return (-1);
	return (0);
}

int		check_textures(char *line)
{
	if (line[0] == 'N')
	{
		if (check_no_tex(line) != 0)
			ft_error2(2);
	}
	if (line[0] == 'S' && line[1] == 'O')
	{
		if (check_so_tex(line) != 0)
			ft_error2(2);
	}
	if (line[0] == 'E')
	{
		if (check_ea_tex(line) != 0)
			ft_error2(2);
	}
	if (line[0] == 'W')
	{
		if (check_we_tex(line) != 0)
			ft_error2(2);
	}
	return (1);
}
