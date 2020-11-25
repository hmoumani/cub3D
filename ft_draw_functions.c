/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:30:21 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/19 13:30:22 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	put_my_pixel(int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < g_conf.win_h && y < g_conf.win_w)
	{
		dst = g_env.addr + (x * g_env.line_length + y * (g_env.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int		ft_hor_line(int x, int y, int color, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		put_my_pixel(x + i, y, color);
		i++;
	}
	return (1);
}

int		ft_square(int x, int y, int color, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_hor_line(x, y + i, color, size);
		i++;
	}
	return (1);
}

void	draw_ray(float angle, float d, int color)
{
	float y;
	float x;
	float i;

	i = 0;
	while (i < d)
	{
		x = cos(angle) * i + g_player.pos.x;
		y = sin(angle) * i + g_player.pos.y;
		put_my_pixel(x, y, color);
		i++;
	}
}

float	distance_between(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
