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
    char entry_buf[4096];
    char one_char;
    int file;
    int iterator;
    int iterator2;
    int nl_count;
    
    nl_count = 0;
    iterator = 0;
    file = open(file_path, O_RDONLY);
    while ((read(file, &one_char, 1)) && one_char != '\0')
    {
        char_buf[iterator] = one_char;
        ++iterator;
    }
    iterator = 0;
    iterator2 = 0;
    while (iterator < 4096)
    {
        if (char_buf[iterator] == '\n')
            ++nl_count;
        else if (nl_count == lines_to_skip)
            entry_buf[iterator2] = char_buf[iterator];
        iterator++;

    }
    char_buf[iterator] = '\0';
    ft_putstr(entry_buf);
    close (file);
    return(0);
}

int main()
{
    //fgetline();
    get_entry("numbers.dict", 4);
}
