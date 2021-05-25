/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:42:03 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:23:13 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_args(void)
{
	g_win.height = 0;
	g_win.width = 0;
	g_args.floor_r = 0;
	g_args.floor_g = 0;
	g_args.floor_b = 0;
	g_args.ceil_r = 0;
	g_args.ceil_g = 0;
	g_args.ceil_b = 0;
	g_args.no = NULL;
	g_args.we = NULL;
	g_args.ea = NULL;
	g_args.so = NULL;
	g_args.sprite = NULL;
}

void	init_counts(void)
{
	g_counts.i = 0;
	g_counts.j = 0;
	g_counts.k = 0;
	g_counts.l = 0;
	g_counts.m = 0;
	g_counts.n = 0;
	g_counts.p = 0;
	g_counts.t = 0;
}

int		help_res(char *line, int j)
{
	g_args.i = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) && g_args.i == 0)
		{
			g_win.width = ft_atoi(line + j) > MAX_W || ft_atoi(line + j) < 0 ?
			MAX_W : ft_atoi(line + j);
			g_args.i++;
			j += num_lenght(line + j);
		}
		else if (ft_isdigit(line[j]) && g_args.i == 1)
		{
			g_win.height = ft_atoi(line + j) > MAX_H || ft_atoi(line + j) < 0 ?
			MAX_H : ft_atoi(line + j);
			g_args.i++;
			j += num_lenght(line + j);
		}
		else if (ft_isdigit(line[j]) && g_args.i == 2)
		{
			g_args.i++;
			break ;
		}
	}
	return (g_args.i);
}

int		num_lenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		if (str[i] == ',')
			break ;
		if (str[i] == ' ' || str[i] == '\t')
		{
			i++;
			if (ft_isdigit(str[i]))
				return (i);
		}
	}
	return (i);
}
