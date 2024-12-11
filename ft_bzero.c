/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanjiga <alejanjiga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:39:09 by alejandj          #+#    #+#             */
/*   Updated: 2024/12/10 13:40:52 by alejanjiga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *p;
    
    i = 0;
    p = (unsigned char *)s;
    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}