#include "so_long.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_color(t_image *dat, int texx, int texy)
{
	char	*dst;

	dst = dat->addr + (texy * dat->linelen + texx * (dat->bpp / 8));
	return (*(unsigned int *)dst);
}

t_image selecttext(char value, t_solong *data)
{
    if (value == '1')
        return (data->texwall);
    else if (value == '0')
        return (data->texfloor);
    else if (value == 'P')
        return (data->texpl[0]);
    else if (value == 'C')
        return (data->texcol);
    else if (value == 'E')
        return (data->texexit);
}

void drawcolor(t_solong *data, int i, int j, char value)
{
    int y;
    int x;
    int texx;
    int texy;
    unsigned int color;

    y = 0;
    while (y < data->unitsize)
    {
        x = 0;
        while (x < data->unitsize)
        {
            if (value == '0')
            {
                x++;
                continue;
            }
            data->current = selecttext(value, data);
            texx = (int)((float)x / data->unitsize * data->current.width);
	        texy = (int)((float)y / data->unitsize * data->current.height);
            color = get_color(&data->current, texx, texy);
            if (color !=  0xFF000000)
                my_mlx_pixel_put(&(data->main_img), data->unitsize * j + x\
                , data->unitsize * i + y, color);
            x++;
        }
        y++;
    }
}

void draw(t_solong *data)
{
    int i;
    int j;
    char value;

    setunitsize(data);
    data->win = mlx_new_window(data->mlx, data->unitsize * data->x, data->unitsize * data->y, "Hello world!");
   	data->main_img.ptr = mlx_new_image(data->mlx, data->unitsize * data->x, data->unitsize * data->y);
    data->main_img.addr = mlx_get_data_addr(data->main_img.ptr, &(data->main_img.bpp), &(data->main_img.linelen),\
								&(data->main_img.endian));
    i = 0;
    while (i < data->y)
    {
        j = 0;
        while ( j < data->x)
        {
            value = data->map[i][j];
            drawfloor(data, i, j);
            drawcolor(data, i, j, value);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->main_img.ptr, 0, 0);
    mlx_hook(data->win, 17, 0, ft_close, data);
    mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop(data->mlx);
}