/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:28:04 by meshahrv          #+#    #+#             */
/*   Updated: 2022/06/07 14:56:49 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h> //!to be removed
# include <stdlib.h>

// # include <sys/types.h>
// # include <sys/uio.h>
// # include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	read_to_stash(int fd, t_list **stash);
void	stash_to_line(t_list *stash, char **line);
int		ft_strlen(char *str);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		check_new_line(t_list *stash);
void	malloc_line(char **line, t_list *stash);
t_list	*last_node(t_list *stash);

#endif
