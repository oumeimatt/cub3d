/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:25:40 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:42:06 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_data(float rayangle, int i, t_all *all)
{
	all->hrzhitdis = (all->fnd_hrzwallhits == 1) ?
	dist_betweenpts(g_p.x, g_p.y, all->hrzhitx, all->hrzhity) : MAXINT;
	all->vrthitdis = (all->fnd_vrtwallhits == 1) ?
	dist_betweenpts(g_p.x, g_p.y, all->vrthitx, all->vrthity) : MAXINT;
	g_r[i].distance = (all->hrzhitdis < all->vrthitdis) ?
	all->hrzhitdis : all->vrthitdis;
	g_r[i].wallhitx = (all->hrzhitdis < all->vrthitdis) ?
	all->hrzhitx : all->vrthitx;
	g_r[i].wallhity = (all->hrzhitdis < all->vrthitdis) ?
	all->hrzhity : all->vrthity;
	g_r[i].washit_vertical = (all->vrthitdis < all->hrzhitdis) ? 1 : 0;
	g_r[i].ray_angle = rayangle;
	g_r[i].raydown = rayangle > 0 && rayangle < M_PI;
	g_r[i].rayup = !(rayangle > 0 && rayangle < M_PI);
	g_r[i].rayleft = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
	g_r[i].rayright = !(rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI);
}

void	castall_rays(void)
{
	float	rayangle;
	int		stripid;
	t_all	all;

	rayangle = (g_p.direction * (M_PI / 180)) - (FOV_ANGLE / 2);
	rayangle = normalise_angle(rayangle);
	stripid = 0;
	while (stripid < g_win.width)
	{
		all.is_raydown = rayangle > 0 && rayangle < M_PI;
		all.is_rayup = !all.is_raydown;
		all.is_rayright = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
		all.is_rayleft = !all.is_rayright;
		rayangle = normalise_angle(rayangle);
		cast_horz(rayangle, &all);
		cast_vert(rayangle, &all);
		store_data(rayangle, stripid, &all);
		rayangle += FOV_ANGLE / g_win.width;
		stripid++;
	}
}

float	dist_betweenpts(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	help_player(void)
{
	if (g_p.rightdirection == 1)
	{
		if (!(is_wall(g_p.x + cos((g_p.direction + 90) * (PI / 180)) * 10,
		g_p.y + sin((g_p.direction + 90) * (PI / 180)) * 10)))
		{
			g_p.y = g_p.y + sin((g_p.direction + 90) * (PI / 180)) * MVSPD;
			g_p.x = g_p.x + cos((g_p.direction + 90) * (PI / 180)) * MVSPD;
		}
	}
	if (g_p.leftdirection == 1)
	{
		if (!(is_wall(g_p.x - cos((g_p.direction + 90) * (PI / 180)) * 10,
		g_p.y - sin((g_p.direction + 90) * (PI / 180)) * 10)))
		{
			g_p.y = g_p.y - sin((g_p.direction + 90) * (PI / 180)) * MVSPD;
			g_p.x = g_p.x - cos((g_p.direction + 90) * (PI / 180)) * MVSPD;
		}
	}
	if (g_p.rightrangle == 1)
		g_p.direction += 3;
	if (g_p.leftrangle == 1)
		g_p.direction -= 3;
}
