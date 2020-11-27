/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:45:26 by hmoumani          #+#    #+#             */
/*   Updated: 2020/11/21 14:45:28 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_init_header(unsigned char *header, t_header *info, int i)
{
	info->width = g_conf.win_w;
	info->height = g_conf.win_h;
	info->bitcount = 24;
	info->bi_planes = 1;
	info->w_in_b = ((info->width * info->bitcount + 31) / 32) * 4;
	info->image_size = info->w_in_b * info->height;
	info->bi_size = 40;
	info->bf_off_bits = 54;
	info->file_size = 54 + info->image_size;
	info->data = (int *)mlx_get_data_addr(g_env.img, &i, &i, &i);
	info->row = info->height - 1;
	info->col = 0;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &info->file_size, 4);
	ft_memcpy(header + 10, &info->bf_off_bits, 4);
	ft_memcpy(header + 14, &info->bi_size, 4);
	ft_memcpy(header + 18, &info->width, 4);
	ft_memcpy(header + 22, &info->height, 4);
	ft_memcpy(header + 26, &info->bi_planes, 2);
	ft_memcpy(header + 28, &info->bitcount, 2);
	ft_memcpy(header + 34, &info->image_size, 4);
}

void	fill_image(unsigned char *header, t_header header_info, char *buf)
{
	int fout;

	fout = open("test.bmp", O_WRONLY | O_CREAT, 0644);
	write(fout, header, 54);
	write(fout, buf, header_info.image_size);
	close(fout);
	free(header_info.buf);
	free(header);
	ft_exit();
}

void	ft_screenshot(void)
{
	int				*color;
	t_header		info;
	unsigned char	*header;

	header = ft_calloc(54, sizeof(unsigned char));
	ft_init_header(header, &info, 10);
	if (!(info.buf = malloc(info.image_size)))
		ft_error("malloc failed");
	while (info.row > 0)
	{
		info.col = 0;
		while (info.col < info.width)
		{
			color = get_colors(info.data[(g_conf.win_h - info.row) * \
				g_conf.win_w + info.col]);
			info.buf[info.row * info.w_in_b + info.col * 3 + 0] = color[2];
			info.buf[info.row * info.w_in_b + info.col * 3 + 1] = color[1];
			info.buf[info.row * info.w_in_b + info.col * 3 + 2] = color[0];
			free(color);
			info.col++;
		}
		info.row--;
	}
	fill_image(header, info, (char *)info.buf);
}
