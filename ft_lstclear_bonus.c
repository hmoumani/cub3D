/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 23:00:23 by hmoumani          #+#    #+#             */
/*   Updated: 2019/11/03 00:14:10 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	t_list *curr;

	if (lst && del)
	{
		temp = *lst;
		curr = *lst;
		while (temp != NULL)
		{
			curr = temp;
			temp = temp->next;
			del(curr->content);
			free(curr);
		}
		*lst = NULL;
	}
}
