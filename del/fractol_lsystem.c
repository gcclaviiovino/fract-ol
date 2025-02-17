/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_lsystem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:53:24 by liovino           #+#    #+#             */
/*   Updated: 2025/02/12 10:45:28 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	check_def(char *res, char *input, int def)
{
	if (def == 0)
	{
		ft_strlcpy(res, input, MAX_LEN);
		return (1);
	}
	else if (def < 0)
		return (1);
	return (0);
}

void	ft_lsystem(char *res, char *input, int def)
{
	char	temp[MAX_LEN];
	int		i;

//	printf("called\n");
	i = -1;
	temp[0] = '\0';
	if (check_def(res, input, def) == 1)
		return ;
	while (input[++i])
	{
		switch(input[i])
		{
			case 'A':
				ft_strlcat(temp, "A-B--B+A++AA+B-", MAX_LEN);
				break ;
			case 'B':
				ft_strlcat(temp, "+A-BB--B-A++A+B", MAX_LEN);
				break ;
			default:
				ft_strlcat(temp, &input[i], 1);
				break ;
		}
	}
	ft_lsystem(res, temp, def - 1);
}

void	ext(t_gosper new_p, t_gosper *min)
{
	if (new_p.x < min->x)
		min->x = new_p.x;
	if (new_p.y < min->y)
		min->y = new_p.y;
}