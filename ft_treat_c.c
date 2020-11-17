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
    char    **p;
    int     r;
    int     g;
	int		b;

    if (g_conf.c != -1)
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
    r = ft_atoi(p[0]);
    g = ft_atoi(p[1]);
    b = ft_atoi(p[2]);
    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
    {
        ft_putstr_fd("R,G,B colors should be numbers in range[0,255].\n", 1);
        exit(1);
    }
	g_conf.c = create_trgb(0, r, g, b);
    g_conf.count++;
}
