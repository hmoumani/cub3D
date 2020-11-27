/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:32:09 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/06 09:32:13 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_check_g_player(int i, int j, char c)
{
	if (g_player.found)
		ft_error("g_player duplicated\n");
	ft_check_zero(i, j);
	if (c == 'W')
		g_player.rotation_angle = ft_rad(270);
	else if (c == 'E')
		g_player.rotation_angle = ft_rad(90);
	else if (c == 'S')
		g_player.rotation_angle = ft_rad(0);
	else if (c == 'N')
		g_player.rotation_angle = ft_rad(180);
	g_player.default_i = i * TILE_SIZE + ((int)TILE_SIZE / 2);
	g_player.default_j = j * TILE_SIZE + ((int)TILE_SIZE / 2);
	g_player.pos.x = i * TILE_SIZE + ((int)TILE_SIZE / 2);
	g_player.pos.y = j * TILE_SIZE + ((int)TILE_SIZE / 2);
	g_player.found = 1;
}

void	ft_check_zero(int i, int j)
{
	int		error;
	char	**mp;

	error = 0;
	mp = g_conf.map;
	if (i - 1 < 0 || j - 1 < 0 || i + 1 >= g_conf.max_height \
	|| j + 1 >= g_conf.max_width)
		error = 1;
	else if (mp[i - 1][j] == ' ' || mp[i + 1][j] == ' ')
		error = 1;
	else if (mp[i][j - 1] == ' ' || mp[i][j + 1] == ' ')
		error = 1;
	if (error)
	{
		ft_error("Error in map file");
		exit(1);
	}
}

int		ft_check_sprite(int i, int j)
{
	t_sprit *temp;

	ft_check_zero(i, j);
	temp = (t_sprit *)malloc(sizeof(t_sprit));
	temp->x = i * TILE_SIZE + 30;
	temp->y = j * TILE_SIZE + 30;
	ft_lstadd_back(&g_conf.sprite_head, ft_lstnew((void *)temp));
	return (0);
}

void	ft_iter_map(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < g_conf.max_height)
	{
		j = 0;
		while (j < g_conf.max_width)
		{
			c = g_conf.map[i][j];
			if (c == '0')
				ft_check_zero(i, j);
			else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
				ft_check_g_player(i, j, c);
			else if (c == '2')
				ft_check_sprite(i, j);
			j++;
		}
		i++;
	}
	if (!g_player.found)
		ft_error("g_player 404\n");
}

void	ft_handle_map(void)
{
	int		i;
	t_list	*curr;
	int		left;
	int		j;

	i = 0;
	j = 0;
	g_conf.max_width++;
	g_conf.max_height = ft_lstsize(g_conf.head);
	if (!(g_conf.map = malloc(g_conf.max_height * sizeof(char *))))
		ft_error("malloc failed");
	curr = g_conf.head;
	while (i < g_conf.max_height)
	{
		if (!(g_conf.map[i] = malloc((g_conf.max_width) * sizeof(char))))
			ft_error("malloc failed");
		left = ft_strlcpy(g_conf.map[i], curr->content, g_conf.max_width);
		i++;
		curr = curr->next;
	}
	ft_iter_map();
}
