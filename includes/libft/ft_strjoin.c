/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:23 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:29:39 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		l_1;
	int		l_2;
	char	*superstr;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	l_1 = ft_strlen(s1);
	l_2 = ft_strlen(s2);
	superstr = (char *) malloc(sizeof(char) * ((l_1 + l_2) + 1));
	if (!superstr)
		return (NULL);
	while (s1[++i] != '\0')
		superstr[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
	{
		superstr[l_1 + i] = s2[i];
		i ++;
	}
	superstr[l_1 + i] = '\0';
	return (superstr);
}
// int	main(void)
// {
// 	ft_strjoin("hey", "lol");
// }