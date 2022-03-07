/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:37:16 by yidrissi          #+#    #+#             */
/*   Updated: 2022/03/07 20:05:43 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# define FD_SIZE 256

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(char *src);
char	*ft_strjoin(char *s1, char *s2);

#endif
 