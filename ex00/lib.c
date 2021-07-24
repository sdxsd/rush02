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

void	ft_putnbr(long nb)
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

/* TODO: whitespace /t/v etc? */
long ft_atoi(const char *str)
{
    long	iterator;
    long	minus_count;
    long	plus_count;
    long	nbr;

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
            nbr += (long)str[iterator] - '0';
        }
        else
            break;
        ++iterator;
    }
    if (minus_count % 2 == 1)
        nbr = -nbr;
    return (nbr);
}
