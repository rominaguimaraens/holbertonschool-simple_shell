#include "main.h"

int main(void)
{
	char cmd[100], command[100], *parameters[20];

	char *envp[] = char *"PATH=/bin";

	while (1)
	{
		prompt();
		read_cmd(command, parameters);
		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			_strcpy(cmd, "/bin/");
			_strcat(cmd, command);
			execve(cmd, parameters, envp);
		}
		if (_strcmp(command, "exit") == 0)
		{
			break;
		}
	}
	return (0);
}
