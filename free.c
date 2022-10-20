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
    freemap(data);
    exit(0);
}