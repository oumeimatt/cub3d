/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:26:57 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 10:27:04 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		invld_line_cf(char *line)
{
	while (*line)
	{
		if (*line != ',' && !ft_isdigit(*line))
			return (-1);
		line++;
	}
	return (1);
}

int		invld_line_res(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ')
			return (-1);
		line++;
	}
	return (1);
}

int		skip_comma(char *line)
{
	int count_comma;

	count_comma = 0;
	while (*line)
	{
		if (*line == ',')
			count_comma++;
		line++;
	}
	return (count_comma);
}

int		ft_map_args(char *line)
{
	if (check_resolution(line) == 2)
	{
		g_counts.i++;
		g_count_args += g_counts.i;
	}
	if (check_no_tex(line) == 0)
	{
		g_counts.j++;
		g_count_args += g_counts.j;
	}
	if (check_floor(line) == 0)
	{
		g_counts.k++;
		g_count_args += g_counts.k;
	}
	if (check_ceil(line) == 0)
	{
		g_counts.l++;
		g_count_args += g_counts.l;
	}
	check_map_args2(line);
	return (g_count_args);
}

int		check_map_args2(char *line)
{
	if (check_so_tex(line) == 0)
	{
		g_counts.m++;
		g_count_args += g_counts.m;
	}
	if (check_we_tex(line) == 0)
	{
		g_counts.n++;
		g_count_args += g_counts.n;
	}
	if (check_ea_tex(line) == 0)
	{
		g_counts.p++;
		g_count_args += g_counts.p;
	}
	if (check_sprite(line) == 0)
	{
		g_counts.t++;
		g_count_args += g_counts.t;
	}
	return (g_count_args);
}
