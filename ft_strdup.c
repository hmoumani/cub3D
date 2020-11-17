/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:06:34 by hmoumani          #+#    #+#             */
/*   Updated: 2019/10/17 21:19:53 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(const char *s)
{
	char			*p;
	unsigned	int	i;
	size_t			len;


	i = 0;
	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		*(p + i) = *(s + i);
		i++;
	}
	*(p + i) = 0;
	return (p);
}
