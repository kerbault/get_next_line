/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:37:52 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:28:15 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** Include headers for the typedefs, macros and standard functions
** libft.h for personal lib
** fcntl.h for the function read
** stdlib.h for the functions malloc and free
** unistd.h for the function write
** string.h for the macro NULL and the typedef size_t
*/

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 32
# define NULL_CHECK1(x) if (x == NULL) return (-1)
# define MALLOC_CHECK1(x) if (x == NULL) return (-1)
# define MALLOC_CHECK2(x) if (x == NULL) return (NULL)

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	unsigned int	size;
	unsigned int	nb;
	char			*endl;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
