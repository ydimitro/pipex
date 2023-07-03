/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:32:10 by ydimitro          #+#    #+#             */
/*   Updated: 2022/08/19 16:32:57 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**freetab(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
	return (0);
}

int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = -1;
	count = 0;
	while (s[++i])
		if ((s[i] != c && s[i + 1] == c)
			|| (s[i] != c && s[i + 1] == '\0'))
			count++;
	return (count);
}

int	words_len(const char *s, char c, int i)
{
	int	l;

	l = 0;
	while (s && s[i] && s[i] == c)
		i++;
	while (s && s[i] && s[i++] != c)
		l++;
	return (l);
}

char	**fill_arr(int words, const char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < words)
	{
		j = 0;
		arr[k] = (char *)malloc(sizeof(char) * (words_len(s, c, i) + 2));
		if (!arr[k])
			return (freetab(arr));
		while (s && s[i] && s[i] == c)
			i++;
		while (s && s[i] && s[i] != c)
			arr[k][j++] = s[i++];
		arr[k][j++] = '/';
		arr[k][j] = '\0';
		k++;
	}
	arr[k] = 0;
	return (arr);
}

int	cmp_char(char c1, char c2)
{
	if ((unsigned char)c1 != (unsigned char)c2)
		return ((unsigned char)c1 - (unsigned char)c2);
	return (0);
}
