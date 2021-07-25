#include <unistd.h>

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
	{
		iterator++;
	}
	write(1, str, iterator);
}

int	ft_strlen(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
		++iterator;
	return (iterator);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
