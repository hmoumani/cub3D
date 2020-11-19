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

void	put_my_pixel(int x, int y, int color)
{
	char 	*dst;
	
	if (x >= 0 && y >= 0 && x < g_conf.win_h && y < g_conf.win_w)
	{
		dst = g_env.addr + (x * g_env.line_length + y * (g_env.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int ft_hor_line(int x, int y, int color, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		put_my_pixel(x + i, y, color);
		i++;
	}
	return 1;
}

int ft_square(int x, int y, int color, int size)
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
		x = cos(angle) * i + player.pos.x;
		y = sin(angle) * i + player.pos.y;
		put_my_pixel(x, y, color);
		i++;
	}

}


float distance_between(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void ft_cast_rays()
{
	int i;
	float rayAngle;

	rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	rayAngle = normalizeangle(rayAngle);
	i = 0;
	while (i < NUM_RAYS)
	{
		ft_cast_ray(rayAngle, i);
		// printf("id: %d, angle : %f, distance : %f\n", i, rayAngle, rays[i].distance);
		// draw_ray(rayAngle, rays[i].distance, 0x00FF00);
		rayAngle += FOV_ANGLE / NUM_RAYS;
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

void ft_player(int r, t_position pos,int coolor)
{
	// skip(r, pos, 0x0000FF);
	ft_cast_rays();
}

int ft_init()
{
	// int i;
	// int j;

	// i = 0;
	// while (i < g_conf.max_height)
	// {
	// 	j = 0;
	// 	while (j < g_conf.max_width)
	// 	{
	// 		if (g_conf.map[i][j] == '1' || g_conf.map[i][j] == ' ')
	// 			ft_square(i * TILE_SIZE, j * TILE_SIZE, 0xFF0000, TILE_SIZE);
	// 		else
	// 			ft_square(i * TILE_SIZE, j * TILE_SIZE, 0x000000, TILE_SIZE);
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (1);
}

int ft_render()
{
	ft_init();
	ft_clear_buffer();
	ft_player(TILE_SIZE / 2, player.pos, 0x0000FF);
	ft_generate_3d();
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	return (1);
}

void move_player()
{
	player.rotationAngle += player.turnDirection * player.turnSpeed;
	float move_step = player.walkDirection * player.walkSpeed;
	float newX = player.pos.x + cos(player.rotationAngle) * (move_step * 3);
	float newY = player.pos.y + sin(player.rotationAngle) * (move_step * 3);
	// printf("%d\n", has_wall((t_position){newX, newY}));
	if (!has_wall((t_position){newX, newY}))
	{
		player.pos.x = newX;
		player.pos.y = newY;
	}
	player.turnDirection = 0;
    player.walkDirection = 0;
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
		player.walkDirection = 1;
	}
	else if (key == 1 || key == 125)
	{
		player.walkDirection = -1;
	}
	else if (key == 123)
	{
		player.turnDirection = -1;
	}
	else if (key == 124)
	{
		player.turnDirection = 1;
	}
	else if (key == 0)
	{
		player.left_right = -90;
		ft_left_or_right();
		player.left_right = 0;
	}
	else if (key == 2)
	{
		player.left_right = 90;
		ft_left_or_right();
		player.left_right = 0;
	}
	move_player();
	ft_render();
	return (0);
}

int main(int argc, char **argv)
{
	g_env.ptr = mlx_init();
	file(argc, argv);
	// TILE_SIZE = g_conf.win_w / g_conf.max_width;
    g_env.win = mlx_new_window(g_env.ptr, g_conf.win_w, g_conf.win_h, "hello world!");
	g_env.img =  mlx_new_image(g_env.ptr, g_conf.win_w, g_conf.win_h);
	g_env.addr = mlx_get_data_addr(g_env.img, &g_env.bpp, &g_env.line_length, &g_env.endian);

	rays = malloc (NUM_RAYS * sizeof(t_ray));
	// ft_init();
	// ft_generate_3d();
	// printf("%d, %d\n", g_player.default_i, g_player.default_j);
	ft_player(TILE_SIZE / 2, (t_position){g_player.default_i, g_player.default_j}, 0x0000ff);
	ft_generate_3d();
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	mlx_hook(g_env.win, 2, 1L<<0, keyPress, (void *)0);
    mlx_loop(g_env.ptr);
}
