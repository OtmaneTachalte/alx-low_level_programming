#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define READ_BYTES 64

/* Function Prototypes */
void check_if_elf(unsigned char *e_ident);
void print_magic_numbers(unsigned char *e_ident);
void print_class_info(unsigned char *e_ident);
void print_data_info(unsigned char *e_ident);
void print_version_info(unsigned char *e_ident);
void close_file(int fd);

/**
 * check_if_elf - Validates if file is an ELF file.
 * @e_ident: Pointer to ELF magic numbers.
 */
void check_if_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
		e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic_numbers - Prints the magic numbers.
 * @e_ident: Pointer to ELF magic numbers.
 */
void print_magic_numbers(unsigned char *e_ident)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * Additional function definitions for class, data,
 * version, and others as per the original functionality.
 */

/**
 * close_file - Closes the file descriptor.
 * @fd: File descriptor.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		fprintf(stderr, "Error: Can't close file descriptor %d\n", fd);
		exit(98);
	}
}

/**
 * main - Entry point, processes ELF header.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	unsigned char e_ident[READ_BYTES];
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	bytes_read = read(fd, e_ident, READ_BYTES);
	if (bytes_read != READ_BYTES)
	{
		close_file(fd);
		fprintf(stderr, "Error: Failed to read ELF header\n");
		return (98);
	}

	check_if_elf(e_ident);
	header = (Elf64_Ehdr *)e_ident;

	printf("ELF Header:\n");
	print_magic_numbers(header->e_ident);
	/* Additional printing functions as needed */

	close_file(fd);
	return (0);
}
