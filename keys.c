#include "so_long.h"

int ft_close(t_solong *data)
{
    ft_exit(data, "");
}

void move(t_solong *data, int y)
{
    data->map[data->playery][data->playerx] = '0';
    if (data->map[y][data->playerx] == '1')
        ;
    else if (data->map[y][data->playerx] == 'C')
    {
        data->map[y][data->playerx] = '0';
        data->collect--;
        data->playery = y;
    }
    else if (data->map[y][data->playerx] == 'E')
    {
        if (data->collect == 0)
            ft_close(data);
    }
    else if (data->map[y][data->playerx] == '0')
        data->playery = y;
    data->map[data->playery][data->playerx] = 'P';
}

void movehor(t_solong *data, int x)
{
    data->map[data->playery][data->playerx] = '0';
    if (data->map[data->playery][x] == '1')
        ;
    else if (data->map[data->playery][x] == 'C')
    {
        data->map[data->playery][x] = '0';
        data->collect--;
        data->playerx = x;
    }
    else if (data->map[data->playery][x] == 'E')
    {
        if (data->collect == 0)
            ft_close(data);
    }
    else if (data->map[data->playery][x] == '0')
        data->playerx = x;
    data->map[data->playery][data->playerx] = 'P';

}

int key_press(int keycode, t_solong *data)
{
    if (keycode == KEY_ESC)
        ft_close(data);
    if (keycode == KEY_W)
    {
        move(data, data->playery - 1);
        drawall(data);
    }
    else if (keycode == KEY_A)
    {
        movehor(data, data->playerx - 1);
        drawall(data);
    }
    else if (keycode == KEY_S)
    {
         move(data, data->playery + 1);
         drawall(data);
    }
    else if (keycode == KEY_D)
    {
        movehor(data, data->playerx + 1);
        drawall(data);
    }
}