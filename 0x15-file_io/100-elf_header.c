#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUF_SIZE 1024

void print_error(const char *msg);

void print_hex(const char *prefix, const char *buf, size_t size);

void print_header(const Elf64_Ehdr *header);

int main(int argc, char *argv[]);

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

void print_hex(const char *prefix, const char *buf, size_t size) {
    size_t i;
    printf("%s", prefix);
    for (i = 0; i < size; i++) {
        printf("%02x ", (unsigned char) buf[i]);
    }
    printf("\n");
}

void print_header(const Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    print_hex("  Magic:   ", header->e_ident, EI_NIDENT);
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
    printf("  Entry point address:               %lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    int fd;
    ssize_t nread;
    char buf[BUF_SIZE];
    Elf64_Ehdr *header;
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Could not open file");
    }
    nread = read(fd, buf, BUF_SIZE);
    if (nread < 0) {
        print_error("Could not read file");
    }
    header = (Elf64_Ehdr *) buf;
    if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }
    print_header(header);
    return 0;
}

