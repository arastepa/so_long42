#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Error: wrong number of arguments\n", 27);
        return (0);
    }
    if (!valid_parameter(argv[1]))
    {
        write(1, "Error: argument must be in .ber format\n", 33);
        return (0);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write (1, "Error: file does not exist", 20);
        close (fd);
        return (0);
    }
    parse(fd, argv[1]);
    close(fd);
    return (1);
}