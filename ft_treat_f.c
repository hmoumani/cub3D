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

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_treat_f(char **ptr)
{
	char	**p;
	int		r;
	int		g;
	int		b;

	if (g_conf.f != -1)
		ft_error("floor color repeated.\n");
	if (ft_ptr_str_len(ptr) != 2)
		ft_error("in floor rgb.\nusage: F r,g,b\n");
	p = ft_split(ptr[1], ',', ft_count_words(ptr[1], ','));
	if (ft_ptr_str_len(p) != 3)
		ft_error("fix argument for floor color.\nusage: F r,g,b\n");
	r = ft_atoi(p[0]);
	g = ft_atoi(p[1]);
	b = ft_atoi(p[2]);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		ft_error("R,G,B colors should be numbers in range[0,255].\n");
	g_conf.f = create_trgb(0, r, g, b);
	g_conf.count++;
}
