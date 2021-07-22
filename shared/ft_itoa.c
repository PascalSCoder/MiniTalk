/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:47:51 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 13:03:20 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	subtract_last_nbr(long *n)
{
	char	ch;

	ch = (*n % 10) + '0';
	*n = *n / 10;
	return (ch);
}

static char	*malloc_length(long n, int *length, char negative)
{
	char	*buffer;

	*length = 0;
	if (negative)
		*length += 1;
	while (1)
	{
		subtract_last_nbr(&n);
		*length += 1;
		if (!n)
			break ;
	}
	buffer = (char *)malloc((1 + (*length)) * sizeof(char));
	return (buffer);
}

static void	fill_buffer(long n, char *buffer)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (1)
	{
		buffer[i] = subtract_last_nbr(&n);
		i++;
		if (!n)
			break ;
	}
	j = 0;
	while (i > j)
	{
		i--;
		tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
		j++;
	}
}

char	*ft_itoa(int n)
{
	char	*buffer;
	char	negative;
	long	abs_n;
	int		length;

	negative = 0;
	abs_n = n;
	if (abs_n < 0)
	{
		abs_n *= -1;
		negative = 1;
	}
	buffer = malloc_length(abs_n, &length, negative);
	if (buffer)
	{
		if (negative)
			buffer[0] = '-';
		fill_buffer(abs_n, buffer + negative);
		buffer[length] = '\0';
		return (buffer);
	}
	return (0);
}
