#include <unistd.h>
#include "list.h"

int	ft_check_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_check(char *str)
{
	int	len;

	len = ft_check_len(str);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			write(1, "error\n", 6);
			return (0);
		}
		str++;
	}
	if (len > 37)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}

int	parse_file(char	*filename, t_list **list);

int	main(int argc, char **argv)
{
	t_list	*li	= (t_list *)0;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	ft_check(argv[1]);
	parse_file("numbers.dict", &li);
	li_display(li);
	return (0);
}
