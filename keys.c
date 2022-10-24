#include "so_long.h"

int ft_close(t_solong *data)
{
    ft_exit(data, "");
}

int key_press(int keycode, t_solong *data)
{
    if (keycode == KEY_ESC)
        ft_close(data);
}