/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:13:07 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 11:22:21 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_close(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_map_height)
	{
		j = 0;
		error_map(g_map[i]);
		while (g_map[i][j])
		{
			handle_error(i, j);
			j++;
			if (j > g_map_width)
				g_map_width = j;
		}
		i++;
	}
	is_player();
}

void	handle_error(int i, int j)
{
	if (g_map[0][j] == 'N' || g_map[0][j] == 'S' ||
		g_map[0][j] == 'E' || g_map[0][j] == 'W' ||
		g_map[0][j] == '0' || g_map[0][j] == '2')
		ft_error(7);
	if (g_map[i][j] == 'N' || g_map[i][j] == 'S' ||
		g_map[i][j] == 'E' || g_map[i][j] == 'W' ||
		g_map[i][j] == '0' || g_map[i][j] == '2')
	{
		if (g_map[i - 1][j] == ' ' || g_map[i][j - 1] == ' '
		|| g_map[i][j + 1] == ' ' || g_map[i + 1][j] == ' '
		|| g_map[i - 1][j] == '\0' || g_map[i][j + 1] == '\0'
		|| g_map[i + 1][j] == '\0')
			ft_error(7);
	}
	if (g_map[i][j] != 'N' && g_map[i][j] != 'S' &&
		g_map[i][j] != 'E' && g_map[i][j] != 'W' &&
		g_map[i][j] != '0' && g_map[i][j] != '2' &&
		g_map[i][j] != '1' && g_map[i][j] != ' ' &&
		g_map[i][j] != '\0')
		ft_error(6);
}

void	is_player(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'E' ||
			g_map[i][j] == 'S' || g_map[i][j] == 'W')
				g_player++;
			j++;
		}
		i++;
	}
	if (g_player != 1)
		ft_error(6);
}

int		valid_line(char *line)
{
	while (*line)
	{
		if (*line == ' ')
			line++;
		else if (*line == '1')
			return (0);
		else
			ft_error2(6);
	}
	return (1);
}

int		first_line(char *line)
{
	if (line[0] == '\0' && g_part2 == 0)
		return (0);
	if (line[0] == '1' || (line[0] == ' ' && !valid_line(line)))
	{
		g_part1 = 3;
		g_part2 = 1;
		return (0);
	}
	if (g_part1 == 3 && line[0] == '\0')
		return (-1);
	return (-1);
}
