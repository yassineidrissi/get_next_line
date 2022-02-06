/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:29:40 by yidrissi          #+#    #+#             */
/*   Updated: 2022/02/07 01:47:01 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buff[1];
	int				i;
	int				j;
	char			*result;

	i = 0;
	j = 1;
	if (fd < 0 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	result = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!result)
		return (NULL);
	while (j > 0 && i < BUFFER_SIZE && buff[0] != '\n')
	{
		if (buff[0] != '\n')
		{
			j = read(fd, buff, 1);
			if (j == -1)
				return (NULL);
			if (j != 0)
				result[i++] = buff[0];
		}
	}
	if (buff[0] != '\n' && buff[0] != '\0')
		return (ft_strjoin(result, get_next_line(fd)));
	result[i] = '\0';
	return (result);
}


