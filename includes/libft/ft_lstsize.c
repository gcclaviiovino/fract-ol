/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:27:19 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:27:20 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size ++;
		lst = lst->next;
	}
	return (size);
}
/*
int	main(void)
{
	t_list *lst;
	int	size;

	lst = (t_list *) malloc(sizeof(t_list));
	lst->next = NULL;
	size = ft_lstsize(lst);
	printf("%d\n", size);
}*/