/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:41:13 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/03 13:41:18 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_treat_spr(char **ptr)
{
    if (g_conf.spr.height != -1)
    {
        ft_putstr_fd("Error\n Sprite texture repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 2)
    {
        ft_putstr_fd("Error\n in sprite texture. usage: S ./path_to_the_sprite_texture\n", 1);
        exit(1);
    }
    if (!ft_is_end_with(ptr[1], ".xpm"))
    {
        ft_putstr_fd("Error\n in sprite texture. file extension is not valid!\n", 1);
        exit(1);
    }
    g_conf.spr.img = mlx_xpm_file_to_image(g_env.ptr, ptr[1], &g_conf.spr.width, &g_conf.spr.height);
    if (!g_conf.spr.img)
    {
        ft_putstr_fd("Error\n in sprite texture. can't open file! \n", 1);
        exit(1);
    }
    g_conf.spr.addr = (unsigned int *)mlx_get_data_addr(g_conf.spr.img, &g_conf.spr.bpp, &g_conf.spr.line_length, &g_conf.spr.endian);
    g_conf.count++;
}
