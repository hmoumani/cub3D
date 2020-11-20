/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:37:40 by hmoumani          #+#    #+#             */
/*   Updated: 2019/11/03 00:24:38 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (*alst == NULL)
		*alst = new;
	else if (alst)
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}
