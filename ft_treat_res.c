/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trest_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:12:52 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 14:12:54 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void        ft_treat_res(char **ptr)
{
    if (g_conf.win_h != -1)
    {
        ft_putstr_fd("Error\nResolution repeated.\n", 1);
        exit(1);
    }
    if (ft_ptr_str_len(ptr) != 3)
    {
        ft_putstr_fd("Error\nin Resolution. usage: R HEIGHT WIDTH\n", 1);
        exit(1);
    }
    g_conf.win_h = ft_atoi(ptr[1]);
    g_conf.win_w = ft_atoi(ptr[2]);
    // NUM_RAYS = 1000;
    if (g_conf.win_h <= 0 || g_conf.win_w <= 0)
    {
        ft_putstr_fd("Error\nin Resolution. use just numbers superior then 0\n", 1);
        exit(1);
    }
    g_conf.count++;
}
