/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_ea.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:51:53 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 18:51:54 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_treat_ea(char **ptr)
{
    if (g_conf.ea.height != -1)
    {
        ft_putstr_fd("Error\n East texture repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 2)
    {
        ft_putstr_fd("Error\n in East texture. usage: EA ./path_to_the_east_texture\n", 1);
        exit(1);
    }
    if (!ft_is_end_with(ptr[1], ".xpm"))
    {
        ft_putstr_fd("Error\n in East texture. file extension is not valid!\n", 1);
        exit(1);
    }
    g_conf.ea.img = mlx_xpm_file_to_image(g_env.ptr, ptr[1], &g_conf.ea.width, &g_conf.ea.height);
    if (!g_conf.ea.img)
    {
        ft_putstr_fd("Error\n in East texture. can't open file! \n", 1);
        exit(1);
    }
    g_conf.ea.addr = (unsigned int *)mlx_get_data_addr(g_conf.ea.img, &g_conf.ea.bpp, &g_conf.ea.line_length, &g_conf.ea.endian);
    g_conf.count++;
}
