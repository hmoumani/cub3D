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

void ft_cast_g_rays()
{
	int i;
	float ray_angle;

	ray_angle = g_player.rotation_angle - (FOV_ANGLE / 2);
	ray_angle = normalizeangle(ray_angle);
	i = 0;
	while (i < g_conf.num_rays)
	{
		ft_cast_ray(ray_angle, i);
		// printf("id: %d, angle : %f, distance : %f\n", i, ray_angle, g_rays[i].distance);
		// draw_ray(ray_angle, g_rays[i].distance, 0x00FF00);
		ray_angle += FOV_ANGLE / g_conf.num_rays;
		i++;
	}
}


int skip(int r, t_position pos,int color)
{
	int r2 = r * r;
	int area = r2 << 2;
	int rr = r << 1;
	int tx;
	int ty;

	for (int i = 0; i < area; i++)
	{
		tx = (i % rr) - r;
		ty = (i / rr) - r;
		if (tx * tx + ty * ty <= r2)
			put_my_pixel(pos.x + tx, pos.y + ty, color);
	}
	return (0);
}

void ft_g_player(int r, t_position pos,int coolor)
{
	// skip(r, pos, 0x0000FF);
	ft_cast_g_rays();
}

int ft_render()
{
	ft_g_player(TILE_SIZE / 2, g_player.pos, 0x0000FF);
	ft_generate_3d(0, 0, 0, 0);
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	return (1);
}

void move_g_player()
{
	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	float move_step = g_player.walk_direction * g_player.walk_speed;
	float newX = g_player.pos.x + cos(g_player.rotation_angle) * (move_step * 3);
	float newY = g_player.pos.y + sin(g_player.rotation_angle) * (move_step * 3);
	if (!has_wall((t_position){newX, newY}))
	{
		g_player.pos.x = newX;
		g_player.pos.y = newY;
	}
	g_player.turn_direction = 0;
    g_player.walk_direction = 0;
}

int keyPress(int key, void *arg)
{
	printf("%d\n", key);
	if (key == 53)
    {
		mlx_destroy_window(g_env.ptr, g_env.win);
		exit(0);
    }
	else if (key == 13 || key == 126)
	{
		g_player.walk_direction = 1;
	}
	else if (key == 1 || key == 125)
	{
		g_player.walk_direction = -1;
	}
	else if (key == 123)
	{
		g_player.turn_direction = -1;
	}
	else if (key == 124)
	{
		g_player.turn_direction = 1;
	}
	else if (key == 0)
	{
		g_player.left_right = -90;
		ft_left_or_right();
		g_player.left_right = 0;
	}
	else if (key == 2)
	{
		g_player.left_right = 90;
		ft_left_or_right();
		g_player.left_right = 0;
	}
	move_g_player();
	ft_render();
	return (0);
}

int main(int argc, char **argv)
{
	g_env.ptr = mlx_init();
	file(argc, argv, 1);
	// TILE_SIZE = g_conf.win_w / g_conf.max_width;
    g_env.win = mlx_new_window(g_env.ptr, g_conf.win_w, g_conf.win_h, "hello world!");
	g_env.img =  mlx_new_image(g_env.ptr, g_conf.win_w, g_conf.win_h);
	g_env.addr = mlx_get_data_addr(g_env.img, &g_env.bpp, &g_env.line_length, &g_env.endian);

	g_rays = malloc (g_conf.num_rays * sizeof(t_ray));
	// ft_generate_3d(0, 0, 0, 0);
	// printf("%d, %d\n", g_player.default_i, g_player.default_j);
	ft_g_player(TILE_SIZE / 2, (t_position){g_player.default_i, g_player.default_j}, 0x0000ff);
	ft_generate_3d(0, 0, 0, 0);
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	mlx_hook(g_env.win, 2, 1L<<0, keyPress, (void *)0);
    mlx_loop(g_env.ptr);
}
