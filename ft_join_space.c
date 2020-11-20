/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:59:19 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/20 18:59:20 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_join_space(char const *s1, char const *s2)
{
	int		i;
	int		s1size;
	int		s2size;
	char	*p;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	if (!(p = (char *)ft_calloc(s1size + s2size + 2, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < s1size + s2size + 1)
	{
		if (i < s1size)
			p[i] = (char)s1[i];
		else if (i == s1size)
			p[i] = ' ';
		else
			p[i] = (char)s2[j++];
		i++;
	}
	return (p);
}
