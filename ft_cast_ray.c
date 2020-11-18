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


void ft_cast_ray(float rayAngle, int id)
{
	rayAngle = normalizeangle(rayAngle);
	float xinter;
	float yinter;
	float xstep;
	float ystep;
	int horz_hit = False;
	float wall_hit_hor_x;
	float wall_hit_hor_y;
	float next_horz_touchX = 0;
	float next_horz_touchY = 0;
	float x_to_check;
	float y_to_check;
	rays[id].isRayDown = rayAngle > 0 && rayAngle < PI;
	rays[id].isRayRight = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;

	yinter = floor(player.pos.y / TILE_SIZE) * TILE_SIZE;
	yinter += rays[id].isRayDown ? TILE_SIZE : 0;

	xinter = player.pos.x + (yinter - player.pos.y) / tan(rayAngle);

	ystep = !rays[id].isRayDown ? -1 * TILE_SIZE : TILE_SIZE;

	int x;
	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= !rays[id].isRayRight && xstep > 0 ? -1 : 1;
	xstep *= rays[id].isRayRight && xstep < 0 ? -1 : 1;

	next_horz_touchX = xinter;
	next_horz_touchY = yinter;
	// while (next_horz_touchX >= 0 && next_horz_touchX <= g_conf.win_w && next_horz_touchY >= 0 && next_horz_touchY <= g_conf.win_h)
	while(1)
	{
		x_to_check = next_horz_touchX;
		y_to_check = next_horz_touchY + (!rays[id].isRayDown ? -1 : 0);
		x = has_wall((t_position){x_to_check, y_to_check});
		if(x)
		{
			wall_hit_hor_x = next_horz_touchX;
			wall_hit_hor_y = next_horz_touchY;
			horz_hit = True;
			break;			
		}
		else
		{
			next_horz_touchX += xstep;
			next_horz_touchY += ystep;
		}
		
	}


	int vert_hit = False;
	float wall_hit_ver_x;
	float wall_hit_ver_y;
	float next_vert_touchX = 0;
	float next_vert_touchY = 0;

	xinter = floor(player.pos.x / TILE_SIZE) * TILE_SIZE;
	xinter += rays[id].isRayRight ? TILE_SIZE : 0;

	yinter = player.pos.y + (xinter - player.pos.x) * tan(rayAngle); 

	xstep = !rays[id].isRayRight ? -1 * TILE_SIZE : TILE_SIZE;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= !rays[id].isRayDown && ystep > 0 ? -1 : 1;
	ystep *= rays[id].isRayDown && ystep < 0 ? -1 : 1;

	next_vert_touchX = xinter;
	next_vert_touchY = yinter;
	// while (next_vert_touchX >= 0 && next_vert_touchX <= g_conf.win_w && next_vert_touchY >= 0 && next_vert_touchY <= g_conf.win_h)
	while (1)
	{
		x_to_check = next_vert_touchX + (!rays[id].isRayRight ? -1 : 0);
		y_to_check = next_vert_touchY;

		if(has_wall((t_position){x_to_check, y_to_check}))
		{
			wall_hit_ver_x = next_vert_touchX;
			wall_hit_ver_y = next_vert_touchY;
			vert_hit = True;
			break;			
		}
		else
		{
			next_vert_touchX += xstep;
			next_vert_touchY += ystep;
		}
	}
	float horz_distance = horz_hit ? distance_between(player.pos.x, player.pos.y, wall_hit_hor_x, wall_hit_hor_y) : INT_MAX;
	float vert_distance = vert_hit ? distance_between(player.pos.x, player.pos.y, wall_hit_ver_x, wall_hit_ver_y) : INT_MAX;

	if (vert_distance < horz_distance)
	{
		rays[id].distance = vert_distance;
		rays[id].wallHitX = wall_hit_ver_x;
		rays[id].wallHitY = wall_hit_ver_y;
		rays[id].wasHitVert = True;
	}
	else
	{
		rays[id].distance = horz_distance;
		rays[id].wallHitX = wall_hit_hor_x;
		rays[id].wallHitY = wall_hit_hor_y;
		rays[id].wasHitVert = False;

	}
	rays[id].rayAngle = rayAngle;
}
