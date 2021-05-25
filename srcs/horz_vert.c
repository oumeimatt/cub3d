/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_vert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:23:22 by oel-yous          #+#    #+#             */
/*   Updated: 2021/02/07 18:49:17 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalise_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	init_horz(float rayangle, t_all *all)
{
	all->fnd_hrzwallhits = 0;
	all->yintercept = floor(g_p.y / TS) * TS;
	all->yintercept += all->is_raydown ? TS : 0;
	all->xintercept = g_p.x - (g_p.y - all->yintercept) / tan(rayangle);
	all->ystep = TS;
	all->ystep *= all->is_rayup ? -1 : 1;
	all->xstep = all->ystep / tan(rayangle);
	all->xstep *= (all->is_rayleft && all->xstep > 0) ? -1 : 1;
	all->xstep *= (all->is_rayright && all->xstep < 0) ? -1 : 1;
	all->nxthrztchx = all->xintercept;
	all->nxthrztchy = all->yintercept;
}

void	cast_horz(float rayangle, t_all *all)
{
	init_horz(rayangle, all);
	while (all->nxthrztchx >= 0 && all->nxthrztchx < g_map_width * TS
	&& all->nxthrztchy >= 0 && all->nxthrztchy < g_map_height * TS)
	{
		all->xcheck = all->nxthrztchx;
		all->ycheck = all->nxthrztchy + (all->is_rayup ? -1 : 0);
		if (is_wall(all->xcheck, all->ycheck) == 1)
		{
			all->fnd_hrzwallhits = 1;
			all->hrzhitx = all->nxthrztchx;
			all->hrzhity = all->nxthrztchy;
			break ;
		}
		else
		{
			all->nxthrztchx += all->xstep;
			all->nxthrztchy += all->ystep;
		}
	}
}

void	init_vert(float rayangle, t_all *all)
{
	all->fnd_vrtwallhits = 0;
	all->xintercept = floor(g_p.x / TS) * TS;
	all->xintercept += all->is_rayright ? TS : 0;
	all->yintercept = g_p.y - (g_p.x - all->xintercept) * tan(rayangle);
	all->xstep = TS;
	all->xstep *= all->is_rayleft ? -1 : 1;
	all->ystep = all->xstep * tan(rayangle);
	all->ystep *= (all->is_rayup && all->ystep > 0) ? -1 : 1;
	all->ystep *= (all->is_raydown && all->ystep < 0) ? -1 : 1;
	all->nxtvrttchx = all->xintercept;
	all->nxtvrttchy = all->yintercept;
}

void	cast_vert(float rayangle, t_all *all)
{
	init_vert(rayangle, all);
	while (all->nxtvrttchx >= 0 && all->nxtvrttchx < g_map_width * TS
	&& all->nxtvrttchy >= 0 && all->nxtvrttchy < g_map_height * TS)
	{
		all->xcheck = all->nxtvrttchx + (all->is_rayleft ? -1 : 0);
		all->ycheck = all->nxtvrttchy;
		if (is_wall(all->xcheck, all->ycheck) == 1)
		{
			all->fnd_vrtwallhits = 1;
			all->vrthitx = all->nxtvrttchx;
			all->vrthity = all->nxtvrttchy;
			break ;
		}
		else
		{
			all->nxtvrttchx += all->xstep;
			all->nxtvrttchy += all->ystep;
		}
	}
}
