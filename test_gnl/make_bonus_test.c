#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"

void	print_line();
char	*diffq_command(char *command, char *input, char *output);
char	*diff_command(char *command, char *input, char *output);
void	diff(char *input, char *output);

int	main(int argc, char *argv[])
{
	char	command[300];
	int		ret;

	// test.out 실행
	printf("./a.out\n"); print_line();
	system("./a.out");
	print_line(); puts("");

	// valgrind 실행
	printf(YELLOW "Valgrind test\n" RESET "valgrind --leak-check=full ./a.out\n"); print_line();
	system("valgrind --leak-check=full ./a.out > valgrind.txt");
	print_line(); puts("");

	// diff 실행
	printf(YELLOW "Diff test\n" RESET);
	diff("text.txt", "text_user.txt");
	diff("empty.txt", "empty_user.txt");
	diff("read_error.txt", "read_error_user.txt");
	diff("big_line.txt", "big_line_user.txt");
	diff("41_no_nl.txt", "41_no_nl_user.txt");
	diff("only_nl.txt", "only_nl_user.txt");
	
	return (0);
}

void	print_line()
{
	for (int i = 0; i < 80; i++)
		printf("=");
	printf("\n");
}

char	*diffq_command(char *command, char *input, char *output)
{
	strcpy(command, "diff -q ");	//명령어
	strcat(command, "srcs/");		//첫 번째 파일 폴더 경로
	strcat(command, input);			//읽은 파일 이름 (ex. empty.txt)
	strcat(command, " ");			//인자 사이 공백
	strcat(command, "srcs/");		//두 번째 파일 폴더 경로
	strcat(command, output);		//결과 파일 이름 (ex. empty_user.txt)
	return (command);
}

char	*diff_command(char *command, char *input, char *output)
{
	strcpy(command, "diff -c -d ");	//명령어
	strcat(command, "srcs/");		//첫 번째 파일 폴더 경로
	strcat(command, input);			//읽은 파일 이름 (ex. empty.txt)
	strcat(command, " ");			//인자 사이 공백
	strcat(command, "srcs/");		//두 번째 파일 폴더 경로
	strcat(command, output);		//결과 파일 이름 (ex. empty_user.txt)
	return (command);
}

void	diff(char *input, char *output)
{
	char	command[300];
	int	ret;

	diffq_command(command, input, output);
	ret = system(command);
	if (ret == 0)
		printf("%s => diff " GREEN "OK!" RESET "\n", command);
	else {
		printf("%s => diff " RED "KO!\n" RESET, diff_command(command, input, output));
		diff_command(command, input, output);
		system(command);
	}
	sleep(1.5);
}
