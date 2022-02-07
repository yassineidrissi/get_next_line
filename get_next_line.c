/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:29:40 by yidrissi          #+#    #+#             */
/*   Updated: 2022/02/07 06:38:54 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buff[1];
	int				i;
	int				j;
	static char		save[BUFFER_SIZE + 1];
	char			*result;

	i = 0;
	j = 1;
	result = NULL;
	if (fd < 0 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	while (j > 0 && i < BUFFER_SIZE && buff[0] != '\n')
	{
		if (buff[0] != '\n')
		{
			j = read(fd, buff, 1);
			if (j == -1)
				return (NULL);
			if (j != 0)
				save[i++] = buff[0];
		}
	}
	save[i] = '\0';
	result = ft_strjoin(result, save);
	if (buff[0] != '\n' && buff[0] != '\0')
		return (ft_strjoin(result, get_next_line(fd)));
	result[i] = '\0';
	return (result);
}


