/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:00:42 by ydimitro          #+#    #+#             */
/*   Updated: 2022/08/19 16:40:23 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		cmp_char(char c1, char c2);
int		word_count(const char *s, char c);
char	**fill_arr(int words, const char *s, char c, char **arr);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (cmp_char(s1[i], s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (cmp_char(s1[i], s2[i]));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a_str;
	size_t	len_s;
	size_t	len_a_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	a_str = malloc((len + 1) * sizeof(char));
	if (!a_str)
		return (NULL);
	len_s = start;
	len_a_str = 0;
	while (len_s < ft_strlen(s) && len_a_str < len)
		a_str[len_a_str++] = s[len_s++];
	a_str[len_a_str] = '\0';
	return (a_str);
}

char	**ft_splitpath(char *s, char c)
{
	char	**arr;
	int		words;

	if (!s || !s[0])
		return (NULL);
	words = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(words, s, c, arr);
	return (arr);
}

int	free_arr(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	if (path)
		free(path);
	return (0);
}

void	free_struct(t_cmd *c)
{
	int	i;

	i = 0;
	if (c->cmd)
		free(c->cmd);
	free_arr(c->path);
	while (c->arg[i])
		free(c->arg[i++]);
}
