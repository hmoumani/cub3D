/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:17:21 by hmoumani          #+#    #+#             */
/*   Updated: 2020/10/18 18:17:24 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# define FALSE 0
# define TRUE 1
# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H
#  define BUFFER_SIZE 100
# endif
# define PI 3.14159265
# define TWO_PI 6.28318530
# define TILE_SIZE 64
# define FOV_ANGLE (60 *(PI / 180))

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_texture
{
	void			*img;
	unsigned int	*addr;
	int				height;
	int				width;
	int				bpp;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef	struct		s_config
{
	int				win_h;
	int				win_w;
	int				f;
	int				c;
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		spr;
	int				count;
	int				max_width;
	int				max_height;
	t_list			*head;
	char			**map;
	int				map_start;
	int				map_end;
	t_list			*sprite_head;
	int				num_rays;
}					t_config;

t_config			g_conf;

typedef struct		s_mlx_info{
	void			*ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_mlx_info;

t_mlx_info			g_env;

typedef struct		s_position
{
	float			x;
	float			y;
}					t_position;

typedef struct		s_sg_player
{
	t_position		pos;
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
	float			walk_speed;
	float			turn_speed;
	int				left_right;
	float			angle;
	int				default_i;
	int				default_j;
	int				found;
}					t_sg_player;

t_sg_player			g_player;

typedef struct		s_ray
{
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			distance;
	int				was_hit_vert;
	int				is_ray_down;
	int				is_ray_right;
}					t_ray;

t_ray				*g_rays;

int					mlx_get_screen_size(void *ptr, int *w, int *h);
void				ft_exit();
int					ft_count_char(char *str, char c);
float				ft_rad(float num);
float				ft_sign(float num);
int					has_wall(t_position pos);
float				normalizeangle(float ray_angle);
void				put_my_pixel(int x, int y, int color);
char				**ft_split(char const *s, char c, int count);
int					ft_hor_line(int x, int y, int color, int size);
int					ft_count_words(char *str, char c);
void				ft_putstr_fd(char *s, int fd);
void				ft_redirect_to(char **ptr, int count);
char				*ft_join_space(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_square(int x, int y, int color, int size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				**ft_failed(char **tab, int n);
char				*ft_join_file(char **ptr, int count);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				draw_ray(float angle, float d, int color);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
int					get_next_line(int fd, char **line);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_ptr_str_len(char **ptr);
void				ft_treat_res(char **ptr);
int					ft_atoi(const char *str, int i);
void				ft_treat_no(char **ptr, int count);
int					ft_is_end_with(char *s, char *s1);
void				ft_treat_so(char **ptr, int count);
void				ft_treat_we(char **ptr, int count);
void				ft_treat_ea(char **ptr, int count);
void				ft_treat_spr(char **ptr, int count);
void				ft_treat_f(char **ptr, int count);
void				ft_treat_c(char **ptr, int count);
void				ft_read_map(char *line);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
void				ft_handle_map();
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_error(char *s);
void				ft_check_zero(int i, int j);
void				ft_check_g_player(int i, int j, char c);
void				file(int argc, char **argv, int r);
int					ft_check_sprite(int i, int j);
int					ft_is_empty(char *line);
void				ft_cast_ray(float ray_angle, int id);
float				distance_between(float x1, float y1, float x2, float y2);
void				ft_generate_3d(int i, int y, float distance_pro, \
float projected_wall);
int					create_trgb(int t, int r, int g, int b);
void				ft_left_or_right();

#endif
