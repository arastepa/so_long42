#include "so_long.h"

void setunitsize(t_solong *data)
{
    int	nativeh;
	int	nativew;

	mlx_get_screen_size(data->mlx, &nativew, &nativeh);
    if (data->y > data->x)
        data->unitsize = (int)(nativeh * 0.80 / data->y);
    else
         data->unitsize = (int)(nativew * 0.80 / data->x);
}

void drawfloor(t_solong *data, int i, int j)
{
    int texx;
    int texy;
    int x;
    int y;

     y = 0;
    while (y < data->unitsize)
    {
        x = 0;
        while (x < data->unitsize)
        {
            texx = (int)((float)x / data->unitsize * data->texfloor.width);
            texy = (int)((float)y / data->unitsize * data->texfloor.height);
            if (get_color(&data->texfloor, texx, texy) !=  0xFF000000)
                my_mlx_pixel_put(&(data->main_img), data->unitsize * j + x\
                , data->unitsize * i + y,  get_color(&data->texfloor, texx, texy));
            x++;
        }
        y++;
    }
}
