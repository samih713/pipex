/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:59:57 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/10 22:15:48 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (size && (SIZE_MAX / size) > count)
	{
		dest = malloc(size * count);
		if (!dest)
			return (NULL);
		ft_memset(dest, 0, size * count);
	}
	else
		return (NULL);
	return (dest);
}
