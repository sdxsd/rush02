#include <unistd.h>
#include "list.h"
//#include "lib.h"
//#include "ft_atoi.h"

long g_num_to_check;

int	ft_check(char *str)
{
	int	len;

	len = ft_strlen(str);
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

void	print_if_eq(t_list *li)
{
	if (li->key == g_num_to_check)
	{
		ft_putstr(li->value);
		ft_putchar(' ');
	}
}

int	main(int argc, char **argv)
{
	long	tmp;
	t_list	*li	= (t_list *)0;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	ft_check(argv[1]);
	g_num_to_check = ft_atoi(argv[1]);
	tmp = g_num_to_check;
	parse_file("numbers.dict", &li);
	if (g_num_to_check >= 20 && g_num_to_check % 10 != 0)
	{
		g_num_to_check = (tmp / 10) * 10;
		li_foreach(li, &print_if_eq);
		g_num_to_check = tmp % 10;
		li_foreach(li, &print_if_eq);
	}
	else
	{
		li_foreach(li, &print_if_eq);
	}
	ft_putchar('\n');
	return (0);
}
