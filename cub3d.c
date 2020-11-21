/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:35:49 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/14 13:35:51 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_cast_g_rays(void)
{
	int		i;
	float	ray_angle;

	ray_angle = g_player.rotation_angle - (FOV_ANGLE / 2);
	i = 0;
	while (i < g_conf.num_rays)
	{
		ray_angle = normalizeangle(ray_angle);
		ft_cast_ray(ray_angle, i);
		ray_angle += FOV_ANGLE / g_conf.num_rays;
		i++;
	}
}

int		ft_render(void)
{
	ft_cast_g_rays();
	ft_generate_3d(0, 0, 0, 0);
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	return (1);
}

void	move_g_player(void)
{
	float move_step;
	float new_x;
	float new_y;

	move_step = g_player.walk_direction * g_player.walk_speed;
	new_x = g_player.pos.x + cos(g_player.rotation_angle) * (move_step * 3);
	new_y = g_player.pos.y + sin(g_player.rotation_angle) * (move_step * 3);
	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	if (!has_wall((t_position){new_x, new_y}))
	{
		g_player.pos.x = new_x;
		g_player.pos.y = new_y;
	}
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
}

int		key_press(int key)
{
	printf("%d\n", key);
	if (key == 53)
		ft_exit();
	else if (key == 13 || key == 126)
		g_player.walk_direction = 1;
	else if (key == 1 || key == 125)
		g_player.walk_direction = -1;
	else if (key == 123)
		g_player.turn_direction = -1;
	else if (key == 124)
		g_player.turn_direction = 1;
	else if (key == 0)
		g_player.left_right = -90;
	else if (key == 2)
		g_player.left_right = 90;
	move_g_player();
	ft_left_or_right();
	ft_render();
	return (0);
}

int		main(int argc, char **argv)
{
	g_env.ptr = mlx_init();
	file(argc, argv, 1);
	g_env.win = mlx_new_window(g_env.ptr, g_conf.win_w, g_conf.win_h, "cub3D");
	g_env.img = mlx_new_image(g_env.ptr, g_conf.win_w, g_conf.win_h);
	g_env.addr = mlx_get_data_addr(g_env.img, &g_env.bpp, \
	&g_env.line_length, &g_env.endian);
	g_rays = malloc(g_conf.num_rays * sizeof(t_ray));
	ft_cast_g_rays();
	ft_generate_3d(0, 0, 0, 0);
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	ft_screenshot();
	mlx_hook(g_env.win, 2, 1L << 0, key_press, (void *)0);
	mlx_loop(g_env.ptr);
}
