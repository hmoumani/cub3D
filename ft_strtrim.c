/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:04:31 by hmoumani          #+#    #+#             */
/*   Updated: 2019/10/25 13:01:01 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static	int		ft_check(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	int		i;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	trim = NULL;
	while (s1[i] != '\0' && ft_check(s1[i], set))
		i++;
	while (s1_len > 0 && ft_check(s1[s1_len - 1], set))
		s1_len--;
	if (i > (s1_len - 1))
		return (ft_strdup(""));
	trim = ft_substr(s1, i, (s1_len - i));
	return (trim);
}
