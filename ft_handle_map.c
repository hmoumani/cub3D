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



void    ft_handle_map()
{
    int     i;
    t_list  *curr;
	int left;
	int j;

    i = 0;
	j = 0;
    g_conf.max_height = ft_lstsize(g_conf.head->next);
    g_conf.map = malloc(g_conf.max_height * sizeof(char *));
    curr = g_conf.head->next;
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
		// while (j < g_conf.max_width)
        printf("%s\n", g_conf.map[i++]);
    }
	// ft_check_zero();
	// ft_check_player();
}