#include "../get_next_line_bonus.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		cur_fd; int cur_fd_user;
	int		fd; int fd_user;
	int		fd2; int fd2_user;
	int		fd3; int fd3_user;
	int		fd4; int fd4_user;
	char	*res;
	int		cnt;

	printf("Invalid fd\n");
	res = get_next_line(-1);
	printf("res : %s\n", res);
	// File input
	if ((fd = open("text/text.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd_user = open("text/text_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	if ((fd2 = open("text/41_no_nl.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd2_user = open("text/41_no_nl_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	if ((fd3 = open("text/read_error.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd3_user = open("text/read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	if ((fd4 = open("text/big_line.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd4_user = open("text/big_line_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	cnt = 1;
	int	fd_flag = 0;
	int	fd2_flag = 0;
	int	fd3_flag = 0;
	int	fd4_flag = 0;
	while (1)
	{
		if (fd_flag && fd2_flag && fd3_flag && fd4_flag)
			break ;
		for (int i = 3; i <= 9; i += 2)
		{
			cur_fd = i;
			cur_fd_user = i + 1;
			if (cur_fd == 3 && fd_flag == 1)
				continue ;
			if (cur_fd == 5 && fd2_flag == 1)
				continue ;
			if (cur_fd == 7 && fd3_flag == 1)
				continue ;
			if (cur_fd == 9 && fd4_flag == 1)
				continue ;
			res = get_next_line(cur_fd);
			if (res == NULL)
			{
				if (cur_fd == 3)
					fd_flag = 1;
				if (cur_fd == 5)
					fd2_flag = 1;
				if (cur_fd == 7)
					fd3_flag = 1;
				if (cur_fd == 9)
					fd4_flag = 1;
				continue ;
			}
			printf("\nfd = %d\ncall count : %d || ", cur_fd, cnt++);
			printf("%s", res);
			write(cur_fd_user, res, strlen(res));
			free(res);
		}
	}
	close(fd);
	close(fd_user);
	close(fd2);
	close(fd2_user);
	close(fd3);
	close(fd3_user);
	close(fd4);
	close(fd4_user);

	fd = open("text/only_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file open failed\n");
		return (0);
	}
	fd2 = open("text/only_nl_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
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

	fd = open("text/read_error.txt", O_RDONLY); fd2 = open("text/read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
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
	close(fd); close(fd2);
	// fd = 0;
	// while (printf("%s", get_next_line(fd)) != 0)	;
	// printf("%s", get_next_line(fd));

}
