#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "ft_atoi.h"
#include "list.h"

#include <stdio.h>

#define BUF_SIZE (4096)

long	m_parse_line(char *line, t_list **list);
char	*m_getline(int file);

int	parse_file(char	*filename, t_list **list)
{	
	int		file;
	char	*line;
	long	prev;
	long	cur;

	prev = -2478289893455;
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		return (-1);
	}
	while (1)
	{
		line = m_getline(file);
		cur = m_parse_line(line, list);
		free(line);
		if (cur == prev)
		{
			return (1);
		}
		prev = cur;
	}
	return (1);
}

long	m_parse_line(char *line, t_list **list)
{
	long	key;
	char	*value;
	int		len;
	int		i;

	len = ft_strlen(line);
	if (len <= 3)
	{
		return (0);
	}
	//printf("%s\n", line);
	key = ft_atoi(line);
	i = 0;
	while (line[i] != ':')
	{
		i++;
	}
	i++;
	value = malloc(len - i);
	ft_strcpy(value, (line + i));
	li_create_append(list, key, value);
	return key;
}

/* reads a line of at most BUF_SIZE in length, returns char* 
 * IT SHOULD BE FREED. */
char	*m_getline(int file)
{
	char	buf[BUF_SIZE];
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		read(file, buf + i, 1);
		if (buf[i] == '\n' || buf[i] == 0 || i >= BUF_SIZE)
		{
			line = malloc(i + 1);
			ft_strcpy(line, buf);
			line[i] = 0;
			return (line);
		}
		i++;
	}
}


int main()
{
	t_list	*li = (t_list *)0;
	parse_file("numbers.dict", &li);
	li_display(li);
	return (0);
}

#undef BUF_SIZE
