#include "../get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"
#define SEC 300000

char	*get_next_line(int fd);
void	gnl_loop(int fd, int fd2);
void	my_sleep(int seconds)
{
	if (getenv("NO_SLEEP") == NULL)
		usleep(seconds);
}
void	print_line()
{
	for (int i = 0; i < 80; i++)
		printf("=");
	printf("\n");
}

int	main(void)
{
	int		fd;
	int		fd2;

	// File input
	printf(YELLOW "Invalid fd(fd == -1)" RESET "\n");
	printf("Expected = (null) | Your result = %s\n", get_next_line(-1));

	printf(YELLOW "\ntext.txt" RESET "\n");
	print_line(); system("cat srcs/text.txt"); print_line();
	my_sleep(7 * SEC);
	fd = open("srcs/text.txt", O_RDONLY);
	fd2 = open("srcs/text_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);

	printf(YELLOW "\nempty.txt" RESET "\n");
	print_line(); system("cat srcs/empty.txt"); print_line();
	my_sleep(7 * SEC);
	fd = open("srcs/empty.txt", O_RDONLY);
	fd2 = open("srcs/empty_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);

	printf(YELLOW "\n41_no_nl.txt" RESET "\n");
	print_line(); system("cat srcs/41_no_nl.txt"); print_line();
	my_sleep(7 * SEC);
	fd = open("srcs/41_no_nl.txt", O_RDONLY);
	fd2 = open("srcs/41_no_nl_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
	
	printf(YELLOW "\nbig_line.txt" RESET "\n");
	print_line(); system("cat srcs/big_line.txt"); print_line();
	my_sleep(7 * SEC);
	fd = open("srcs/big_line.txt", O_RDONLY);
	fd2 = open("srcs/big_line_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);

	printf(YELLOW "\nread_error.txt" RESET "\n");
	print_line(); system("cat srcs/read_error.txt"); print_line();
	my_sleep(7 * SEC);
	fd = open("srcs/read_error.txt", O_RDONLY);
	fd2 = open("srcs/read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
}

void	gnl_loop(int fd, int fd2)
{
	char	*res;

	for (int i = 1;; i++)
	{
		if ((res = get_next_line(fd)) == NULL)
			break ;
		my_sleep(SEC);
		printf("-%d-\n%s", i, res);
		write(fd2, res, strlen(res));
		free(res);
	}
}
