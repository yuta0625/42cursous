#include <stdlib.h>

static int	malloc_count(long nb)
{
	int	n = 1;
	while (nb >= 10)
	{
		nb /= 10;
		n++;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		count;
	int		sign;

	if (n < 0)
	{
		sign = 1;
		nb = -(long)n;
	}
	else
	{
		sign = 0;
		nb = (long)n;
	}
	count = malloc_count(nb);
	ret = malloc((count + sign + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[count + sign] = '\0';
	while (count--)
	{
		ret[count + sign] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		ret[0] = '-';
	return (ret);
}
