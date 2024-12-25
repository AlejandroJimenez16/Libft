/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanjiga <alejanjiga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:20:15 by alejandj          #+#    #+#             */
/*   Updated: 2024/12/25 18:00:18 by alejanjiga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (needle[0] == '\0')
    {
        return ((char *)haystack);
    }
    i = 0;
    while (i < len && haystack[i] != '\0')
    {
        j = 0;
        while (i + j < len && haystack[i + j] == needle[j] && needle[j] != '\0')
        {
            j++;
        }
        if (needle[j] == '\0')
		{
			return ((char *)&haystack[i]);
		}
        i++;
    }
    return (0);
}