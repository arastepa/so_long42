#include "so_long.h"

void initmap(t_solong *data)
{
    data->map = NULL;
    data->x = 0;
    data->y = 0;
    data->collect = 0;
    data->playerx = -1;
    data->playery = -1;
    data->counter = 0;
}

void initplayer(t_solong *data,  int y, int i)
{
    if (!(data->playerx < 0 && data->playery < 0))
        ft_exit(data, "must be only one player\n");
    data->playerx = i;
    data->playery = y;
}