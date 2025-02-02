/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:24:51 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:31:26 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_n;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last_n = ft_lstlast(*lst);
		last_n->next = new;
	}
}
/*
int	main(void) // main di merda.
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));
	t_list *new = malloc(sizeof(t_list));

	node1->content = "First";
	node1->next = node2;

	node2->content = "Second";
	node2->next = node3;

	node3->content = "Third";
	node3->next = NULL;

	new->content = "Fourth!";
	new->next = NULL;

	printf("%p\n", new);
	ft_lstadd_back(&node1, new);
}*/