int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || \
				*str == '\v' || *str == '\f' || *str == '\r')
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			num = (*str - 48) + (num * 10);
			str++;
		}
		break ;
	}
	return (num * sign);
}	
