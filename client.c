/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 20:49:16 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 21:32:30 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared/minitalk.h"
#include <stdlib.h>

static void	sendmessage(unsigned char ascii)
{
	int	i;
	int	bit;

	i = 0;
	bit = most_signf_bit(BITCOUNT);
	while (i < BITCOUNT)
	{
		if (!g_recv.active)
		{
			g_recv.active = 1;
			if (bit <= ascii)
			{
				kill(g_recv.client, SIGUSR1);
				ascii -= bit;
			}
			else
			{
				kill(g_recv.client, SIGUSR2);
			}
			bit /= 2;
			i++;
		}
	}
}

static void	loop_str(char *str)
{
	while (*str)
	{
		sendmessage(*str);
		str++;
	}
	sendmessage(0);
}

static void	confirmed(int i)
{
	(void)i;
	g_recv.active = 0;
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, confirmed);
	if (argc != 3)
	{
		ft_putstr("Usage: ./client [PID] [STRING]\n");
		return (0);
	}
	if (!ft_atoi_strict(argv[1], &g_recv.client))
	{
		ft_putstr("Invalid characters encountered in the entered PID.\n");
		return (0);
	}
	if (argc == 2)
		sendmessage(0);
	else
		loop_str(argv[2]);
}
