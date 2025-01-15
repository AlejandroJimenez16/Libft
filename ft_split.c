/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:11:29 by alejanjiga        #+#    #+#             */
/*   Updated: 2025/01/15 16:36:47 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	int	i;
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static void	initialize_vars(int *i, int *n_times, int *num_chara)
{
	*i = 0;
	*num_chara = 0;
	*n_times = 0;
}

static int	create_add_word(int num_chara, char const *s, int i,
	char **arr, int n_times)
{
	char	*word;

	word = (char *)malloc((num_chara + 1) * sizeof(char));
	if (!word)
		return (1);
	ft_strlcpy(word, &s[i - num_chara], num_chara + 1);
	arr[n_times] = word;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n_times;
	int		num_words;
	int		num_chara;
	char	**arr;

	initialize_vars(&i, &n_times, &num_chara);
	num_words = words_count(s, c);
	arr = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (n_times < num_words)
	{
		num_chara = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			num_chara++;
			i++;
		}
		if (num_chara > 0)
		{
			if (create_add_word(num_chara, s, i, arr, n_times) == 1)
				return (NULL);
			n_times++;
		}	
		while (s[i] == c)
			i++;
	}
	arr[n_times] = NULL;
	return (arr);
}

int main(void)
{
    char *src = " Hola que tal paquito y juancoo ";
    
    char **arr = ft_split(src, ' ');

    int n = words_count(src, ' ');

    for(int i=0; i < n; i++)
    {
        printf("%s", arr[i]);
        printf("\n");
        free(arr[i]);
    }
    free(arr);
}