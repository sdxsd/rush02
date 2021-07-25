#ifndef FT_ATOI_H
# define FT_ATOI_H

/* walks over the whitespace, returns offset */
unsigned int	check_whitespace(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == ' '
		|| str[i] == '\n'
		|| str[i] == '\r'
		|| str[i] == '\t'
		|| str[i] == '\f'
		|| str[i] == '\v')
	{
		i++;
	}
	return (i);
}

/* determines if the number should be negative or not
 * returns offset
 * ^ is the XOR operator, *neg ^ 1 will flip the first bit */
unsigned int	should_be_negative(char *str, int *neg)
{
	unsigned int	i;

	i = 0;
	*neg = 0;
	while (str[i] != 0)
	{
		if (str[i] == '-')
		{
			*neg = *neg ^ 1;
		}
		else if (str[i] != '+')
		{
			break ;
		}
		i++;
	}
	return (i);
}

/* converts string to long, as a human would
 * overflow behaviour is undefined */
long	ft_atoi(char *str)
{
	long	r;
	int		neg;

	r = 0;
	str += check_whitespace(str);
	str += should_be_negative(str, &neg);
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
		{
			break ;
		}
		r *= 10;
		r += *str - '0';
		str++;
	}
	if (neg)
		r = -r;
	return (r);
}
#endif
