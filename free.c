#include "so_long.h"

void freemap(t_solong *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->y)
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
}

void ft_exit(t_solong *data, char *msg)
{
    write(1, msg, ft_strlen(msg));
    if (data->texcol.ptr)
        mlx_destroy_image(data->mlx, data->texcol.ptr);
    if (data->texcol.ptr)
        mlx_destroy_image(data->mlx, data->texfloor.ptr);
    if (data->texexit.ptr)
        mlx_destroy_image(data->mlx, data->texexit.ptr);
    if (data->texpl[0].ptr)
        mlx_destroy_image(data->mlx, data->texpl[0].ptr);
    if  (data->texwall.ptr)
        mlx_destroy_image(data->mlx, data->texwall.ptr);
    if (data->main_img.ptr)
        mlx_destroy_image(data->mlx, data->main_img.ptr);
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    freemap(data);
    exit(0);
}