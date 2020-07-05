/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neodyme  <neodyme@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 01:36:28 by neodyme           #+#    #+#             */
/*   Updated: 2020/07/05 12:05:17 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void print_result(int result)
{
	if (result == 1)
	{
		printf("\033[1;32m");
		printf("OK\n");
		printf("\033[0m");
		return ;
	}
	else
	{
		printf("\033[1;31m");
	 	printf("KO\n");
		printf("\033[0m");
		return ;
	}
}

#ifdef MALLOC
void	*malloc(size_t size)
{
	if (size)
	{
		;
	}
	return (NULL);
}
#endif

int main(void)
{
	int		fd;
	char	*line;

/* ERROR MANAGEMENT TESTS */

#ifdef MALLOC
	printf("\nMalloc protection test: ");
	fd = open("test_regular", O_RDONLY);
	get_next_line(fd, &line) == -1 ? print_result(1) : print_result(0);
	close(fd);
#endif

#ifdef ERRMAN
	printf("\nERROR MANAGEMENT TESTS\n\nOpening arbitrary file descriptor: ");
	get_next_line(42, &line) == -1 ? print_result(1) : print_result(0);
	
	printf("\nReading non-existing file: ");
	fd = open("dummy", O_RDONLY);
	get_next_line(fd, &line) == -1 ? print_result(1) : print_result(0);
	
	printf("\nReading file opened for write-only: ");
	fd = open("test_wronly", O_WRONLY);
	get_next_line(fd, &line) == -1 ? print_result(1) : print_result(0);
	close(fd);
#endif

#ifdef BUF0
	printf("\nReading file with BUFFER_SIZE = 0: ");
	fd = open("test_regular", O_RDONLY);
	get_next_line(fd, &line) == -1 ? print_result(1) : print_result(0);
	close(fd);
#endif

/* READING TESTS */

#ifdef BUF1
	printf("\n\nREADING TESTS\n\nReading with BUFFER_SIZE = 1: ");
	fd = open("test_regular", O_RDONLY);
	if (get_next_line(fd, &line) == 1 && !strcmp(line, "I do believe you think what now you speak;"))
		print_result(1);
	else
		print_result(0);
	close(fd);
	free(line);
#endif

#ifdef BUF4
	printf("\nReading with BUFFER_SIZE = 4: ");
	fd = open("test_regular", O_RDONLY);
	if (get_next_line(fd, &line) == 1 && !strcmp(line, "I do believe you think what now you speak;"))
		print_result(1);
	else
		print_result(0);
	close(fd);
	free(line);
#endif

#ifdef BUF9999
	printf("\nReading with BUFFER_SIZE = 9999: ");
	fd = open("test_regular", O_RDONLY);
	if (get_next_line(fd, &line) == 1 && !strcmp(line, "I do believe you think what now you speak;"))
		print_result(1);
	else
		print_result(0);
	close(fd);
	free(line);
#endif

#ifdef BUF10000000
	printf("\nReading with BUFFER_SIZE = 10000000: ");
	fd = open("test_regular", O_RDONLY);
	if (get_next_line(fd, &line) == 1 && !strcmp(line, "I do believe you think what now you speak;"))
		print_result(1);
	else
		print_result(0);
	close(fd);
	free(line);
#endif

#ifdef BUFLINE
	printf("\nReading with BUFFER_SIZE = 43: ");
	fd = open("test_regular", O_RDONLY);
	if (get_next_line(fd, &line) == 1 && !strcmp(line, "I do believe you think what now you speak;"))
		print_result(1);
	else
		print_result(0);
	close(fd);
	free(line);
#endif

#ifdef HUGE_FILE
	int fd1;

	printf("\nReading the War and Peace: ");
	fd = open("test_warandpeace", O_RDONLY);
	fd1 = open("test_warandpeace_out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	while (get_next_line(fd, &line))
	{
		write(fd1, line, strlen(line));
		write(fd1, "\n", 1);
		free(line);
	}
	close(fd);
	close(fd1);
#endif

	return (0);
}
