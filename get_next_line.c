/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:29:40 by yidrissi          #+#    #+#             */
/*   Updated: 2022/02/06 22:38:52 by yidrissi         ###   ########.fr       */
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
	if (fd < 0 || fd > FD_SIZE || BUFF_SIZE < 1)
		return (NULL);
	result = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!result)
		return (NULL);
	while (j > 0 && i < BUFF_SIZE && buff[0] != '\n')
	{
		if (buff[0] != '\n')
		{
			j = read(fd, buff, 1);
			if (!j || buff[0] == '\n')
				result[i++] = buff[0];
		}
	}
	if (buff[0] != '\n' && buff[0] != '\0')
		return (ft_strjoin(result, get_next_line(fd)));
	result[i] = '\0';
	return (result);
}
