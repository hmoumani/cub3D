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

void ft_cast_ray(float ray_angle, int id)
{
	float xinter;
	float yinter;
	float xstep;
	float ystep;
	int horz_hit = FALSE;
	float wall_hit_hor_x;
	float wall_hit_hor_y;
	float next_horz_touchX = 0;
	float next_horz_touchY = 0;
	float x_to_check;
	float y_to_check;

	g_rays[id].is_ray_down = ray_angle > 0 && ray_angle < PI;
	g_rays[id].is_ray_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	yinter = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
	yinter += g_rays[id].is_ray_down ? TILE_SIZE : 0;
	xinter = g_player.pos.x + (yinter - g_player.pos.y) / tan(ray_angle);
	ystep = !g_rays[id].is_ray_down ? -1 * TILE_SIZE : TILE_SIZE;
	int x;
	xstep = TILE_SIZE / tan(ray_angle);
	xstep *= !g_rays[id].is_ray_right && xstep > 0 ? -1 : 1;
	xstep *= g_rays[id].is_ray_right && xstep < 0 ? -1 : 1;
	next_horz_touchX = xinter;
	next_horz_touchY = yinter;
	while(1)
	{
		x_to_check = next_horz_touchX;
		y_to_check = next_horz_touchY + (!g_rays[id].is_ray_down ? -1 : 0);
		x = has_wall((t_position){x_to_check, y_to_check});
		if(x)
		{
			wall_hit_hor_x = next_horz_touchX;
			wall_hit_hor_y = next_horz_touchY;
			horz_hit = TRUE;
			break;			
		}
		else
		{
			next_horz_touchX += xstep;
			next_horz_touchY += ystep;
		}
		
	}
	int vert_hit = FALSE;
	float wall_hit_ver_x;
	float wall_hit_ver_y;
	float next_vert_touchX = 0;
	float next_vert_touchY = 0;
	xinter = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
	xinter += g_rays[id].is_ray_right ? TILE_SIZE : 0;
	yinter = g_player.pos.y + (xinter - g_player.pos.x) * tan(ray_angle); 
	xstep = !g_rays[id].is_ray_right ? -1 * TILE_SIZE : TILE_SIZE;
	ystep = TILE_SIZE * tan(ray_angle);
	ystep *= !g_rays[id].is_ray_down && ystep > 0 ? -1 : 1;
	ystep *= g_rays[id].is_ray_down && ystep < 0 ? -1 : 1;
	next_vert_touchX = xinter;
	next_vert_touchY = yinter;
	while (1)
	{
		x_to_check = next_vert_touchX + (!g_rays[id].is_ray_right ? -1 : 0);
		y_to_check = next_vert_touchY;

		if(has_wall((t_position){x_to_check, y_to_check}))
		{
			wall_hit_ver_x = next_vert_touchX;
			wall_hit_ver_y = next_vert_touchY;
			vert_hit = TRUE;
			break;			
		}
		else
		{
			next_vert_touchX += xstep;
			next_vert_touchY += ystep;
		}
	}
	float horz_distance = horz_hit ? distance_between(g_player.pos.x, g_player.pos.y, wall_hit_hor_x, wall_hit_hor_y) : INT_MAX;
	float vert_distance = vert_hit ? distance_between(g_player.pos.x, g_player.pos.y, wall_hit_ver_x, wall_hit_ver_y) : INT_MAX;
	if (vert_distance < horz_distance)
	{
		g_rays[id].distance = vert_distance;
		g_rays[id].wall_hit_x = wall_hit_ver_x;
		g_rays[id].wall_hit_y = wall_hit_ver_y;
		g_rays[id].was_hit_vert = TRUE;
	}
	else
	{
		g_rays[id].distance = horz_distance;
		g_rays[id].wall_hit_x = wall_hit_hor_x;
		g_rays[id].wall_hit_y = wall_hit_hor_y;
		g_rays[id].was_hit_vert = FALSE;
	}
	g_rays[id].ray_angle = ray_angle;
}
