#include "so_long.h"

int valid_parameter(char *str)
{
    int i;

    i = 0;
    while (str[i] != '.' && str[i])
        i++;
    if (str[i] && ft_strncmp(&str[i], ".ber",\
    ft_strlen(&str[i]) > ft_strlen(".ber") ? ft_strlen(&str[i]) :\
    ft_strlen(".ber")) == 0)
    {
        return (1);
    }
    return (0);
}

int checkheight(char *f, t_solong *data)
{
    char *line;
    int t;
    int i;
    int fd;
    int exit;

    exit = 0;
    i = 0;
    fd = open(f, O_RDONLY);
    t = get_next_line(fd, &line);
    while (t)
    {
        i++;
        if (ft_strchr(line, 'E'))
            exit = 1;
        free(line);
        t = get_next_line(fd, &line);
    }
    if (exit == 0)
    {
        close(fd);
        ft_exit(data, "Error: no exit symbol\n");
    }
    close(fd);
    return (i);
}

int checkbelowabove(t_solong *data)
{
    int j;

    j = 0;
    while (j < data->x)
    {
        if (data->map[0][j] != '1' || data->map[data->y - 1][j] != '1')
        {
            return (0);
        }
        j++;
    }
    return (1);
}



int checkleftright(t_solong *data)
{
     int i;

     i = 0;
     while (i < data->y)
     {
        if (data->map[i][0] != '1' || data->map[i][data->x - 1] != '1')
        { 
            return (0);
        }
        i++;
     }
     return (1);
}

int getmapline(char *line, t_solong *data)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '0')
            data->map[data->y][i] = '0';
        else if (line[i] == '1')
            data->map[data->y][i] = '1';
        else if (line[i] == 'C')
        {
            data->map[data->y][i] = 'C';
            data->collect++;
        }
        else if(line[i] == 'E')
        {
            data->map[data->y][i] = 'E';
        }
        else if (line[i] == 'P')
        {
            initplayer(data, data->y, i);
            data->map[data->y][i] = 'P';
        }
        else
        {
            ft_exit(data, "Error: map must contain only 0 1 C E P\n");
        }
        i++;
    }
    data->map[data->y][i] = '\0';
    data->y++;
}

void parse(int fd, char *f)
{
    int t;
    char *line;
    t_solong *data;
    int i;

    i = 0;
    data  = malloc(sizeof(t_solong));
    initmap(data);
    data->y = checkheight(f, data);
    data->map = (char **)malloc(sizeof(char *) * (data->y));
    t = get_next_line(fd, &line);
    data->x = ft_strlen(line);
    while (i < data->y)
    {
        data->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
        i++;
    }
    data->y = 0;
    while (t)
    {
        if (data->x != ft_strlen(line))
            ft_exit(data, "Error: map must be rectangular\n");
        getmapline(line, data);
        free(line);
        t = get_next_line(fd, &line);
    }
    if (data->playerx < 0 && data->playery < 0)
        ft_exit(data, "error: ther's no player\n");
    if (data->collect == 0)
        ft_exit(data, "error: no collectible");
    if (!checkbelowabove(data) || !checkleftright(data))
        ft_exit(data, "Error: map must be closed by 1\n");
    gentextures(data);
}