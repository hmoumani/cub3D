/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:53:41 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/19 11:53:43 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			has_screen(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!strcmp(argv[i], "--save"))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_exit(void)
{
	mlx_destroy_window(g_env.ptr, g_env.win);
	exit(0);
}
