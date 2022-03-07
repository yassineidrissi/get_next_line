/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_for_exam.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:13:11 by yassine           #+#    #+#             */
/*   Updated: 2022/03/07 20:16:03 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_for_exam(int fd)
{
	char			buff[1];
	int				i;
	int				j;
	char			*result;

	i = 0;
	j = 1;
	result = NULL;
	if (fd < 0 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	while (j > 0 && buff[0] != '\n')
	{
			j = read(fd, buff, 1);
			if (j == -1)
				return (NULL);
			if (j != 0)
				result[i++] = buff[0];
	}
	//  save[i] = '\0';
	// result = ft_strjoin(result, save);
	result[i] = '\0';
	return (result);
}
