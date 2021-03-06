#include <stdio.h>
#include <string.h>

static void print_welcome()
{
	printf("Welcome to the echo server!\n");
	printf("---------------------------\n");
	printf("The compiled binary is available at echo.pqz.us/echo\n");
	printf("Enter 'source' to get source code\n");
	printf("Otherwise, enter any line to have it printed back to you\n");
}

static void print_source()
{
	FILE * source = fopen("echo.c", "r");
	if (source == NULL) {
		perror("fopen");
		printf("Unable to get source code!");
		return;
	}

	char * buf = NULL;
	size_t len = 0;
	while(getline(&buf, &len, source) > 0) {
		fputs(buf, stdout);
	}

	fclose(source);
}

int main(int argc, char ** argv)
{
	char buffer[128];

	print_welcome();
	printf("Buffer is at 0x%lx\n", buffer);
	printf("Enter line: ");
	fflush(stdout);

	scanf("%s", buffer);

	if (strcmp(buffer, "source") == 0) {
		print_source();
		return;
	}

	printf("You entered: %s\n", buffer);

	return;
}
