/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:43:55 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 11:10:53 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
		error_args(ARG);
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
			error_args(MAP);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save\0", 7) != 0)
			error_args(SAVE);
		if (ft_strncmp(argv[2], "--save\0", 7) == 0)
			g_save = 1;
	}
}

int		main(int argc, char **argv)
{
	int		fd1;
	char	*line;
	t_mlx	mlx;

	g_part1 = 0;
	g_part2 = 0;
	g_count_args = 0;
	g_map_height = 0;
	g_save = 0;
	g_p.count = 0;
	init_counts();
	check_args(argc, argv);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		perror("Error \n");
	init_args();
	read_file(fd1, line);
	init_map();
	initialise_window(&mlx);
	init_textures(&mlx);
	draw_map();
	init_sprite(&mlx);
	mlx_loop_hook(mlx.mlx, &update, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
