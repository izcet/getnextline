/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:54:04 by irhett            #+#    #+#             */
/*   Updated: 2017/02/01 14:26:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	put_str_cya(char *str)
{
	printf("\033[0;36m\"%s\"\033[0m\n", str);
}

void	put_str_red(char *str)
{
	printf("\033[0;31m\"%s\"\033[0m\n", str);
}

int		main(int argc, char **argv)
{
	int		*fds;
	char	*line;
	int 	index;
	int		line_count;
	int		still_reading;
	int		ret;

	if (argc > 1)
	{
		index = 0;
		fds = (int*)malloc(sizeof(int) * argc);
		while (index < argc - 1)
		{
				fds[index] = open(argv[index + 1], O_RDONLY);
				if (fds[index] == -1)
					printf("\033[0;31mError opening file \"%s\"\033[0m\n", argv[index + 1]);
			index++;
		}
		line_count = 0;
		still_reading = 1;
		while (still_reading)
		{
			still_reading = 0;
			index = 0;
			while (index < argc - 1)
			{
				if (fds[index] != -1)
				{
					ret = get_next_line(fds[index], &line);
					printf("\033[0;31mget_next_line() call %i on fds[%i](%i)\033[0m\n returned %i", line_count, index, fds[index], ret);
					put_str_cya(line);
					if (ret == 1)
					{
						still_reading = ret;
						free(line);
					}
					else if (ret == 0)
					{
						close(fds[index]);
						fds[index] = -1;
					}
				}
				else
					printf("\033[0;31mget_next_line() skipped on fds[%i]\033[0m\n", index);
				index++;
			}
			printf("\n");
			line_count++;
		}
		free(fds);
		free(line);
	}
	else
		put_str_red("not enough files");
	return (0);
}
