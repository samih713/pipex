/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:47:50 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/06 21:50:55 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if ((s1[i] - s2[i]))
			return ((s1[i] - s2[i]));
		i++;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (size && (SIZE_MAX / size) > count)
	{
		dest = malloc(size * count);
		if (!dest)
			error_msg("Memory error");
		ft_memset(dest, 0, size * count);
	}
	else
	{
		dest = malloc(1);
		error_msg("Invalid Size");
	}
	return (dest);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = c;
		i++;
	}
	return (dest);
}
