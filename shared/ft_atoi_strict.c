/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_strict.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 21:57:42 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/08 21:10:08 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

static char	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			break ;
	}
	return (*s1 - *s2);
}

static char	cmp_int(char *str, int n)
{
	char	*cmp;

	cmp = ft_itoa(n);
	if (!cmp)
		return (0);
	if (ft_strcmp(str, cmp) == 0)
	{
		free(cmp);
		return (1);
	}
	free(cmp);
	return (0);
}

char	ft_atoi_strict(char *str, int *out_num)
{
	char	negative;
	int		i;

	*out_num = 0;
	negative = 0;
	i = 0;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		*out_num = *out_num * 10 + str[i] - '0';
		i++;
	}
	if (negative)
		*out_num *= -1;
	return (cmp_int(str, *out_num));
}
