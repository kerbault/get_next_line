/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:40:34 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:40:36 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	t_byte	*ret;

	ret = s;
	while (n--)
		*(t_byte *)s++ = (t_byte)c;
	return (ret);
}
