/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:53:44 by mucankir          #+#    #+#             */
/*   Updated: 2025/02/19 19:22:57 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(const char *s)
{
    int	len;

    len = 0;
    while (s[len])
    {
        len++;
    }
    return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	i = 0;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (*(s + start) && len-- > 0)
	{
		sub[i] = *(s + start);
		i++;
		s++;
	}
	sub[i] = '\0';
	return (sub);
}
static int	word_counter(char const *s, char c)
{
	int	count;
	int	inword;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			inword = 1;
			count++;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}



char	**ft_split(char const *s, char c)
{
	int i;
	char **split;
	int count;

	if (!s)
		return (NULL);
	count = word_counter(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	split[count] = NULL;
	i = 0;
	while (count-- > 0)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (split);
		split[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!split[i++])
			return (NULL);
		s += ft_wordlen(s, c);
	}
	return (split);
}
int 	is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size_a - 1)
    {
        if (stack->a[i] > stack->a[i + 1])
            return (0);
        i++;
    }
    return (1);
}