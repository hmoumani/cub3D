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

void	ft_treat_we(char *line)
{
	char *file_name;

	if (g_conf.we.height != -1)
		ft_error("West texture repeated.\n");
	file_name = ft_strtrim(line + 2, " ");
	if (!ft_is_end_with(file_name, ".xpm"))
		ft_error("in west texture. file extension is not valid!\n");
	g_conf.we.img = mlx_xpm_file_to_image(g_env.ptr, file_name, \
	&g_conf.we.width, &g_conf.we.height);
	if (!g_conf.we.img)
		ft_error("in west texture. can't open file! \n");
	g_conf.we.addr = (unsigned int *)mlx_get_data_addr(g_conf.we.img, \
	&g_conf.we.bpp, &g_conf.we.line_length, &g_conf.we.endian);
	g_conf.count++;
	free(file_name);
}
