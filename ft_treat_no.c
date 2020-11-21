/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:40:08 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 14:40:09 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_join_file(char **ptr, int count)
{
	int		i;
	char	*str;
	char	*pfree;

	pfree = NULL;
	str = ft_strdup(ptr[1]);
	i = 1;
	while (i + 1 < count)
	{
		pfree = str;
		str = ft_join_space(str, ptr[i + 1]);
		free(pfree);
		i++;
	}
	return (str);
}

void	ft_treat_no(char **ptr, int count)
{
	char *file_name;

	if (g_conf.no.height != -1)
		ft_error("North texture repeated.\n");
	file_name = ft_join_file(ptr, count);
	if (!ft_is_end_with(file_name, ".xpm"))
		ft_error("in North texture. file extension is not valid!\n");
	printf("-%s-\n", file_name);
	g_conf.no.img = mlx_xpm_file_to_image(g_env.ptr, file_name, \
	&g_conf.no.width, &g_conf.no.height);
	if (!g_conf.no.img)
		ft_error("in north texture.can't open file! \n");
	g_conf.no.addr = (unsigned int *)mlx_get_data_addr(g_conf.no.img, \
	&g_conf.no.bpp, &g_conf.no.line_length, &g_conf.no.endian);
	g_conf.count++;
	free(file_name);
}
