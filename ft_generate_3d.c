/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:39:10 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/17 16:39:12 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_fill(int x, int start, int end, int color)
{
	int i;

	i = start;
	while (i < end)
	{
		put_my_pixel(i, x, color);
		i++;
	}
}

int		ft_get_y(int y, int wall_strip_height)
{
	int distance_from_top;

	distance_from_top = y + (wall_strip_height / 2) - (g_conf.win_h / 2);
	return (distance_from_top * ((float)g_conf.no.height / wall_strip_height));
}

int		ft_get_color(int ray_id, int y, int top_pixel, int wall_strip_height)
{
	int				text_x;
	int				text_y;
	int				distance_from_top;
	unsigned int	*from;

	if (g_rays[ray_id].was_hit_vert)
	{
		if (!g_rays[ray_id].is_ray_right)
			from = g_conf.ea.addr;
		else if (g_rays[ray_id].is_ray_right)
			from = g_conf.we.addr;
	}
	if (!g_rays[ray_id].was_hit_vert)
	{
		if (!g_rays[ray_id].is_ray_down)
			from = g_conf.no.addr;
		else if (g_rays[ray_id].is_ray_down)
			from = g_conf.so.addr;
	}
	if (g_rays[ray_id].was_hit_vert)
		text_x = (int)g_rays[ray_id].wall_hit_y % TILE_SIZE;
	else
		text_x = (int)g_rays[ray_id].wall_hit_x % TILE_SIZE;
	text_y = ft_get_y(y, wall_strip_height);
	return (from[(g_conf.no.width * text_y) + text_x]);
}

void	ft_fill_c_a_f(int i, int top_p, int bottom_pixel)
{
	ft_fill(i, 0, top_p, g_conf.f);
	ft_fill(i, bottom_pixel, g_conf.win_h, g_conf.c);
}

void	ft_generate_3d(int i, int y, float distance_pro, float pro_wall)
{
	int		top_p;
	int		bottom_pixel;
	float	perp_dis;

	while (i < g_conf.num_rays)
	{
		perp_dis = g_rays[i].distance * cos(g_rays[i].ray_angle - \
		g_player.rotation_angle);
		distance_pro = (g_conf.win_w / 2) / tan(FOV_ANGLE / 2);
		pro_wall = (TILE_SIZE / perp_dis) * distance_pro;
		top_p = (g_conf.win_h / 2) - ((int)pro_wall / 2);
		top_p = top_p < 0 ? 0 : top_p;
		bottom_pixel = (g_conf.win_h / 2) + ((int)pro_wall / 2);
		if (bottom_pixel > g_conf.win_h)
			bottom_pixel = g_conf.win_h;
		else
			bottom_pixel = bottom_pixel;
		y = top_p;
		while (y < bottom_pixel)
		{
			put_my_pixel(y, i, (int)ft_get_color(i, y, top_p, (int)pro_wall));
			y++;
		}
		ft_fill_c_a_f(i++, top_p, bottom_pixel);
	}
}
