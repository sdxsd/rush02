#include <unistd.h>
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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	ft_check(argv[1]);
}
