#include "get_next_line.h"
#include <string.h>

/*
int main(void)
{
    int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error creating file");
        return 1;
    }

    const char *text = "This is line 1.\nThis is line 2.\nThis is line 3.";
    if (write(fd, text, strlen(text)) == -1)
    {
        perror("Error writing");
        close(fd);
        return 1;
    }

    close(fd);

    fd = open("test_file.txt", O_RDWR); // Use O_RDWR for read-write access
    if (fd == -1)
    {
        perror("Error opening");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line read: %s\n", line);
        free(line);
    }

    close(fd);

    return 0;
}
*/
/*
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
*/

int main(void)
{
	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	char *line;
	if (fd == -1)
		perror("error creating");
	const char *text = "\nhello";
	if(write(fd, text, strlen(text)) == -1)
	{
		perror("error writing");
		close(fd);
		return 1;
	}
	close(fd);
	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		perror("error opening");
	while (1)
	{
        line = get_next_line(fd);
        printf("%s", line);
        if (!line)
            break ;
		
		free(line);
	}
	close(fd);
	return (0);
}
// add if statement that breaks out the llop if str == null

/*
int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("error creating");
        return 1;
    }

    const char *text = "line 1\nline 2\nline 3";
    if (write(fd, text, strlen(text)) == -1)
    {
        perror("error writing");
        close(fd);
        return 1;
    }

    close(fd);

    fd = open("test.txt", O_RDONLY); // Use O_RDONLY for reading
    if (fd == -1)
    {
        perror("error opening");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line = %s\n", line);
        free(line); // Free memory allocated by get_next_line
    }

    close(fd);
    return 0;
}
*/