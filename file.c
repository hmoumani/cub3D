/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:03:49 by hmoumani          #+#    #+#             */
/*   Updated: 2020/10/23 12:04:04 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_init_config(char **line)
{
	g_conf.win_h = -1;
	g_conf.win_w = -1;
	g_conf.f = -1;
	g_conf.c = -1;
	g_conf.no = (t_texture){NULL, NULL, -1, -1, -1, -1, -1};
	g_conf.so = (t_texture){NULL, NULL, -1, -1, -1, -1, -1};
	g_conf.we = (t_texture){NULL, NULL, -1, -1, -1, -1, -1};
	g_conf.ea = (t_texture){NULL, NULL, -1, -1, -1, -1, -1};
	g_conf.spr = (t_texture){NULL, NULL, -1, -1, -1, -1, -1};
	g_conf.count = 0;
	g_conf.max_width = 0;
	*line = NULL;
	g_conf.head = NULL;
	g_conf.map_start = 0;
	g_conf.map_end = 0;
	g_conf.sprite_head = NULL;
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.rotation_angle = ft_rad(0);
	g_player.walk_speed = 10;
	g_player.turn_speed = ft_rad(10);
}

void	ft_read_conf(char *line)
{
	char	**ptr;
	int		count;

	count = ft_count_words(line, ' ');
	if ((ptr = ft_split(line, ' ', count)) == NULL)
	{
		ft_putstr_fd("Error\nrestart the game please", 1);
		exit(1);
	}
	ft_redirect_to(ptr, count, line);
	ft_failed(ptr, count);
}

void	ft_read_map(char *line)
{
	int		len;
	t_list	*new;

	g_conf.map_start = 1;
	len = ft_strlen(line);
	g_conf.max_width = g_conf.max_width > len ? g_conf.max_width : len;
	new = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(&g_conf.head, new);
}

void	file(int argc, char **argv, int r)
{
	int		fd;
	char	*line;

	if (argc < 2)
		ft_error("usag: ./Cub3d MAPFILE.cub [--save]");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("Error\n");
		exit(1);
	}
	ft_init_config(&line);
	while (r > 0)
	{
		r = get_next_line(fd, &line);
		if (g_conf.count != 8)
			ft_read_conf(line);
		else if (ft_is_empty(line) && g_conf.map_start && !g_conf.map_end)
			g_conf.map_end = 1;
		else if (!ft_is_empty(line) && g_conf.map_end)
			ft_error("map missconfigured");
		else if (!ft_is_empty(line))
			ft_read_map(line);
		free(line);
	}
	ft_handle_map();
}
