/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:01:13 by hmoumani          #+#    #+#             */
/*   Updated: 2019/10/28 14:02:31 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_left_or_right(void)
{
	float x_to_check;
	float y_to_check;

	if (!g_player.left_right)
		return ;
	x_to_check = cos((g_player.rotation_angle + ft_rad(g_player.left_right))) \
	* 40 + g_player.pos.x;
	y_to_check = sin((g_player.rotation_angle + \
	ft_rad(g_player.left_right))) * 40 + g_player.pos.y;
	if (!has_wall((t_position){x_to_check, y_to_check}))
	{
		g_player.pos.x = x_to_check;
		g_player.pos.y = y_to_check;
	}
	g_player.left_right = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
