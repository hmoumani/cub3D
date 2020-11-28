/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:32:48 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/22 18:32:49 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_calcul_dist(void)
{
	t_list	*curr;
	int		x;
	int		y;

	curr = g_conf.sprite_head;
	while (curr)
	{
		x = ((t_sprit *)curr->content)->x;
		y = ((t_sprit *)curr->content)->y;
		((t_sprit *)curr->content)->dis = distance_between(g_player.pos.x, \
		g_player.pos.y, x, y);
		curr = curr->next;
	}
}

void	sort_linked_list(t_list *start)
{
	t_list	*node;
	t_list	*temp;
	t_sprit	*tempvar;

	node = start;
	while (node != NULL)
	{
		temp = node;
		while (temp->next != NULL)
		{
			if (((t_sprit *)temp->content)->dis < \
			((t_sprit *)temp->next->content)->dis)
			{
				tempvar = (t_sprit *)temp->content;
				temp->content = temp->next->content;
				temp->next->content = (void *)tempvar;
			}
			temp = temp->next;
		}
		node = node->next;
	}
}

void	ft_rndr_sprit(void)
{
	t_list *curr;

	curr = g_conf.sprite_head;
	sort_linked_list(curr);
	while (curr)
	{
		render_sprite((t_sprit *)curr->content);
		curr = curr->next;
	}
}
