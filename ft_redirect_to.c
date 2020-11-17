/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:14:47 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/02 11:14:49 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

size_t      ft_ptr_str_len(char **ptr)
{
    size_t len;

    len = 0;
    while (ptr[len])
        len++;
    return (len);
}

char		*ft_missing()
{
	if (g_conf.win_h == -1)
        return ("Resolution");
	else if (g_conf.no.height == -1)
        return ("North texture");
	else if (g_conf.so.height == -1)
        return ("South texture");
	else if (g_conf.we.height == -1)
        return ("West texture");
	else if (g_conf.ea.height == -1)
        return ("East texture");
	else if (g_conf.spr.height == -1)
        return ("Sprite texture");
	else if (g_conf.f == -1)
        return ("floor texture");
	else if (g_conf.c == -1)
        return ("Ceilling texture");
	return "smth";
}

int         ft_is_end_with(char *s, char *s1)
{
    int len;
    int i;
    int len1;

    len = ft_strlen(s);
    len1 = ft_strlen(s1);
    i = 0;
    while (len - i >= 0)
    {
        if (s[len - i] != s1[len1 - i])
            return (0);
        if (i == len1)
            return (1);
        i++;
    }
    return (1);
}

void        ft_redirect_to(char **ptr)
{
    if (!ptr[0])
        return;
    else if (!strncmp(ptr[0], "R", 2))
        ft_treat_res(ptr);
    else if (!strncmp(ptr[0], "NO", 3))
        ft_treat_no(ptr);
    else if (!strncmp(ptr[0], "SO", 3))
        ft_treat_so(ptr);
    else if (!strncmp(ptr[0], "WE", 3))
        ft_treat_we(ptr);
    else if (!strncmp(ptr[0], "EA", 3))
        ft_treat_ea(ptr);
    else if (!strncmp(ptr[0], "S", 2))
        ft_treat_spr(ptr);
    else if (!strncmp(ptr[0], "F", 2))
        ft_treat_f(ptr);
    else if (!strncmp(ptr[0], "C", 2))
        ft_treat_c(ptr);
    else
    {
        ft_putstr_fd("Error\nmap file is misconfigured", 1);
        exit(1);
    }
}
