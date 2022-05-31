/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:10:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/05/31 14:30:56 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char			*buf[BUFFER_SIZE + 1];
char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				i;

	i = 0;
	stash = ft_lstnew(stash->content);
	line[i] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	while ()
	{
		
	}
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
