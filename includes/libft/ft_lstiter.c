/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:26:51 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:26:52 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

/*
void    f(void *content) // solo per provare DA LEVARE!!
{
	char *str = (char *)content;
    strcpy(str, "ciaoo"); 
}*/
/*
void    print_list(t_list *lst) // solo per stampare DA LEVARE!!
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_n;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		next_n = lst->next;
		(*f)(lst->content);
		lst = next_n;
	}
}
/*
int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = strdup("First");
	node1->next = node2;

	node2->content = strdup("Second");
	node2->next = node3;

	node3->content = strdup("Third");
	node3->next = NULL;

	printf("Lista prima:\n");
	print_list(node1);
	ft_lstiter(node1, f);
	printf("Lista dopo:\n");
	print_list(node1);
}*/