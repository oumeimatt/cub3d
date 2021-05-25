/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:13:18 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 17:53:00 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	error_des(char *str)
{
	printf("Error \n %s", str);
	exit(0);
}

void	ft_error(int err)
{
	if (err == 0)
		error_des(ARG);
	if (err == 1)
		error_des(RGB);
	if (err == 2)
		error_des(INV_PATH);
	if (err == 3)
		error_des(RES);
	if (err == 4)
		error_des(ARGS);
	if (err == 5)
		error_des(INV_LINE);
	if (err == 6)
		error_des(INK_CHAR);
	if (err == 7)
		error_des(MAP_CLS);
	if (err == 8)
		error_des(NEW_LINE);
	if (err == 9)
		error_des(MAP);
	if (err == 10)
		error_des(SAVE);
}

int		ft_error2(int err)
{
	ft_error(err);
	return (-1);
}

void	error_args(char *str)
{
	printf("Error \n %s", str);
	exit(0);
}
