/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:42:17 by hmoumani          #+#    #+#             */
/*   Updated: 2019/10/26 00:03:14 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*p;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[i] != '\0')
		i++;
	if (len > i)
		len = i;
	p = (char *)malloc(((len + 1) * sizeof(char)));
	i = 0;
	if (p == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		p[i] = s[i + start];
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
