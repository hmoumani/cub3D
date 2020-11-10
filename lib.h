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

#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <math.h>
#include <limits.h>

#define False 0
#define True 1
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100
#endif


#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 60
#define MAP_COLS 30
#define MAP_ROWS 15
#define WINDOW_WIDTH (MAP_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_ROWS * TILE_SIZE)
#define PLAYER_R TILE_SIZE / 4

#define FOV_ANGLE (60 *(PI / 180))
#define NUM_RAYS WINDOW_WIDTH

typedef struct	s_list
{
	void			*content;
	struct	s_list	*next;
}				t_list;


typedef struct	s_texture
{
	void    *img;
	int		height;
	int		width;

}				t_texture;

typedef struct  s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef	struct s_player
{
	float	angle;
	int		default_i;
	int		default_j;
	int		found;
}				t_player;


typedef struct  s_config
{
    int     	win_h;
	int     	win_w;
	t_rgb		f;
	t_rgb		c;
    t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	spr;
	int			count;
	int			max_width;
	int			max_height;
	t_list		*head;
	char		**map;
	int			map_start;
}               t_config;

t_config g_conf;

typedef struct s_mlx_info{
    void *ptr;
    void *win;
    void *img;
    char *addr;
    int		bpp;
	int		line_length;
	int		endian;
}               t_mlx_info;

t_mlx_info	g_env;
t_player	g_player;

// typedef struct s_position
// {
//     float x;
//     float y;
// }               t_position;

// typedef struct s_player
// {
//     t_position pos;
//     int turnDirection;
//     int walkDirection;
//     float rotationAngle;
//     float walkSpeed;
//     float turnSpeed;
// }               t_player;
// t_player player;


// struct  s_color
// {
//     const int RED;
//     const int BLUE;
//     const int GREEN;
//     const int BLACK;
// }       color = {0xFF0000, 0x0000FF, 0x00FF00, 0x000000};

// struct s_ray
// {
//     float rayAngle;
//     float wallHitX;
//     float wallHitY;
//     float distance;
//     int wasHitVert;
//     int isRayDown;
//     int isRayRight;
// }       rays[NUM_RAYS];


// int worldMap[15][30] =
// {
//     {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
//     {'1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
//     {'1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
//     {'1','0','1','1','0','0','N','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
//     {'1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','1','1','1','0','1','1','1','1','0','0','0','0','1'},
//     {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','0','1'},
//     {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','0','1','0','0','1','0','0','0','0','1'},
//     {'1','1','0','0','0','0','0','0','1','1','0','1','0','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','0','1'},
//     {'1','0','0','0','2','0','0','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','1','0','0','0','0','1'},
//     {'1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','1','0','1','0','1','0','0','1','0','0','0','0','1'},
//     {'1','1','0','0','0','0','0','0','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','1','0','0','0','0','1'},
//     {'1','1','1','1','0','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','1','1','1','0','0','0','0','1'},
//     {'1','1','1','1','0','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','1','1','1','0','0','0','0','1'},
//     {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
// };

char			**ft_split(char const *s, char c, int count);
int				ft_count_words(char *str, char c);
void	        ft_putstr_fd(char *s, int fd);
void            ft_redirect_to(char **ptr);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_ptr_str_len(char **ptr);
void			ft_treat_res(char **ptr);
int				ft_atoi(const char *str);
void    		ft_treat_no(char **ptr);
int				ft_is_end_with(char *s, char *s1);
void			ft_treat_so(char **ptr);
void			ft_treat_we(char **ptr);
void			ft_treat_ea(char **ptr);
void    		ft_treat_spr(char **ptr);
void			ft_treat_f(char **ptr);
void			ft_treat_c(char **ptr);
void			ft_read_map(char *line);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
t_list			*ft_lstlast(t_list *lst);
void			ft_handle_map();
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			ft_print_error(char *s);
void    		ft_check_zero(int i, int j);
void    		ft_check_player(int i, int j, char c);

