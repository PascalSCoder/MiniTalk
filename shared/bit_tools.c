/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bit_tools.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 15:20:40 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/10 19:23:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int	bitoi(char *bi)
{
	int	res;
	int	signf;
	int	i;

	signf = most_signf_bit(BITCOUNT);
	res = 0;
	i = 0;
	while (i < BITCOUNT)
	{
		if (bi[i] == '1')
			res += signf;
		signf /= 2;
		i++;
	}
	return (res);
}

int	most_signf_bit(int bits)
{
	int	i;
	int	bit;

	i = 1;
	bit = 1;
	while (i < bits)
	{
		bit += bit;
		i++;
	}
	return (bit);
}
