/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:53:45 by yidrissi          #+#    #+#             */
/*   Updated: 2022/02/07 06:12:39 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;
	char	*t_s1;
	char	*t_s2;

	i = 0;
	j = 0;
	t_s1 = (char *)s1;
	t_s2 = (char *)s2;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (result);
	while (t_s1 && t_s1[i] != '\0')
		result[j++] = t_s1[i++];
	i = 0;
	while (t_s2 && t_s2[i] != '\0')
		result[j++] = t_s2[i++];
	free(t_s1);
	free(t_s2);
	return (result);
}
