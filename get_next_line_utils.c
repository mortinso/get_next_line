/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:18:57 by mortins-          #+#    #+#             */
/*   Updated: 2022/12/19 17:53:13 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_strjoin(char *line, const char *box)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(box) + 1));
	if (!new)
		return (NULL);
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (*box)
	{
		new[i++] = *box;
		if (*box++ == '\n')
			break ;
	}
	new[i] = 0;
	free (line);
	return (new);
}

int	check_newline(char *box)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (box[i])
	{
		if (n)
			box[j++] = box[i];
		if (box[i] == '\n')
			n = 1;
		box[i++] = 0;
	}
	return (n);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}
