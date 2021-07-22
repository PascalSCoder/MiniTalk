/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc_double.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 15:43:51 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/10 13:50:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//	Reallocates memory twice the size of srcsize, and fills the memory with src
//	srcsize will be updated to the new size.
//	Return new memory pointer on succes, or exit program on error.
void	*ft_realloc_double(void *src, int *srcsize)
{
	char	*dest;
	int		i;

	dest = malloc(*srcsize * 2);
	if (!dest)
		exit(0);
	i = 0;
	while (i < *srcsize)
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	free(src);
	*srcsize += *srcsize;
	return (dest);
}
