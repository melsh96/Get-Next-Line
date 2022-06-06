/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:10:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/06/06 19:42:38 by meshahrv         ###   ########.fr       */
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

// TODO	1 : read from fd & add to the stash
void	read_to_stash(int fd, t_list **stash)
{
	char			*buf;
	t_list			*new_node;
	int				line_read;

	// ! Read till it finds a new line
	// malloc_line(buf, *stash);
	// if (buf == NULL)
	// 	return ;
	line_read = 1;
	while (!check_new_line(*stash) && line_read != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		line_read = read(fd, buf, BUFFER_SIZE + 1);
		if (*stash == NULL || line_read == 0)
			free(buf);
		buf[line_read] = '\0';
		new_node = ft_lstnew(new_node->content);
		ft_lstadd_back(stash, new_node);
		new_node = new_node->next;
		free(buf);
	}
}

// TODO	2 : extract from stash to line till we reach a \n or end of file
void	stash_to_line(t_list *stash, char *line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	malloc_line(line, stash);
	if (line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				line[j++] = stash->content[i];
				break ;
			}
			line[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	line[j] = '\0';
}

// TODO	3 : clear the stash

char	*get_next_line(int fd)
{
	char			*line;
	int				i;
	static t_list	*stash = NULL; // ! It will be initialized only at the begining
	
	// ! Error cases
	// ! If open does not work, it returns a negative number
	// ! If read sends a negative number or the buffer size is less than 0
	
	//line = malloc(sizeof(char) * 101);
	//line = NULL;
	printf("fd = %d\n",fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	
	i = 0;
	line = NULL;
	printf("line = %s\n",line);
	// TODO 1 : read from fd & add to the stash
	read_to_stash(fd, &stash);
	// TODO	2 : extract from stash to line till we reach a \n or end of file
	stash_to_line(stash, line);
	if (stash == NULL)
		return (NULL);
	// TODO	3 : clear the stash
	// if (stash == NULL || ft_strlen(line) == 0)
	// 	ft_lstclear(&stash, free);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}
