/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:10:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/06/01 18:26:18 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*	1. read in fd & send it to the stash */

void	get_in_stash(int fd, t_list **stash)
{
	char			*buf;
	t_list			*new_node;
	int				line_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return ;
	while (new_node->content != '\n')
	{
		line_read = read(fd, buf, BUFFER_SIZE + 1);
		new_node = ft_lstnew(new_node->content);
		ft_lstadd_back(*stash, new_node);
		new_node = new_node->next;
	}
}

/*	2. extract from stash to line 
	till we reach a \n or end of file */
/*	3. clear the stash */

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				i;

	i = 0;
	line = NULL;
	line[i] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	get_in_stash(fd, &stash);
	if (stash == NULL || ft_strlen(line) == 0)
		ft_lstclear(&stash, free);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}
