#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"

char	*make_command(char *command, int argc, char *argv)
{
	if (argc > 2) {
		printf("Invalid argc");
		return (0);
	}
	if (argc == 1) {
		strcpy(command, "cc ");
		strcat(command, " ../get_next_line.c ../get_next_line_utils.c test.c -o a.out");
	}
	else {
		strcpy(command, "cc -g ");
		strcat(command, "-Wall -Wextra -Werror ");
		strcat(command, "-D BUFFER_SIZE=");
		strcat(command, argv);
		strcat(command, " ../get_next_line.c ../get_next_line_utils.c test.c ");
		strcat(command, "-o a.out");
	}
	return (command);
}

void	print_line()
{
	for (int i = 0; i < 80; i++)
		printf("=");
	printf("\n");
}

char	*diffq_command(char *command, char *input, char *output)
{
	strcpy(command, "diff -q ");
	strcat(command, "srcs/");
	strcat(command, input);
	strcat(command, " ");
	strcat(command, "srcs/");
	strcat(command, output);
	return (command);
}

char	*diff_command(char *command, char *input, char *output)
{
	strcpy(command, "diff -c -d ");
	strcat(command, "srcs/");
	strcat(command, input);
	strcat(command, " ");
	strcat(command, "srcs/");
	strcat(command, output);
	return (command);
}

void	diff(char *input, char *output)
{
	char	command[300];
	int	ret;

	diffq_command(command, input, output);
	ret = system(command);
	if (ret == 0)
		printf("%s => diff " RED "OK!\n" RESET, command);
	else {
		diff_command(command, input, output);
		system(command);
	}
}

int	main(int argc, char *argv[])
{
	char	command[300];
	int		ret;

	make_command(command, argc, argv[1]);
	printf("%s\n", command);
	system(command);
	
	// test.out 실행
	printf("./a.out\n"); print_line();
	system("./a.out");
	print_line(); puts("");

	// valgrind 실행
	printf(RED "valgrind --leak-check=full ./a.out\n"); print_line();
	system("valgrind --leak-check=full ./a.out > valgrind.txt");
	print_line(); puts("");
	printf(RESET);

	// diff 실행
	diff("text.txt", "text_user.txt");
	diff("empty.txt", "empty_user.txt");
	diff("read_error.txt", "read_error_user.txt");
	diff("big_line.txt", "big_line_user.txt");
	diff("41_no_nl.txt", "41_no_nl_user.txt");
	
	return (0);
}
