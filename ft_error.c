/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:35:03 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/07 18:35:04 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void			ft_free_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_conf.max_height)
	{
		free(g_conf.map[i]);
		i++;
	}
	free(g_conf.map);
}

void			ft_error(char *s)
{
	free(g_rays);
	ft_lstclear(&g_conf.head, free);
	ft_lstclear(&g_conf.sprite_head, free);
	ft_free_map();
	if (g_env.ptr && g_env.win)
		mlx_destroy_window(g_env.ptr, g_env.win);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(s, 1);
	exit(1);
}
