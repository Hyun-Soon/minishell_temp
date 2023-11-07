#include <stdio.h>
#include </usr/local/include/readline/readline.h>
#include </usr/local/include/readline/history.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>


//typedef struct s_bundle
//{
//	char	**envp;
//	int		envp_len;
//	char	*temp_filename; //hyuim : to remove
//	int		pid;
//	int		fd[2];
//}				t_bundle;

//void	go(t_bundle *bundle)
//{
//	int pid = fork();
//	printf("%p\n", bundle);
//	if (pid == 0)
//		bundle->envp_len = 0;
//	if (pid > 0)
//	{
//		wait(0);
//		printf("parent : %d\n", bundle->envp_len);
//	}
//	if (pid == 0)
//		printf("child : %d\n", bundle->envp_len);
//}

//int main()
//{
//	t_bundle bundle;

//	bundle.envp_len = 1;
//	go(&bundle);

//	return (0);
//}

//////////////////////////////////////////////////////

//int main(int argc, char **argv, char **envp)
//{
//	(void)argc;
//	(void)envp;
//	int idx = -1;
//	char *ret = getenv("SECURITYSESSIONID");
//	ret[0] = 'h';
//	printf("%s\n", envp[0]);
//	return 0;
//}

////////////////////////////////////////////////

//int main()
//{
//	while (1)
//	{
//		char *inp = readline(">");
//		printf("%s\n", getenv("PATH"));
//	}
//	return 0;
//}

/////////////////////////////
//int main()
//{
//	execve()
//}

////////////////////////////////////////////////
//int main(int argc, char *argv[], char *envp[])
//{
//	char *a[4] = {"ls", "-a", "-l", NULL};
//	execve("/bin/lss", a, envp);
//	return 0;
//}
////////////////////////////////////////////////

//int main()
//{
//	char **head = (char **)malloc(sizeof(char *) * 3);
//	head[0] = (char *)malloc(3);
//	head[1] = (char *)malloc(3);
//	head[2] = NULL;

//	head[0][0] = 'a';
//	head[0][1] = 'b';
//	head[0][2] = '\0';
//	head[1][0] = 'c';
//	head[1][1] = 'd';
//	head[1][2] = '\0';
//	printf("parent : %p\n", head);
//	int pid = fork();
//	if (pid == 0)
//	{
//		printf("child : %p\n", head);
//		printf("%s\n", head[0]);
//		printf("%s\n", head[1]);
//	}
//}

////////////////////////////////////////////////////

//int main(int argc, char *argv[], char *envp[])
//{
//	char *arvs[2] = {"ls", NULL};
//	if (chdir("../") == -1)
//		printf("here\n");
//	else
//		execve("/bin/ls", arvs, envp);
//}

///////////////////////////////////////////////////
//int main()
//{
//	char **a = (char **)malloc(sizeof(char) * 3);
//	a[0] = (char *)malloc(sizeof(char) * 2);
//	a[1] = (char *)malloc(sizeof(char) * 2);

//	a[0][0] = '1';
//	a[0][1] = '\0';
//	a[1][0] = '2';
//	a[1][1] = '\0';

//	char **b = (char **)malloc(sizeof(char) * 3);
//	b[0] = a[0];
//	b[1] = a[1];
//	free(a);
//	printf("%s\n", b[0]);
//	printf("%s\n", b[1]);
//}

/////////////////////////////////////////////////////////
int main(int argc, char **argv, char **envp)
{
	//signal(SIGINT, sigint_handler_during_fork);
	//signal(SIGQUIT, sigquit_handler_during_fork);
	//char *argvv[3] = {"./asdf", NULL, NULL};
	//if (!access("asdf", F_OK))
	//	execve("./asdf", argvv, envp);
	//perror("access :");
	//return 0;
	while(1);
}

//if access doesn't find file, "No such file or directory"
//if execve but doesn't have permission, "Permission denied"
