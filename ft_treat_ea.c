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

void	ft_treat_ea(char *line)
{
	char *file_name;

	if (g_conf.ea.height != -1)
		ft_error("East texture repeated.\n");
	file_name = ft_strtrim(line + 2, " ");
	if (!ft_is_end_with(file_name, ".xpm"))
		ft_error("in East texture. file extension is not valid!\n");
	g_conf.ea.img = mlx_xpm_file_to_image(g_env.ptr, file_name, \
	&g_conf.ea.width, &g_conf.ea.height);
	if (!g_conf.ea.img)
		ft_error("in East texture. can't open file! \n");
	g_conf.ea.addr = (unsigned int *)mlx_get_data_addr(g_conf.ea.img, \
	&g_conf.ea.bpp, &g_conf.ea.line_length, &g_conf.ea.endian);
	g_conf.count++;
	free(file_name);
}
