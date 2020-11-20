# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 17:50:28 by hmoumani          #+#    #+#              #
#    Updated: 2020/10/18 17:50:32 by hmoumani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -g cub3d.c \
	file.c \
	ft_atoi.c \
	ft_handle_map.c \
	ft_lstadd_back_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_error.c \
	ft_putstr_fd.c \
	ft_redirect_to.c \
	ft_split.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_substr.c \
	ft_treat_c.c \
	ft_treat_ea.c \
	ft_treat_f.c \
	ft_treat_no.c \
	ft_treat_res.c \
	ft_treat_so.c \
	ft_treat_spr.c \
	ft_treat_we.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_cast_ray.c \
	ft_generate_3d.c \
	ft_draw_functions.c \
	ft_exit.c \
	ft_join_space.c \
	-I /usr/local/include -L /usr/local/bin -lmlx -framework OpenGl -framework AppKit libmlx.dylib -fsanitize=address \
	-o cub3D