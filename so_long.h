#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include "stdio.h"
#include <fcntl.h>
#include "mlx_linux/mlx.h"
# define SCREEN_WIDTH 1300
# define SCREEN_HEIGHT 800
typedef struct s_image
{
    void *ptr;
    char *addr;
    int linelen;
    int endian;
    int width;
    int height;
    int bpp;
}               t_image;

typedef struct s_solong
{
    char **map;
    int y;
    int x;
    int collect;
    int playerx;
    int playery;
   	t_image		texwall;
	t_image		texpl[3];
	t_image		texcol;
	t_image		texexit;
	t_image		texfloor;
    int cubwidth;
    int cubheight;
    void *mlx;
    void *win;
    t_image main_img;
    t_image current;
    int unitsize;
}               t_solong;


void drawfloor(t_solong *data, int i, int j);
void initmap(t_solong *data);
int valid_parameter(char *str);
void parse(int fd, char *f);
void ft_exit(t_solong *data, char *msg);
void freemap(t_solong *data);
void initplayer(t_solong *data, int y, int i);
void gentextures(t_solong *data);
void draw(t_solong *data);
void setunitsize(t_solong *data);

#endif