/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:31:41 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/14 17:31:43 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	g_cast_init(void)
{
	g_cast = (t_cast){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

void	horz_cast(int id)
{
	g_cast.xstep *= !g_rays[id].is_ray_right && g_cast.xstep > 0 ? -1 : 1;
	g_cast.xstep *= g_rays[id].is_ray_right && g_cast.xstep < 0 ? -1 : 1;
	g_cast.next_horz_tx = g_cast.xinter;
	g_cast.next_horz_ty = g_cast.yinter;
	while (1)
	{
		g_cast.x_to_check = g_cast.next_horz_tx;
		g_cast.y_to_check = g_cast.next_horz_ty + \
		(!g_rays[id].is_ray_down ? -1 : 0);
		if (has_wall((t_position){g_cast.x_to_check, g_cast.y_to_check}))
		{
			g_cast.wall_hor_x = g_cast.next_horz_tx;
			g_cast.wall_hor_y = g_cast.next_horz_ty;
			g_cast.horz_hit = TRUE;
			break ;
		}
		else
		{
			g_cast.next_horz_tx += g_cast.xstep;
			g_cast.next_horz_ty += g_cast.ystep;
		}
	}
}

void	vert_cast(float angle, int id)
{
	g_cast.xstep = !g_rays[id].is_ray_right ? -1 * TILE_SIZE : TILE_SIZE;
	g_cast.ystep = TILE_SIZE * tan(angle);
	g_cast.ystep *= !g_rays[id].is_ray_down && g_cast.ystep > 0 ? -1 : 1;
	g_cast.ystep *= g_rays[id].is_ray_down && g_cast.ystep < 0 ? -1 : 1;
	g_cast.next_vert_tx = g_cast.xinter;
	g_cast.next_vert_ty = g_cast.yinter;
	while (1)
	{
		g_cast.x_to_check = g_cast.next_vert_tx + \
		(!g_rays[id].is_ray_right ? -1 : 0);
		g_cast.y_to_check = g_cast.next_vert_ty;
		if (has_wall((t_position){g_cast.x_to_check, g_cast.y_to_check}))
		{
			g_cast.wall_ver_x = g_cast.next_vert_tx;
			g_cast.wall_ver_y = g_cast.next_vert_ty;
			g_cast.vert_hit = TRUE;
			break ;
		}
		else
		{
			g_cast.next_vert_tx += g_cast.xstep;
			g_cast.next_vert_ty += g_cast.ystep;
		}
	}
}

void	ft_compare_dis(float angle, int id)
{
	g_cast.horz_distance = g_cast.horz_hit ? distance_between(g_player.pos.x, \
	g_player.pos.y, g_cast.wall_hor_x, g_cast.wall_hor_y) : INT_MAX;
	g_cast.vert_distance = g_cast.vert_hit ? distance_between(g_player.pos.x, \
	g_player.pos.y, g_cast.wall_ver_x, g_cast.wall_ver_y) : INT_MAX;
	if (g_cast.vert_distance < g_cast.horz_distance)
	{
		g_rays[id].distance = g_cast.vert_distance;
		g_rays[id].wall_hit_x = g_cast.wall_ver_x;
		g_rays[id].wall_hit_y = g_cast.wall_ver_y;
		g_rays[id].was_hit_vert = TRUE;
	}
	else
	{
		g_rays[id].distance = g_cast.horz_distance;
		g_rays[id].wall_hit_x = g_cast.wall_hor_x;
		g_rays[id].wall_hit_y = g_cast.wall_hor_y;
		g_rays[id].was_hit_vert = FALSE;
	}
	g_rays[id].ray_angle = angle;
}

void	ft_cast_ray(float angle, int id)
{
	g_cast_init();
	g_rays[id].is_ray_down = angle > 0 && angle < PI;
	g_rays[id].is_ray_right = angle < 0.5 * PI || angle > 1.5 * PI;
	g_cast.yinter = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
	g_cast.yinter += g_rays[id].is_ray_down ? TILE_SIZE : 0;
	g_cast.xinter = g_player.pos.x + (g_cast.yinter - g_player.pos.y) / \
	tan(angle);
	g_cast.ystep = !g_rays[id].is_ray_down ? -1 * TILE_SIZE : TILE_SIZE;
	g_cast.xstep = TILE_SIZE / tan(angle);
	horz_cast(id);
	g_cast.xinter = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
	g_cast.xinter += g_rays[id].is_ray_right ? TILE_SIZE : 0;
	g_cast.yinter = g_player.pos.y + (g_cast.xinter - g_player.pos.x) \
	* tan(angle);
	vert_cast(angle, id);
	ft_compare_dis(angle, id);
}
