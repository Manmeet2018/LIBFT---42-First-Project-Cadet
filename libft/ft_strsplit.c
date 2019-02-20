/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:45:23 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/19 22:58:30 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	flag;
	size_t	index;
	size_t	i;
	size_t	start;

	flag = 0;
	i = -1;
	index = 0;
	start = 0;
	res = (char **)ft_memalloc(sizeof(char *) * (ft_countlength(s, c) + 1));
	if (!res || !s)
		return (NULL);
	while (s[++i])
	{
		if (s[i] == c && flag)
			res[index++] = ft_strsub(s, start, i - start);
		if (!flag && s[i] != c)
			start = i;
		flag = (s[i] == c) ? 0 : 1;
	}
	if (flag)
		res[index] = ft_strsub(s, start, i - start);
	return (res);
}
