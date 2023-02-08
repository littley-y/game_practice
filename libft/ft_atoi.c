int	ft_atoi(const char *nptr)
{
	int			i;
	int			minus;
	long long	temp_num;
	long long	last_num;

	i = 0;
	minus = 1;
	temp_num = 0;
	last_num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		minus = 44 - nptr[i++];
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp_num *= 10;
		temp_num += nptr[i++] - '0';
		if (temp_num <= 0 && last_num > 0 && minus == -1)
			return (0);
		if (temp_num <= 0 && last_num > 0 && minus == 1)
			return (-1);
		last_num = temp_num;
	}
	return ((int)(temp_num * minus));
}
