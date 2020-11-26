/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:27:05 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/24 17:27:12 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

float	to_deg(float angle)
{
	angle = angle * (180 / M_PI);
	return (angle);
}

void	sprite_put_pixels(t_sprit *sprit, int i, int j)
{
	int color;

	color = g_conf.spr.addr[((int)g_conf.spr.width * (j * \
	(int)g_conf.spr.height /
			(int)sprit->size)) + (i * (int)g_conf.spr.width /
			(int)sprit->size)];
	if (color != 0)
	{
		put_my_pixel(sprit->y_ofst + j, sprit->x_ofst + i, color);
	}
}

void	draw_sprite(t_sprit *sprit)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < sprit->size - 1)
	{
		if (sprit->x_ofst + i < 0 ||
				sprit->x_ofst + i > g_conf.win_w)
			continue;
		if ((int)sprit->x_ofst + i >= g_conf.num_rays)
			continue;
		if (sprit->dis > g_rays[(int)sprit->x_ofst + i].distance)
			continue;
		j = -1;
		while (++j < sprit->size - 1)
		{
			if (sprit->y_ofst + j < 0 ||
					sprit->y_ofst + j > g_conf.win_h)
				continue;
			sprite_put_pixels(sprit, i, j);
		}
	}
}

void	render_sprite(t_sprit *sprit)
{
	float angle;

	angle = atan2(sprit->y - g_player.pos.y, sprit->x - g_player.pos.x);
	while (angle - (g_player.rotation_angle) > M_PI)
		angle -= 2 * M_PI;
	while (angle - (g_player.rotation_angle) < -M_PI)
		angle += 2 * M_PI;
	angle = angle - (g_player.rotation_angle);
	if (g_conf.win_h > g_conf.win_w)
		sprit->size = (g_conf.win_h / sprit->dis) * TILE_SIZE;
	else
		sprit->size = (g_conf.win_w / sprit->dis) * TILE_SIZE;
	sprit->y_ofst = (g_conf.win_h / 2) - (sprit->size / 2);
	sprit->x_ofst = ((angle * g_conf.win_w) / FOV_ANGLE) +
		((g_conf.win_w / 2) - (sprit->size / 2));
	draw_sprite(sprit);
}
