#include "../get_next_line_bonus.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"

void	file_close(int fd);
int		is_fileclose(int fd);
void	gnl_loop(int fd, int fd2);
void	print_filename(int fd, char *color);
char	*get_next_line(int fd);
int		fd_flag = 0;
int		fd2_flag = 0;
int		fd3_flag = 0;
int		fd4_flag = 0;

char	*name1 = "srcs/text.txt";
char	*name11 = "srcs/text_user.txt";
char	*name2 = "srcs/41_no_nl.txt";
char	*name22 = "srcs/41_no_nl_user.txt";
char	*name3 = "srcs/only_nl.txt";
char	*name33 = "srcs/only_nl_user.txt";
char	*name4 = "srcs/empty.txt";
char	*name44 = "srcs/empty_user.txt";

int	main(void)
{
	int		cur_fd; int cur_fd_user;
	int		fd; int fd_user;
	int		fd2; int fd2_user;
	int		fd3; int fd3_user;
	int		fd4; int fd4_user;
	char	*res;

	printf(YELLOW "Invalid fd\n" RESET);
	printf("Expected = (null) | Your result = %s\n", get_next_line(-1));

	// File open
	fd = open(name1, O_RDONLY);
	fd_user = open(name11, O_WRONLY | O_CREAT | O_TRUNC);
	fd2 = open(name2, O_RDONLY);
	fd2_user = open(name22, O_WRONLY | O_CREAT | O_TRUNC);
	fd3 = open(name3, O_RDONLY);
	fd3_user = open(name33, O_WRONLY | O_CREAT | O_TRUNC);
	fd4 = open(name4, O_RDONLY);
	fd4_user = open(name44, O_WRONLY | O_CREAT | O_TRUNC);

	// get_next_line test
	// 각 파일을 모두 읽으면 그 파일에 대해선 더 이상 gnl을 호출 안함
	while (1)
	{
		if (fd_flag && fd2_flag && fd3_flag && fd4_flag)
			break ;
		for (int i = 3; i <= 9; i += 2)
		{
			cur_fd = i; cur_fd_user = i + 1;
			if (is_fileclose(cur_fd))
				continue ;
			res = get_next_line(cur_fd);
			if (res == NULL) {
				file_close(cur_fd);
				continue ;
			}
			print_filename(cur_fd, YELLOW);
			printf("(fd = " YELLOW "%d" RESET ")\n%s", cur_fd, res);
			write(cur_fd_user, res, strlen(res));
			free(res);
		}
	}

	// Close File
	close(fd); close(fd_user);
	close(fd2); close(fd2_user);
	close(fd3); close(fd3_user);
	close(fd4); close(fd4_user);

	fd = open("srcs/big_line.txt", O_RDONLY);
	fd2 = open("srcs/big_line_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf(YELLOW "\nbig_line.txt\n" RESET);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);

	fd = open("srcs/read_error.txt", O_RDONLY);
	fd2 = open("srcs/read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf(YELLOW "\nread_error.txt\n" RESET);
	gnl_loop(fd, fd2);
	close(fd); close(fd2);
}

int	is_fileclose(int fd)
{
	if (fd == 3 && fd_flag == 1)
		return (1);
	if (fd == 5 && fd2_flag == 1)
		return (1);
	if (fd == 7 && fd3_flag == 1)
		return (1);
	if (fd == 9 && fd4_flag == 1)
		return (1);
	return (0);
}

void	file_close(int fd)
{
	if (fd == 3)
		fd_flag = 1;
	if (fd == 5)
		fd2_flag = 1;
	if (fd == 7)
		fd3_flag = 1;
	if (fd == 9)
		fd4_flag = 1;
	print_filename(fd, RED);
	printf(RED " close\n" RESET);
}

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

void	print_filename(int fd, char *color)
{
	if (fd == 3)
		printf("%s\n%s" RESET, color, name1 + 5);
	if (fd == 5)
		printf("%s\n%s" RESET, color, name2 + 5);
	if (fd == 7)
		printf("%s\n%s" RESET, color, name3 + 5);
	if (fd == 9)
		printf("%s\n%s" RESET, color, name4 + 5);
}
