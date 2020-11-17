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

void    ft_check_player(int i, int j, char c)
{
    if (g_player.found)
        ft_print_error("player duplicated\n");
    ft_check_zero(i, j);
    if (c == 'W')
        g_player.angle = 0;
    else if (c == 'E')
        g_player.angle = 0;
    else if (c == 'S')
        g_player.angle = 0;
    else if (c == 'N')
        g_player.angle = 0;
    g_player.default_i = i * TILE_SIZE;
    g_player.default_j = j * TILE_SIZE;
    player.pos.x = i * TILE_SIZE;
    player.pos.y = j * TILE_SIZE;
    g_player.found = 1;
}

void    ft_check_zero(int i, int j)
{
	int error;
    char **mp;

	error = 0;
    mp = g_conf.map;
    if (i - 1 < 0 || j - 1 < 0 || i + 1 >= g_conf.max_height || j + 1 >= g_conf.max_width)
        error = 1;
	else if (mp[i - 1][j] == ' ' || mp[i + 1][j] == ' ')
        error = 1;
    else if (mp[i][j - 1] == ' ' || mp[i][j + 1] == ' ')
        error = 1;
    if (error)
    {
        printf("Error\nError in map file");
        printf("%d, %d, %c\n", i, j, mp[i][j]);
        exit(1);
    }
	// else if (g_conf.map[i - 1] == ' ')
}

int				ft_check_sprite(int i, int j, char c)
{
    ft_check_zero(i, j);
    // ft_lstadd_back(&g_conf.sprite_head, ft_lstnew();
    return (0);
}

void    ft_handle_map()
{
    int     i;
    t_list  *curr;
	int left;
	int j;
    char c;

    i = 0;
	j = 0;
    g_conf.max_width++;
    int w = g_conf.max_width;
    g_conf.max_height = ft_lstsize(g_conf.head);
    int h = g_conf.max_height;
    g_conf.map = malloc(g_conf.max_height * sizeof(char *));
    curr = g_conf.head;
    while (i < g_conf.max_height)
    {
        g_conf.map[i] = malloc((g_conf.max_width) * sizeof(char));
        left = ft_strlcpy(g_conf.map[i], curr->content, g_conf.max_width);
        i++;
        curr = curr->next;
    }
    i = 0;
    while (i < g_conf.max_height)
    {
        j = 0;
        // printf("%d\n", i);
		while (j < g_conf.max_width)
        {
            c = g_conf.map[i][j];
            if (c == '0')
    	        ft_check_zero(i, j);
            else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
                ft_check_player(i, j, c);
            else if (c == '2')
                ft_check_sprite(i, j, c);
            j++;
        }
        // printf("\n");
        i++;
    }
    if (!g_player.found)
        ft_print_error("player 404\n");
}