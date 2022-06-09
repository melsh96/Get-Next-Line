/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:04:57 by meshahrv          #+#    #+#             */
/*   Updated: 2022/06/08 15:13:11 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	last_node = *lst;
	if (*lst != NULL)
	{	
		while (last_node->next != NULL)
			last_node = last_node->next;
	}
	if (last_node == NULL)
		*lst = new;
	else
		last_node->next = new;
}

void	new_line_exists(t_list	*to_clear)
{
	int		i;
	int		pos;

	i = 0;
	pos = check_new_line(to_clear) + 1;
	while (to_clear->content[i + pos] != '\0')
	{
		(to_clear->content)[i] = (to_clear->content)[i + pos];
		i++;
	}
	to_clear->content[i] = '\0';
}

int	check_new_line(t_list *node)
{
	int		i;
	t_list	*current;

	current = node;
	i = 0;
	if (current)
	{
		while (current->content[i])
		{
			if (current->content[i] == '\n')
				return (i);
			i++;
		}
	}		
	return (-1);
}
