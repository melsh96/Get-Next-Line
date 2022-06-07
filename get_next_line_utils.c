/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:28:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/06/07 19:29:15 by meshahrv         ###   ########.fr       */
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
		if (check_new_line(to_clear) == -1)
		{
			del(to_clear->content);
			free(to_clear);
		}
		else
		{
			new_line_exists(to_clear);
			break ;
		}
		to_clear = next;
	}
	*lst = to_clear;
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

// Returns a pointer to the last node in the stash
// t_list	*last_node(t_list *stash)
// {
// 	t_list	*current;

// 	current = stash;
// 	while (current && current->next)
// 		current = current->next;
// 	return (current);
// }

void	malloc_line(char **line, t_list *stash)
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
	if (len == 0)
		*line = NULL;
	else
		*line = malloc(sizeof(char) * (len + 1));
}
