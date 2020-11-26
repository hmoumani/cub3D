/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:24:56 by hmoumani          #+#    #+#             */
/*   Updated: 2019/10/25 15:23:04 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		has_sp(t_position pos)
{
	int x;
	int y;

	y = floor(pos.y / TILE_SIZE);
	x = floor(pos.x / TILE_SIZE);
	if (x < 0 || x > g_conf.max_height - 1 || y < 0 || \
	y > g_conf.max_width - 1)
		return (TRUE);
	return (g_conf.map[x][y] == '2');
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
