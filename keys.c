#include "so_long.h"

int ft_close(t_solong *data)
{
    ft_exit(data, "");
}

int move(t_solong *data, int y)
{
    int t;

    t = 0;
    data->map[data->playery][data->playerx] = '0';
    if (data->map[y][data->playerx] == '1')
        ;
    else if (data->map[y][data->playerx] == 'C')
    {
        data->map[y][data->playerx] = '0';
        data->collect--;
        data->playery = y;
        t = 1;
    }
    else if (data->map[y][data->playerx] == 'E')
    {
        if (data->collect == 0)
            ft_close(data);
    }
    else if (data->map[y][data->playerx] == '0')
    {
        data->playery = y;
        t = 1;
    }
    data->map[data->playery][data->playerx] = 'P';
    return (t);
}

int movehor(t_solong *data, int x)
{
    int t;

    t = 0;
    data->map[data->playery][data->playerx] = '0';
    if (data->map[data->playery][x] == '1')
        ;
    else if (data->map[data->playery][x] == 'C')
    {
        data->map[data->playery][x] = '0';
        data->collect--;
        data->playerx = x;
        t = 1;
    }
    else if (data->map[data->playery][x] == 'E')
    {
        if (data->collect == 0)
            ft_close(data);
    }
    else if (data->map[data->playery][x] == '0')
    {
        data->playerx = x;
        t = 1;
    }
    data->map[data->playery][data->playerx] = 'P';
    return (t);

}

int key_press(int keycode, t_solong *data)
{
    if (keycode == KEY_ESC)
        ft_close(data);
    if (keycode == KEY_W)
    {
        if (move(data, data->playery - 1))
        {
            data->counter++;
            ft_putnbr_fd(data->counter, 1);
            ft_putstr_fd(" moves\n", 1);
        }
        drawall(data);
    }
    else if (keycode == KEY_A)
    {
        if (movehor(data, data->playerx - 1))
        {
            data->counter++;
            ft_putnbr_fd(data->counter, 1);
            ft_putstr_fd(" moves\n", 1);
        }
        drawall(data);
    }
    else if (keycode == KEY_S)
    {
        if (move(data, data->playery + 1))
        {
            data->counter++;
            ft_putnbr_fd(data->counter, 1);
            ft_putstr_fd(" moves\n", 1);
        }
         drawall(data);
    }
    else if (keycode == KEY_D)
    {
        if (movehor(data, data->playerx + 1))
        {
            data->counter++;
            ft_putnbr_fd(data->counter, 1);
            ft_putstr_fd(" moves\n", 1);
        }
        drawall(data);
    }
}