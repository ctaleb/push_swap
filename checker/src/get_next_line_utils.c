/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:18:04 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 13:18:42 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_memchr(const void *ptr, int c, size_t size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < size)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;
	unsigned int	dst_len;

	dst_len = ft_strlen(dst);
	i = dst_len;
	src_len = ft_strlen((char *)src);
	if (dst_size == 0 || dst_size - 1 < dst_len)
		return (dst_size + src_len);
	j = 0;
	while (src[j] && ((dst_size - dst_len - j - 1) > 0))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
