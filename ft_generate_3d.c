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

void    ft_clear_buffer()
{
    int i;
    int j;

    i = 0;
    while (i < g_conf.win_h)
    {
        j = 0;
        while(j < g_conf.win_w)
        {
            put_my_pixel(i, j, 0);
            j++;
        }
        i++;
    }
}

void    ft_fill(int x,int start, int end, int color)
{
    int i;

    i = start;
    while (i < end)
    {
        put_my_pixel(i, x, color);
        i++;
    }
}

void    ft_generate_3d()
{
    int i;
    int y;
    float distance_pro;
    float projected_wall;
    int wall_strip_height;
    int top_pixel;
    int bottom_pixel;
    float perp_dis;

    i = 0;
    y = 0;
    while(i < NUM_RAYS)
    {
        perp_dis = rays[i].distance * cos(rays[i].rayAngle - player.rotationAngle);
        distance_pro = (g_conf.win_w / 2) / tan(FOV_ANGLE / 2);
        projected_wall = (TILE_SIZE / perp_dis) * distance_pro;
        wall_strip_height = (int)projected_wall;
        top_pixel = (g_conf.win_h / 2) - (wall_strip_height / 2);
        top_pixel = top_pixel < 0 ? 0 : top_pixel;
        bottom_pixel = (g_conf.win_h / 2) + (wall_strip_height / 2);
        bottom_pixel = bottom_pixel > g_conf.win_h ? g_conf.win_h : bottom_pixel;
        y = top_pixel;
        ft_fill(i, 0, top_pixel, g_conf.f);
        while (y < bottom_pixel)
        {
            put_my_pixel(y, i, 0xff00ff);
            y++;
        }
        ft_fill(i, bottom_pixel,g_conf.win_h, g_conf.c);
        i++;
    }
}
