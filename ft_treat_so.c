/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_so.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:39:30 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 18:39:31 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_treat_so(char **ptr)
{
	if (g_conf.so.height != -1)
		ft_error("South texture repeated.\n");
	if (ft_ptr_str_len(ptr) != 2)
		ft_error("in South texture. usage: SO ./path_to_the_south_texture\n");
	if (!ft_is_end_with(ptr[1], ".xpm"))
		ft_error("in South texture. file extension is not valid!\n");
	g_conf.so.img = mlx_xpm_file_to_image(g_env.ptr, ptr[1], \
	&g_conf.so.width, &g_conf.so.height);
	if (!g_conf.so.img)
		ft_error("in south texture. can't open file! \n");
	g_conf.so.addr = (unsigned int *)mlx_get_data_addr(g_conf.so.img, \
	&g_conf.so.bpp, &g_conf.so.line_length, &g_conf.so.endian);
	g_conf.count++;
}