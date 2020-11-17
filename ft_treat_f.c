/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:32:11 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/03 14:32:12 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    ft_treat_f(char **ptr)
{
    char **p;

    if (g_conf.f.r != -1)
    {
        ft_putstr_fd("Error\nfloor color repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 2)
    {
        ft_putstr_fd("Error\nin floor rgb.\nusage: F r,g,b\n", 1);
        exit(1);
    }
    p = ft_split(ptr[1], ',', ft_count_words(ptr[1], ','));
    if (ft_ptr_str_len(p) != 3)
    {
        ft_putstr_fd("Error\nfix argument for floor color.\nusage: F r,g,b\n", 1);
        exit(1);
    }
    g_conf.f.r = ft_atoi(p[0]);
    g_conf.f.g = ft_atoi(p[1]);
    g_conf.f.b = ft_atoi(p[2]);
    if (g_conf.f.r < 0 || g_conf.f.g < 0 || g_conf.f.b < 0 || g_conf.f.r > 255 || g_conf.f.g > 255 || g_conf.f.b > 255)
    {
        ft_putstr_fd("Error\nR,G,B colors should be numbers in range[0,255].\n", 1);
        exit(1);
    }
    g_conf.count++;
}
