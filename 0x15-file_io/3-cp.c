#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void check_arguments(int argc);
int open_source_file(char *file_name);
int open_destination_file(char *file_name);
void copy_content(int file_from, int file_to);
void close_files(int file_from, int file_to);

/**
 * main - Copies the content of a file to another file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	check_arguments(argc);
	file_from = open_source_file(argv[1]);
	file_to = open_destination_file(argv[2]);
	copy_content(file_from, file_to);
	close_files(file_from, file_to);

	return (0);
}

void check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

int open_source_file(char *file_name)
{
	int file_from = open(file_name, O_RDONLY);

	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
		exit(98);
	}
	return (file_from);
}

int open_destination_file(char *file_name)
{
	int file_to = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
		exit(99);
	}
	return (file_to);
}

void copy_content(int file_from, int file_to)
{
	int r, w;
	char buffer[BUFFER_SIZE];

	while ((r = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(file_from);
			close(file_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

void close_files(int file_from, int file_to)
{
	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
}
