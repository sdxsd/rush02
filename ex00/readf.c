#include <fcntl.h>
#include <unistd.h>
#include "lib.h"

int fgetline()
{
    open("numbers.dict", O_RDONLY);
    char buffer[8096];
    int file = open("numbers.dict", O_RDONLY);
    if (file == -1)
    {
        write(1, "error", 5);
        return (1);
    }
    read(file, &buffer[0], sizeof(buffer));
    close(file);
    ft_putstr(buffer);
    return (0);
}

int main()
{
    fgetline();
}
