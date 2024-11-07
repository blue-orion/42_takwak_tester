#include "../get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"

char	*get_next_line(int fd);

void	gnl_loop(int fd, int fd2)
{
	char	*res;

	for (int i = 1;; i++)
	{
		if ((res = get_next_line(fd)) == NULL)
			break ;
		printf("-%d-\n%s", i, res);
		write(fd2, res, strlen(res));
		free(res);
	}
}

int	main(void)
{
	int		fd;
	int		fd2;

	// File input
	printf("Invalid fd\n");
	res = get_next_line(-1);

	fd = open("srcs/text.txt", O_RDONLY);
	fd2 = open("srcs/text_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("\nfd == %d | " YELLOW "text.txt\n" RESET, fd);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
	sleep(1);

	fd = open("srcs/empty.txt", O_RDONLY);
	fd2 = open("srcs/empty_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("\nfd == %d | " YELLOW "empty.txt\n" RESET, fd);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
	sleep(1);

	fd = open("srcs/41_no_nl.txt", O_RDONLY);
	fd2 = open("srcs/41_no_nl_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("\nfd == %d | " YELLOW "41_no_nl.txt\n" RESET, fd);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
	sleep(1);
	
	fd = open("srcs/big_line.txt", O_RDONLY);
	fd2 = open("srcs/big_line_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("\nfd == %d | " YELLOW "big_line.txt\n" RESET, fd);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
	sleep(1);

	fd = open("srcs/read_error.txt", O_RDONLY);
	fd2 = open("srcs/read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("\nfd == %d | " YELLOW "read_error.txt\n" RESET, fd);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
	sleep(1);
}
