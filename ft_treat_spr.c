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

void	ft_treat_spr(char *line)
{
	char *file_name;

	if (g_conf.spr.height != -1)
		ft_error("Sprite texture repeated.\n");
	file_name = ft_strtrim(line + 2, " ");
	if (!ft_is_end_with(file_name, ".xpm"))
		ft_error("sprite texture. file extension is not valid!\n");
	g_conf.spr.img = mlx_xpm_file_to_image(g_env.ptr, file_name, \
	&g_conf.spr.width, &g_conf.spr.height);
	if (!g_conf.spr.img)
		ft_error("in sprite texture. can't open file! \n");
	g_conf.spr.addr = (unsigned int *)mlx_get_data_addr(g_conf.spr.img, \
	&g_conf.spr.bpp, &g_conf.spr.line_length, &g_conf.spr.endian);
	g_conf.count++;
	free(file_name);
}
