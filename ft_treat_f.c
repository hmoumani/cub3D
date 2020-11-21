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

int		ft_count_char(char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_treat_f(char **ptr, int count)
{
	char	**p;
	int		r;
	int		g;
	int		b;
	char	*rgb;

	if (g_conf.f != -1)
		ft_error("floor color repeated.\n");
	rgb = ft_join_file(ptr, count);
	p = ft_split(rgb, ',', ft_count_words(ptr[1], ','));
	if (ft_ptr_str_len(p) != 3 || ft_count_char(rgb, ',') != 2)
		ft_error("fix argument for floor color.\nusage: F r,g,b\n");
	r = ft_atoi(p[0], 0);
	g = ft_atoi(p[1], 0);
	b = ft_atoi(p[2], 0);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		ft_error("R,G,B colors should be numbers in range[0,255].\n");
	g_conf.f = create_trgb(0, r, g, b);
	g_conf.count++;
	free(rgb);
	ft_failed(p, ft_count_words(ptr[1], ','));
}
