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
	gcc -I /usr/local/include *.c -L /usr/local/bin -lmlx -framework OpenGl -framework AppKit -g -fsanitize=address