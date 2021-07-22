/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 20:17:53 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/29 12:46:43 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared/minitalk.h"
#include <stdlib.h>

static void	recv(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		g_recv.active = 1;
	else
		g_recv.inactive = 1;
	g_recv.client = info->si_pid;
}

static void	add_char(char **str_buff, int *str_c, int *str_buff_c, char ch)
{
	if (*str_c == *str_buff_c)
		*str_buff = ft_realloc_double(*str_buff, str_buff_c);
	(*str_buff)[*str_c] = ch;
	*str_c += 1;
	if (ch == 0)
	{
		ft_putstr(*str_buff);
		*str_c = 0;
	}
}

static void	add_bit(char *bits, char *bit_buff)
{
	if (g_recv.active)
		bit_buff[(int)*bits] = '1';
	else if (g_recv.inactive)
		bit_buff[(int)*bits] = '0';
	g_recv.active = 0;
	g_recv.inactive = 0;
	*bits += 1;
}

static void	process(void)
{
	char	bit_buff[BITCOUNT];
	char	bits;
	char	*str_buff;
	int		str_c;
	int		str_buff_c;

	bits = 0;
	str_c = 0;
	str_buff_c = BUFFERSIZE;
	str_buff = malloc(BUFFERSIZE);
	if (!str_buff)
		exit(0);
	while (1)
	{
		if (g_recv.inactive || g_recv.active)
		{
			add_bit(&bits, bit_buff);
			if (bits == BITCOUNT)
			{
				add_char(&str_buff, &str_c, &str_buff_c, (char)bitoi(bit_buff));
				bits = 0;
			}
			kill(g_recv.client, SIGUSR1);
		}
	}
}

int	main(void)
{
	struct sigaction	act;
	struct sigaction	oact;

	ft_putstr("Server pid: ");
	ft_putnbr((int)getpid());
	ft_putstr("\n");
	act.sa_flags = SA_SIGINFO | SA_NODEFER;
	act.sa_sigaction = recv;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, &oact);
	sigaction(SIGUSR2, &act, &oact);
	process();
}
