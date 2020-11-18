/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:40:08 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 14:40:09 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_treat_no(char **ptr)
{
    if (g_conf.no.height != -1)
    {
        ft_putstr_fd("Error\n North texture repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 2)
    {
        ft_putstr_fd("Error\n in North texture. usage: NO ./path_to_the_north_texture\n", 1);
        exit(1);
    }
    if (!ft_is_end_with(ptr[1], ".xpm"))
    {
        ft_putstr_fd("Error\n in North texture. file extension is not valid!\n", 1);
        exit(1);
    }
    g_conf.no.img = mlx_xpm_file_to_image(g_env.ptr, ptr[1], &g_conf.no.width, &g_conf.no.height);
    g_conf.no.addr=(unsigned int *)mlx_get_data_addr(g_conf.no.img, &g_conf.no.bpp, &g_conf.no.line_length, &g_conf.no.endian);
    if (!g_conf.no.img)
    {
        ft_putstr_fd("Error\n in north texture.can't open file! \n", 1);
        exit(1);
    }
    g_conf.count++;
}
