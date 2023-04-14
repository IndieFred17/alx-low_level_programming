#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks for Elf files
 * @e_indent: Pointer to an array of Elf magic num.
 * Description: If the file is not an Elf file - exit code 98 is returned.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Print the magic num of Elf header
 * @e_indent: Pointer to an array of Elf magic num.
 * Returns: void
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x ", e_ident[index]);
	}
	printf("\n");
}

/**
 * print_class - Prints the class (32-bit or 64-bit) of the ELF file.
 * @e_indent: Pointer to an array of Elf magic num.
 * Return: void
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - Prints the endianness (little or big) of the ELF file.
 * @e_ident: Pointer to an array of Elf maginc num.
 * Return: void
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints Elf header version
 * @e_indent: Pointer to an array of Elf version
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: ");
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("invalid\n");
			break;
		case EV_CURRENT:
			printf("%d (current)\n", EV_CURRENT);
			break;
		default:
			printf("%d\n", e_ident[EI_VERSION]);
			break;
	}
}

/**
 * print_abi - Prints the ABI version of an Elf header
 * @e_indent: Pointer to an array of Elf version
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_osabi - Prints the OS ABI of an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI: ");

	switch (e_ident[EI_OSABI])
			{
			case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
			case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
			case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
			case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
			case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
			case ELFOSABI_AIX:
			printf("AIX\n");
			break;
			case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
			case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
			case ELFOSABI_TRU64:
			printf("TRU64 UNIX\n");
			break;
			case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
			case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
			default:
			printf("<unknown: 0x%x>\n", e_ident[EI_OSABI]);
			}
}

/**
 * print_type - Prints the ELF file type.
 * @e_type: The ELF file type.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Determines the ELF file type based on the value of e_type and prints it to stdout.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		switch (e_type)
		{
			case ET_NONE:
				printf("Type: NONE\n");
				break;
			case ET_REL:
				printf("Type: REL\n");
				break;
			case ET_EXEC:
				printf("Type: EXEC\n");
				break;
			case ET_DYN:
				printf("Type: DYN\n");
				break;
			case ET_CORE:
				printf("Type: CORE\n");
				break;
			default:
				printf("Type: UNKNOWN\n");
				break;
		}
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		switch (e_type)
		{
			case ET_NONE:
				printf("Type: NONE\n");
				break;
			case ET_REL:
				printf("Type: REL\n");
				break;
			case ET_EXEC:
				printf("Type: EXEC\n");
				break;
			case ET_DYN:
				printf("Type: DYN\n");
				break;
			case ET_CORE:
				printf("Type: CORE\n");
				break;
			default:
				printf("Type: UNKNOWN\n");
				break;
		}
	}
}

/**
 * print_entry - Prints the entry point address of the ELF file.
 * @e_entry: The entry point address of the ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the entry point address of the ELF file to stdout.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("Entry point: 0x%x\n",(unsigned int)e_entry);
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("Entry point: 0x%lx\n", e_entry);
}

/**
 * close_elf - Closes the ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: Closes the ELF file specified by the file descriptor elf
 * and Exits with code 98 if closing the file fails.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close ELF file\n");
		exit(98);
	}
}

/**
 * main - entry point for program that reads
 * and displays information about an ELF file.
 * @argc: The number of arguments passed to the program.
 * @argv: A pointer to an array of pointers to strings
 * and containing the program arguments.
 * Return: 0 on success.
*/

int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		fprintf(stderr, "Error: Cannot read ELF header\n");
			exit(98);
	}
	
	check_elf(header.e_ident);
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_abi(header.e_ident);
	print_osabi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close_elf(fd);
	return (0);
}
