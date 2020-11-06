/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:22:37 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/03 17:22:40 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_treat_c(char **ptr)
{
    char **p;

    if (g_conf.c.r != -1)
    {
        ft_putstr_fd("Error\nCeilling color repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 2)
    {
        ft_putstr_fd("Error in ceilling rgb.\nusage: F r,g,b\n", 1);
        exit(1);
    }
    p = ft_split(ptr[1], ',', ft_count_words(ptr[1], ','));
    if (ft_ptr_str_len(p) != 3)
    {
        ft_putstr_fd("fix argument for ceilling color.\nusage: F r,g,b\n", 1);
        exit(1);
    }
    g_conf.c.r = ft_atoi(p[0]);
    g_conf.c.g = ft_atoi(p[1]);
    g_conf.c.b = ft_atoi(p[2]);
    if (g_conf.c.r < 0 || g_conf.c.g < 0 || g_conf.c.b < 0 || g_conf.c.r > 255 || g_conf.c.g > 255 || g_conf.c.b > 255)
    {
        ft_putstr_fd("R,G,B colors should be numbers in range[0,255].\n", 1);
        exit(1);
    }
    g_conf.count++;
}
