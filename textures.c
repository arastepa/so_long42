#include "so_long.h"

void gentextures1(t_solong *data)
{
    data->texwall.ptr = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",\
                                    &(data->texwall.height), &(data->texwall.width));
    if (data->texwall.ptr == NULL)
        ft_exit(data, "failed to allocate memory for the wall texture");
    data->texwall.addr = mlx_get_data_addr(data->texwall.ptr, &(data->texwall.bpp), \
                            &(data->texwall.linelen),&(data->texwall.endian));
    
}

void gentextures2(t_solong *data)
{
    data->texfloor.ptr = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",\
                                    &(data->texfloor.height), &(data->texfloor.width));
    if (data->texfloor.ptr == NULL)
        ft_exit(data, "failed to allocate memory for the floor texture");
    data->texfloor.addr = mlx_get_data_addr(data->texfloor.ptr, &(data->texfloor.bpp), \
                            &(data->texfloor.linelen),&(data->texfloor.endian));
    
}

void gentextures3(t_solong *data)
{
    data->texcol.ptr = mlx_xpm_file_to_image(data->mlx, "./textures/coin.xpm",\
                                    &(data->texcol.height), &(data->texcol.width));
    if (data->texcol.ptr == NULL)
        ft_exit(data, "failed to allocate memory for the collect texture");
    data->texcol.addr = mlx_get_data_addr(data->texcol.ptr, &(data->texcol.bpp), \
                            &(data->texcol.linelen),&(data->texcol.endian));
    
}

void gentextures4(t_solong *data)
{
    data->texexit.ptr = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm",\
                                    &(data->texexit.height), &(data->texexit.width));
    if (data->texexit.ptr == NULL)
        ft_exit(data, "failed to allocate memory for the exit texture");
    data->texexit.addr = mlx_get_data_addr(data->texexit.ptr, &(data->texexit.bpp), \
                            &(data->texexit.linelen),&(data->texexit.endian));
    
}

void gentextures5(t_solong *data)
{

    data->texpl[0].ptr = mlx_xpm_file_to_image(data->mlx, "./textures/m_00.xpm", &(data->texpl[0].width), \
                                            &(data->texpl[0].height));
    if (data->texpl[0].ptr == NULL)
        ft_exit(data, "failed to allocate memory for the exit texture");
     data->texpl[0].addr = mlx_get_data_addr(data->texpl[0].ptr, &(data->texpl[0].bpp), \
                            &(data->texpl[0].linelen),&(data->texpl[0].endian));
}

void gentextures(t_solong *data)
{
    data->mlx = mlx_init();
    gentextures1(data);
    gentextures2(data);
    gentextures3(data);
    gentextures4(data);
    gentextures5(data);
    draw(data);
}