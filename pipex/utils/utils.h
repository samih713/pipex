/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:01:54 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/10 22:05:43 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *dest, int c, size_t len);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strncpy(char *dest, char *src, int n);

#endif
