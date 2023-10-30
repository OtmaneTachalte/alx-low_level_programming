#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

#define ERR_MSG "Error: Issue with the ELF file\n"
#define ERR_ELF "Error: Not an ELF file\n"

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_class);
void print_data(unsigned char e_data);
void print_version(unsigned char e_version);
void print_osabi(unsigned char e_osabi);
void print_abiversion(unsigned char e_abiversion);
void print_type(unsigned short e_type);
void print_entry(unsigned long int e_entry);

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, ERR_MSG);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, ERR_MSG);
		return (98);
	}

	if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		close(fd);
		fprintf(stderr, ERR_MSG);
		return (98);
	}

	check_elf(ehdr.e_ident);

	printf("ELF Header:\n");
	print_magic(ehdr.e_ident);
	print_class(ehdr.e_ident[EI_CLASS]);
	print_data(ehdr.e_ident[EI_DATA]);
	print_version(ehdr.e_ident[EI_VERSION]);
	print_osabi(ehdr.e_ident[EI_OSABI]);
	print_abiversion(ehdr.e_ident[EI_ABIVERSION]);
	print_type(ehdr.e_type);
	print_entry(ehdr.e_entry);

	close(fd);
	return (0);
}

/**
 * check_elf - Checks if the file is an ELF file
 * @e_ident: Pointer to the ELF identifier
 */
void check_elf(unsigned char *e_ident)
{
	if (memcmp(e_ident, ELFMAG, SELFMAG))
	{
		fprintf(stderr, ERR_ELF);
		exit(98);
	}
}

/**
 * print_magic - Prints the magic numbers of the ELF header
 * @e_ident: Pointer to the ELF identifier
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * print_class - Prints the class of the ELF file
 * @e_class: ELF class
 */
void print_class(unsigned char e_class)
{
	printf("  Class:                             ");
	printf("%s\n", e_class == ELFCLASS64 ? "ELF64" : "ELF32");
}

/**
 * print_data - Prints the data encoding of the ELF file
 * @e_data: ELF data encoding
 */
void print_data(unsigned char e_data)
{
	printf("  Data:                              ");
	printf("%s\n", e_data == ELFDATA2LSB ?
		   "2's complement, little endian" :
		   "2's complement, big endian");
}

/**
 * print_version - Prints the version of the ELF header
 * @e_version: ELF version
 */
void print_version(unsigned char e_version)
{
	printf("  Version:                           ");
	printf("%s\n", e_version == EV_CURRENT ? "1 (current)" : "0");
}

/**
 * print_osabi - Prints the OS/ABI of the ELF file
 * @e_osabi: ELF OS/ABI
 */
void print_osabi(unsigned char e_osabi)
{
	printf("  OS/ABI:                            ");
	switch (e_osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		/* Additional cases for other OS/ABI values */
		default:
			printf("<unknown: %x>\n", e_osabi);
	}
}

/**
 * print_abiversion - Prints the ABI version of the ELF file
 * @e_abiversion: ELF ABI version
 */
void print_abiversion(unsigned char e_abiversion)
{
	printf("  ABI Version:                       %u\n", e_abiversion);
}

/**
 * print_type - Prints the type of the ELF file
 * @e_type: ELF type
 */
void print_type(unsigned short e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		/* Additional cases for other e_type values */
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point address of the ELF file
 * @e_entry: ELF entry point address
 */
void print_entry(unsigned long int e_entry)
{
	printf("  Entry point address:               0x%lx\n", e_entry);
}
