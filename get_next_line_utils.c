/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:28:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/05/30 16:06:07 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	while ((*lst)->content != NULL)
		last_node = (*lst)->next;
	if (!last_node)
		*lst = new;
	else
		last_node->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_clear;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	to_clear = *lst;
	while (to_clear != NULL)
	{
		next = to_clear->next;
		del(to_clear->content);
		free(to_clear);
		to_clear = next;
	}
	*lst = NULL;
}
