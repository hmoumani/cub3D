/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:19:39 by hmoumani          #+#    #+#             */
/*   Updated: 2019/10/23 16:49:00 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

float	normalizeangle(float ray_angle)
{
	ray_angle = remainderf(ray_angle, TWO_PI);
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;
	return (ray_angle);
}

int		has_wall(t_position pos)
{
	int x;
	int y;

	y = floor(pos.y / TILE_SIZE);
	x = floor(pos.x / TILE_SIZE);
	if (x < 0 || x > g_conf.max_height - 1 || y < 0 || \
	y > g_conf.max_width - 1)
		return (TRUE);
	return (g_conf.map[x][y] == '1' || g_conf.map[x][y] == ' ');
}

float	ft_rad(float num)
{
	return (num * (PI / 180));
}

float	ft_sign(float num)
{
	return (num < 0 ? -1 : 1);
}

int		ft_atoi(const char *str, int i)
{
	int		sign;
	int		integer;

	integer = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = (str[i] == 45 ? -1 : 1);
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			if ((unsigned long)integer * 10 > 9223372036854775807)
				return (sign == 1) ? -1 : 0;
			integer *= 10;
			integer += str[i] - 48;
		}
		else if (str[i] == ' ')
			return (integer * sign);
		else
			return (-1);
		i++;
	}
	return (integer * sign);
}
