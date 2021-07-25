#include <fcntl.h>
#include <unistd.h>
#include "lib.h"
#include "ft_atoi.h"

int fgetline()
{
    open("numbers.dict", O_RDONLY);
    char buffer[8096];
    int file = open("numbers.dict", O_RDONLY);
    if (file == -1)
    {
        write(1, "error\n", 6);
        return (1);
    }
    read(file, &buffer[0], sizeof(buffer));
    close(file);
    ft_putstr(buffer);
    return (0);
}

int get_entry(char *file_path, int lines_to_skip)
{
    char char_buf[4096];
    char one_char;
    int file;
    int iterator;
    int nl_count;

    iterator = 0;
    file = open(file_path, O_RDONLY);
    while ((read(file, &one_char, 1)))
    {
        if (one_char == '\n')
            nl_count++;
        else if (nl_count == lines_to_skip)
        {
            char_buf[iterator] = one_char;
        }
        ++iterator;
    }
    char_buf[iterator++] = '\0';
    ft_putstr(char_buf);
    ft_putnbr(ft_atoi(char_buf));
    return(0);
}

int main()
{
    fgetline();
    get_entry("numbers.dict", 5);
}
