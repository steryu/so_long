/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:32:05 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/28 13:32:06 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*s;

	i = 0;
	dst = (char *)dest;
	s = (char *)src;
	if (dst == src || n == 0)
	{
		return (dest);
	}
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	n;

	n = (ft_strlen(s1) + 1);
	dst = malloc(n);
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, n);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	i = start;
	j = 0;
	while (ft_strlen(s) >= start && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
