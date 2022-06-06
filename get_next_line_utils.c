/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:28:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/06/06 19:51:51 by meshahrv         ###   ########.fr       */
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

int	check_new_line(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
	// while (stash && stash->next)
	// 	stash = stash->next;
	// while (stash->next)
	// 		last_node = stash->next;
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}		
	return (0);
}

// Returns a pointer to the last node in the stash
t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	malloc_line(char *line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash != NULL)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	line = malloc(sizeof(char) * (len + 1));
}
