char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_str_is_numeric(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
	{
		if (str[iterator] < '0' || str[iterator] > '9')
			return (0);
		++iterator;
	}
	if (iterator == 0)
		return (1);
	return (1);
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

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int	odd_even(int x)
{
	if (x % 2)
		return (1);
	else
		return (0);
}

int ft_atoi(char *str)
{
    int iterator;
    int minus_count;
    int plus_count;
    int nbr;

    nbr = 0;
    iterator = 0;
    minus_count = 0;
    plus_count = 0;
    while (str[iterator] != '\0')
    {

        if (str[iterator] == ' ')
            continue;
        if (str[iterator] == '-')
            ++minus_count;
        else if (str[iterator] == '+')
            ++plus_count;
        else if (str[iterator] >= '0' && str[iterator] <= '9')
        {
            nbr *= 10;
            nbr += (int)str[iterator] - '0';
        }
        else
            break;
        ++iterator;
    }
    if (odd_even(minus_count) == 1)
        nbr = nbr - (nbr * 2);
    printf("%d\n", nbr);

    return (nbr);
}