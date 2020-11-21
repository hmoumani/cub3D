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


void    ft_screenshot()
{
	int *color;
	int32_t width = g_conf.win_w;
	int32_t height = g_conf.win_h;
	uint16_t bitcount = 24;//<- 24-bit bitmap
	int i;

	i = 0;
	int width_in_bytes = ((width * bitcount + 31) / 32) * 4;
	uint32_t imagesize = width_in_bytes * height;
	const uint32_t biSize = 40;
	const uint32_t bfOffBits = 54; 
	uint32_t filesize = 54 + imagesize;
	int         *data;
	const uint16_t biPlanes = 1;

	unsigned char header[54] = { 0 };
	memcpy(header, "BM", 2);
	memcpy(header + 2 , &filesize, 4);
	memcpy(header + 10, &bfOffBits, 4);
	memcpy(header + 14, &biSize, 4);
	memcpy(header + 18, &width, 4);
	memcpy(header + 22, &height, 4);
	memcpy(header + 26, &biPlanes, 2);
	memcpy(header + 28, &bitcount, 2);
	memcpy(header + 34, &imagesize, 4);

	data = (int *)mlx_get_data_addr(g_env.img, &i, &i, &i);
	unsigned char* buf = malloc(imagesize);
	for(int row = height - 1; row >= 0; row--)
	{
		for(int col = 0; col < width; col++)
		{
			color = get_colors(data[(g_conf.win_h - row) * g_conf.win_w + col]);
			buf[row * width_in_bytes + col * 3 + 0] = color[2];// blue
			buf[row * width_in_bytes + col * 3 + 1] = color[1];// green
			buf[row * width_in_bytes + col * 3 + 2] = color[0];// red
			free(color);
		}
	}
	int fout = open("test.bmp", O_WRONLY | O_CREAT, 0644);
	write(fout, header, 54);
	write(fout, (char *)buf, imagesize);
	close(fout);
	free(buf);
}