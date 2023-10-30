#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/* Function Prototypes */
void handle_read_error(char *file);
void handle_write_error(char *file);
void handle_close_error(int fd);
void copy_file_contents(int src_fd, int dest_fd,
char *src_file, char *dest_file);
int open_source_file(char *file);
int create_dest_file(char *file);

/**
 * main - Entry point, copies contents of one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, exit codes for various errors.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open_source_file(argv[1]);
	file_to = create_dest_file(argv[2]);

	copy_file_contents(file_from, file_to, argv[1], argv[2]);

	if (close(file_from) == -1)
		handle_close_error(file_from);
	if (close(file_to) == -1)
		handle_close_error(file_to);
	return (0);
}

/**
 * handle_read_error - Handles read errors, prints and exits.
 * @file: The filename that couldn't be read.
 */
void handle_read_error(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * handle_write_error - Handles write errors, prints and exits.
 * @file: The filename that couldn't be written to.
 */
void handle_write_error(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * handle_close_error - Handles close errors, prints and exits.
 * @fd: The file descriptor that couldn't be closed.
 */
void handle_close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * copy_file_contents - Copies content from one file to another.
 * @src_fd: File descriptor of source file.
 * @dest_fd: File descriptor of destination file.
 * @src_file: Source file name for error handling.
 * @dest_file: Destination file name for error handling.
 */
void copy_file_contents(int src_fd, int dest_fd,
						char *src_file, char *dest_file)
{
	ssize_t read_bytes, written_bytes;
	char buffer[BUFFER_SIZE];

	while ((read_bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		written_bytes = write(dest_fd, buffer, read_bytes);
		if (written_bytes != read_bytes)
			handle_write_error(dest_file);
	}

	if (read_bytes == -1)
		handle_read_error(src_file);
}

/**
 * open_source_file - Opens a file for reading.
 * @file: The filename to open.
 * Return: File descriptor of opened file.
 */
int open_source_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		handle_read_error(file);
	return (fd);
}

/**
 * create_dest_file - Creates a file for writing.
 * @file: The filename to create.
 * Return: File descriptor of created file.
 */
int create_dest_file(char *file)
{
	int fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		handle_write_error(file);
	return (fd);
}
