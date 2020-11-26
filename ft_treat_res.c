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

void		ft_treat_res(char **ptr)
{
	int h;
	int w;

	if (g_conf.win_h != -1)
		ft_error("Resolution repeated.\n");
	if (ft_ptr_str_len(ptr) != 3)
		ft_error("in Resolution. usage: R HEIGHT WIDTH\n");
	g_conf.win_h = ft_atoi(ptr[1], 0);
	g_conf.win_w = ft_atoi(ptr[2], 0);
	if (g_conf.win_h <= 0 || g_conf.win_w <= 0)
		ft_error("in Resolution. use just numbers superior then 0\n");
	mlx_get_screen_size(g_env.ptr, &w, &h);
	if (g_conf.win_h >= h)
		g_conf.win_h = h;
	if (g_conf.win_w >= w)
		g_conf.win_w = w;
	g_conf.num_rays = g_conf.win_w;
	g_conf.count++;
}
