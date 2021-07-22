/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 20:44:16 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 21:32:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SIGNALSLEEP 500
# define BITCOUNT 8
# define BUFFERSIZE 10
# define TERMINATOR 0

# ifdef OnLinux
#  define _GNU_SOURCE
# endif

# include <unistd.h>
# include <signal.h>

void	ft_putstr(char *str);
void	ft_putnbr(int n);
char	ft_atoi_strict(char *str, int *out_num);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	*ft_realloc_double(void *src, int *srcsize);
int		most_signf_bit(int bits);
char	*itobi(int n, int bits);
int		bitoi(char *bi);

typedef struct s_recvbuff
{
	char	*buffer;
	char	inactive;
	char	active;
	int		client;
}	t_recvbuff;

t_recvbuff	g_recv;

#endif
