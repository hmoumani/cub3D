/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:30:51 by hmoumani          #+#    #+#             */
/*   Updated: 2020/10/18 18:30:55 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// int ft_putchar(char c)
// {
//     return (write(1, &c, 1));
// }


// // int ft_line(t_position pos, int size, int color)
// // {
// //     int i;

// //     i = 0;
// //     while (i < size)
// //     {
// //         mlx_pixel_put(g_env.ptr, g_env.win, pos.x + i, pos.y, color);
// //         i++;
// //     }
// //     return (size);
// // }

// int ft_square(t_position start, float size, int color)
// {
//     float i;
//     float j;

//     j = 0;
//     while (j < size)
//     {
//         i = 0;
//         while (i < size)
//         {
//             mlx_pixel_put(g_env.ptr, g_env.win, start.x + i, start.y + j, color);
//             i++;
//         }
//         j++;
//     }
//     return (size);
// }

// void ft_circle(int r, t_position pos,int color)
// {
// 	int r2 = r * r;
// 	int area = r2 << 2;
// 	int rr = r << 1;
// 	int tx;
// 	int ty;

// 	for (int i = 0; i < area; i++)
// 	{
// 		tx = (i % rr) - r;
// 		ty = (i / rr) - r;
// 		if (tx * tx + ty * ty <= r2)
// 			mlx_pixel_put(g_env.ptr, g_env.win, pos.x + tx, pos.y + ty, color);
// 	}
// }
// int has_wall(t_position pos)
// {
// 	if (pos.x < 0 || pos.x > WINDOW_WIDTH || pos.y < 0 || pos.x > WINDOW_HEIGHT)
// 		return (True);
// 	int indexX = floor(pos.x / TILE_SIZE);
// 	int indexY = floor(pos.y / TILE_SIZE);
// 	return (world[indexY][indexX] == '1');
// }



// void move_player()
// {
// 	player.rotationAngle += player.turnDirection * player.turnSpeed;
// 	float move_step = player.walkDirection * player.walkSpeed;
// 	float newX = player.pos.x + cos(player.rotationAngle) * move_step;
// 	float newY = player.pos.y + sin(player.rotationAngle) * move_step;
// 	if (!has_wall((t_position){newX, newY}))
// 	{
// 		player.pos.x = newX;
// 		player.pos.y = newY;
// 	}
// 	player.turnDirection = 0;
//     player.walkDirection = 0;
// }

// // int ft_init_map()
// // {
// // 	float i;
// // 	float j;

// // 	i = 0;
// // 	while (i < MAP_COLS)
// // 	{
// // 		j = 0;
// // 		while (j < MAP_ROWS)
// // 		{
// // 			if (world[(int)j][(int)i] == '1')
// // 			{
// // 				ft_square((t_position){i * TILE_SIZE, j * TILE_SIZE}, TILE_SIZE, 441464);
// // 			}
// // 			else if (world[(int)j][(int)i] == '2')
// // 			{
// // 				ft_circle(10, (t_position){i * TILE_SIZE, j * TILE_SIZE}, 441464);
// // 			}
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // 	return 1;
// // }

// void ft_init()
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < MAP_COLS)
// 	{
// 		j = 0;
// 		while (j < MAP_ROWS)
// 		{
// 			if (world[j][i] == '1')
// 			{
// 				ft_square((t_position){i * TILE_SIZE, j * TILE_SIZE}, TILE_SIZE, 441464);
// 			}
// 			else if (world[j][i] == '2')
// 			{
// 				player.pos.x = i * TILE_SIZE;
// 				player.pos.y = j * TILE_SIZE;
// 				player.turnDirection = 0;
// 				player.walkDirection = 0;
// 				player.rotationAngle = ft_rad(90);
// 				player.walkSpeed = 10;
// 				player.turnSpeed = ft_rad(45);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int ft_render()
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	mlx_clear_window(g_env.ptr, g_env.win);
// 	while (i < MAP_COLS)
// 	{
// 		j = 0;
// 		while (j < MAP_ROWS)
// 		{
// 			if (world[j][i] == '1')
// 			{
// 				ft_square((t_position){i * TILE_SIZE, j * TILE_SIZE}, TILE_SIZE, 441464);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	ft_square(player.pos, 10, 441464);
// 	return (1);
// }

// int keyPress(int key, void *param)
// {
//     printf("%d\n", key);
//     if (key == 53)
//     {
// 		mlx_destroy_window(g_env.ptr, g_env.win);
// 		exit(0);
//     }
// 	else if (key == 13)
// 	{
// 		player.walkDirection = 1;
// 		move_player();
// 	}
// 	else if (key == 0)
// 	{
// 		player.pos.x -= 5;
// 	}
// 	else if (key == 1)
// 	{
// 		player.walkDirection = -1;
// 		move_player();
// 	}
// 	else if (key == 2)
// 	{
// 		player.pos.x += 5;
// 	}
// 	else if (key == 123)
// 	{
// 		player.turnDirection = -1;
// 		move_player();
// 	}
// 	else if (key == 124)
// 	{
// 		player.turnDirection = 1;
// 		move_player();
// 	}
// 	ft_render();
//     return (0);
// }

float ft_abs(float num)
{
	return num < 0 ? -num : num;
}

float	normalizeangle(float rayangle)
{
	rayangle = remainderf(rayangle,  TWO_PI);
	if (rayangle < 0)
		rayangle = TWO_PI + rayangle;
	return(rayangle);
}

float ft_rad(float num)
{
	return (num *(PI / 180));
}
float ft_sign(float num)
{
	return num < 0 ? -1 : 1;
}

int has_wall(t_position pos)
{
	if (pos.x < 0 || pos.x > g_conf.win_w || pos.y < 0 || pos.y > g_conf.win_h)
		return (True);
	int indexX = floor(pos.x / TILE_SIZE);
	int indexY = floor(pos.y / TILE_SIZE);
	return (g_conf.map[indexX][indexY] == '1');
}

void	put_my_pixel(int x, int y, int color)
{
	char 	*dst;
	
	if (x >= 0 && y >= 0 && x < g_conf.win_h && y < g_conf.win_w)
	{
		dst = g_env.addr + (x * g_env.line_length + y * (g_env.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

// void ft_line(int x0, int y0, int x1, int y1)
// {
//     float deltax = x1 - x0;
//     float deltay = y1 - y0;
//     float deltaerr = ft_abs(deltay / deltax);
//     float error = 0.0;
//     int y = y0;
// 	int x = x0;
//     while (x < x1)
// 	{
//         put_my_pixel(x, y, 0x00FF00);
//         error = error + deltaerr;
//         if (error >= 0.5)
// 		{
//             y = y + ft_sign(deltay);
//             error = error - 1.0;
// 		}
// 		x++;
// 	}
// }

void	draw_ray(float angle,float d, int color)
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

float distance_between(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

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

	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= !rays[id].isRayRight && xstep > 0 ? -1 : 1;
	xstep *= rays[id].isRayRight && xstep < 0 ? -1 : 1;

	next_horz_touchX = xinter;
	next_horz_touchY = yinter;
	while (next_horz_touchX >= 0 && next_horz_touchX <= g_conf.win_h && next_horz_touchY >= 0 && next_horz_touchY <= g_conf.win_w)
	{
		x_to_check = next_horz_touchX;
		y_to_check = next_horz_touchY + (!rays[id].isRayDown ? -1 : 0);

		if(has_wall((t_position){x_to_check, y_to_check}))
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
	while (next_vert_touchX >= 0 && next_vert_touchX <= g_conf.win_h && next_vert_touchY >= 0 && next_vert_touchY <= g_conf.win_w)
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

void ft_cast_rays()
{
	t_position pos;
	int i;
	float rayAngle;

	rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	rayAngle = normalizeangle(rayAngle);
	i = 0;
	pos = player.pos;
	while (i < 100)
	{
		ft_cast_ray(rayAngle, i);
		// ft_line(pos.x, pos.y, rays[i].wallHitX, rays[i].wallHitY);
		draw_ray(rayAngle, rays[i].distance, 0x00FF00);
		printf("id: %d, angle : %f, distance : %f\n", i, rayAngle, rays[i].distance);
		rayAngle += FOV_ANGLE / 100;
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
	skip(PLAYER_R, player.pos, 0x0000FF);
	// ft_cast_rays();
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

void move_player()
{
	player.rotationAngle += player.turnDirection * player.turnSpeed;
	float move_step = player.walkDirection * player.walkSpeed;
	float newX = player.pos.x + cos(player.rotationAngle) * move_step;
	float newY = player.pos.y + sin(player.rotationAngle) * move_step;
	// printf("%d\n", has_wall((t_position){newX, newY}));
	if (!has_wall((t_position){newX, newY}))
	{
		player.pos.x = newX;
		player.pos.y = newY;
	}
	player.turnDirection = 0;
    player.walkDirection = 0;
}

int ft_player_pos()
{
	int i;
	int j;

	i = 0;
	// while (i < g_conf.max_width)
	// {
	// 	j = 0;
	// 	while (j < g_conf.max_height)
	// 	{
	// 		if (g_conf.map[i][j] == '2')
	// 		{
				player.pos.x = g_player.default_i * TILE_SIZE;
				player.pos.y = g_player.default_j * TILE_SIZE;
				player.turnDirection = 0;
				player.walkDirection = 0;
				player.rotationAngle = ft_rad(90);
				player.walkSpeed = 10;
				player.turnSpeed = ft_rad(5);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (1);
}

int ft_init()
{
	int i;
	int j;

	i = 0;
	while (i < g_conf.max_height)
	{
		j = 0;
		while (j < g_conf.max_width)
		{
			if (g_conf.map[i][j] == '1' || g_conf.map[i][j] == ' ')
				ft_square(i * TILE_SIZE, j * TILE_SIZE, 0xFF0000, TILE_SIZE);
			else
				ft_square(i * TILE_SIZE, j * TILE_SIZE, 0x000000, TILE_SIZE);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_render()
{
	ft_init();
	ft_player(PLAYER_R, player.pos, 0x0000FF);
	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	return (1);
}

int keyPress(int key, void *arg)
{
	printf("%d\n", key);
	if (key == 53)
    {
		mlx_destroy_window(g_env.ptr, g_env.win);
		exit(0);
    }
	else if (key == 13)
	{
		player.walkDirection = 1;
		move_player();
	}
	// else if (key == 0)
	// {
	// 	player.pos.x -= 5;
	// }
	else if (key == 1)
	{
		player.walkDirection = -1;
		move_player();
	}
	// else if (key == 2)
	// {
	// 	player.pos.x += 5;
	// }
	else if (key == 123)
	{
		player.turnDirection = 1;
		move_player();
	}
	else if (key == 124)
	{
		player.turnDirection = -1;
		move_player();
	}
	ft_render();
	return key;
}

/********************************************************************************
 * 																				*
 * 																				*
 * 																				*
 ********************************************************************************/



int main(int argc, char **argv)
{
	// printf("%d", WINDOW_WIDTH);
	// printf("%d", WINDOW_HEIGHT);
	// exit(1);
    g_env.ptr = mlx_init();
	file(argc, argv);
	TILE_SIZE = g_conf.win_w / g_conf.max_width;
    g_env.win = mlx_new_window(g_env.ptr, g_conf.win_w, g_conf.win_h, "hello world!");
	g_env.img =  mlx_new_image(g_env.ptr, g_conf.win_w, g_conf.win_h);
	g_env.addr = mlx_get_data_addr(g_env.img, &g_env.bpp, &g_env.line_length, &g_env.endian);
	ft_init();
	ft_square(20, 20, 0xFF0000, 20);
	ft_player_pos();
	ft_player(PLAYER_R, player.pos, 0x0000FF);

	// draw_ray(45, 600);

	mlx_put_image_to_window(g_env.ptr, g_env.win, g_env.img, 0, 0);
	mlx_hook(g_env.win, 2, 1L<<0, keyPress, (void *)0);
    mlx_loop(g_env.ptr);
}