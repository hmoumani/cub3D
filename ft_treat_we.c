/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_we.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:49:04 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 18:49:07 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_treat_we(char **ptr)
{
    if (g_conf.we.height != -1)
    {
        ft_putstr_fd("Error\n West texture repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 2)
    {
        ft_putstr_fd("Error\n in west texture. usage: WE ./path_to_the_west_texture\n", 1);
        exit(1);
    }
    if (!ft_is_end_with(ptr[1], ".xpm"))
    {
        ft_putstr_fd("Error\n in west texture. file extension is not valid!\n", 1);
        exit(1);
    }
    g_conf.we.img = mlx_xpm_file_to_image(g_env.ptr, ptr[1], &g_conf.we.width, &g_conf.we.height);
    if (!g_conf.we.img)
    {
        ft_putstr_fd("Error\n in west texture. can't open file! \n", 1);
        exit(1);
    }
    g_conf.we.addr = (unsigned int *)mlx_get_data_addr(g_conf.we.img, &g_conf.we.bpp, &g_conf.we.line_length, &g_conf.we.endian);
    g_conf.count++;
}
