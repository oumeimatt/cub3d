/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:15:19 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 11:27:11 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_map_line(char *line)
{
	int i;

	if (line[0] != '1' && line[0] != ' ')
		ft_error2(5);
	return (-1);
}

void	error_map(char *line)
{
	if (surrounder_by_walls(line) != 0)
		ft_error(5);
}

void	init_map(void)
{
	g_player = 0;
	g_map_width = 0;
	check_map_close();
}

int		surrounder_by_walls(char *line)
{
	while (*line)
	{
		if (line[0] != '1' && line[0] != ' ')
			ft_error(6);
		if (*line == ' ')
			line++;
		if (*line == '\0' && g_part1 == 3)
			return (0);
		if (*line == '1')
			return (0);
		else if (line[0] == 'N' || line[0] == 'S' ||
		line[0] == 'E' || line[0] == 'W' ||
		line[0] == '0' || line[0] == '2')
			ft_error2(7);
	}
	return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	g_map_height++;
	return (dest);
}
