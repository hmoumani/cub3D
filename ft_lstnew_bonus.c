/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:51:58 by hmoumani          #+#    #+#             */
/*   Updated: 2019/11/02 01:30:06 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		ft_error("malloc failed");
	if (!new)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}
