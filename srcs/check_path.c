/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:29:11 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 10:25:19 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_no_tex(char *line)
{
	int fd;

	if (ft_strncmp("NO ", line, 3) != 0)
		return (-1);
	g_args.no = ft_strtrim(line + 2, " ");
	fd = open(g_args.no, O_RDONLY);
	if (fd == -1)
	{
		free(g_args.no);
		return (-1);
	}
	return (0);
}

int		check_so_tex(char *line)
{
	int fd;

	if (ft_strncmp("SO ", line, 3) != 0)
		return (-1);
	g_args.so = ft_strtrim(line + 2, " ");
	fd = open(g_args.so, O_RDONLY);
	if (fd == -1)
	{
		free(g_args.so);
		return (-1);
	}
	return (0);
}

int		check_we_tex(char *line)
{
	int fd;

	if (ft_strncmp("WE ", line, 3) != 0)
		return (-1);
	g_args.we = ft_strtrim(line + 2, " ");
	fd = open(g_args.we, O_RDONLY);
	if (fd == -1)
	{
		free(g_args.we);
		return (-1);
	}
	return (0);
}

int		check_ea_tex(char *line)
{
	int fd;

	if (ft_strncmp("EA ", line, 3) != 0)
		return (-1);
	g_args.ea = ft_strtrim(line + 2, " ");
	fd = open(g_args.ea, O_RDONLY);
	if (fd == -1)
	{
		free(g_args.ea);
		return (-1);
	}
	return (0);
}

int		check_sprite(char *line)
{
	int fd;

	if (ft_strncmp("S ", line, 2) != 0)
		return (-1);
	g_args.sprite = ft_strtrim(line + 2, " ");
	fd = open(g_args.sprite, O_RDONLY);
	if (fd == -1)
	{
		free(g_args.sprite);
		return (-1);
	}
	return (0);
}
