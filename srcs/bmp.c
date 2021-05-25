/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 08:19:33 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/08 09:22:04 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_initialize(t_bmp *bmp)
{
	int i;

	i = 0;
	bmp->bitcount = 32;
	bmp->imagesize = g_win.width * g_win.height * 4;
	bmp->bisize = 40;
	bmp->offsetbytes = 54;
	bmp->filesize = 54 + bmp->imagesize;
	bmp->bi_planes = 1;
	while (i < 54)
		bmp->header[i++] = 0;
	ft_memcpy(bmp->header, "BM", 2);
	ft_memcpy(bmp->header + 2, &bmp->filesize, 4);
	ft_memcpy(bmp->header + 10, &bmp->offsetbytes, 4);
	ft_memcpy(bmp->header + 14, &bmp->bisize, 4);
	ft_memcpy(bmp->header + 18, &g_win.width, 4);
	ft_memcpy(bmp->header + 22, &g_win.height, 4);
	ft_memcpy(bmp->header + 26, &bmp->bi_planes, 2);
	ft_memcpy(bmp->header + 28, &bmp->bitcount, 2);
	ft_memcpy(bmp->header + 34, &bmp->imagesize, 4);
}

void	ft_bmp(t_mlx *mlx)
{
	t_bmp	bmp;

	bmp_initialize(&bmp);
	bmp.i = 0;
	bmp.j = g_win.height - 1;
	g_sp = -1;
	while (++g_sp <= g_sptcount)
		ft_sprite(mlx);
	if ((bmp.fd = open("save.bmp", O_CREAT | O_RDWR, S_IRWXU)) < 0)
		ft_exit(mlx);
	write(bmp.fd, bmp.header, 54);
	while (bmp.j > -1)
	{
		bmp.i = 0;
		while (bmp.i < g_win.width)
		{
			bmp.pos = (bmp.i + g_win.width * bmp.j);
			bmp.pixel = (int *)(mlx->addr) + bmp.pos;
			write(bmp.fd, bmp.pixel, 4);
			bmp.i++;
		}
		bmp.j--;
	}
	close(bmp.fd);
	ft_exit(mlx);
}
