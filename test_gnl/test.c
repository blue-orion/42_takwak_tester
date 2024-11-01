#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	int		fd2;
	char	*res;

	// File input
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file open failed\n");
		return (0);
	}
	fd2 = open("text_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd2 == -1)
	{
		printf("file open failed\n");
		return (0);
	}
	printf("fd == %d\n", fd);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s", res);
		write(fd2, res, strlen(res));
		free(res);
	}
	close(fd);
	close(fd2);

	fd = open("empty.txt", O_RDONLY);
	fd2 = open("empty_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("fd == %d | empty.txt\n", fd);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s", res);
		write(fd2, res, strlen(res));
		free(res);
	}
	close(fd);
	close(fd2);

	fd = open("41_no_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file open failed\n");
		return (0);
	}
	fd2 = open("41_no_nl_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd2 == -1)
	{
		printf("file2 open failed\n");
		return (0);
	}
	printf("fd == %d | 41_no_nl.txt\n", fd);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s", res);
		write(fd2, res, strlen(res));
		free(res);
	}
	close(fd);
	close(fd2);
	
	fd = open("big_line.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file open failed\n");
		return (0);
	}
	fd2 = open("big_line_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd2 == -1)
	{
		printf("file2 open failed\n");
		return (0);
	}
	printf("fd == %d | big_line.txt\n", fd);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s", res);
		write(fd2, res, strlen(res));
		free(res);
	}
	close(fd);
	close(fd2);

	fd = open("read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file open failed\n");
		return (0);
	}
	fd2 = open("read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd2 == -1)
	{
		printf("file2 open failed\n");
		return (0);
	}
	printf("fd == %d | read_error.txt\n", fd);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s", res);
		write(fd2, res, strlen(res));
		free(res);
	}
	close(fd);
	close(fd2);
	// Standard input
	// fd = 0;
	// while (printf("%s", get_next_line(fd)) != 0)	;
	// printf("%s", get_next_line(fd));

}
