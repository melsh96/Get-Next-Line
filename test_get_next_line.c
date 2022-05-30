/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:27:51 by meshahrv          #+#    #+#             */
/*   Updated: 2022/05/30 13:20:10 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line_test(int fd)
{
	char	*str;
	int		buf;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = BUFFER_SIZE + 1;
	str = malloc(sizeof(char) * BUFFER_SIZE);
	if (str == NULL)
		return (NULL);
	read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';
	return (str);
}

int	main(void)
{
	printf("%s\n", get_next_line(open("test", O_RDONLY)));
	return (0);
}
