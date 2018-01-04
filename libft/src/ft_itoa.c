/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:38:04 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:38:07 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_minint(void)
{
	char	*min;

	if (!(min = (char *)malloc(sizeof(*min) * 12)))
		return (NULL);
	min = ft_strdup("-2147483648\0");
	return (min);
}

static int	ft_countnumb(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
		return (i + 1);
	}
	return (2);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*ret;

	i = ft_countnumb(n);
	if (n == -2147483648)
		return (ft_minint());
	if (!(ret = (char *)malloc(sizeof(*ret) * i)))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0\0"));
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	ret[--i] = '\0';
	i--;
	while (n > 0)
	{
		ret[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
