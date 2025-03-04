#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024  // Define buffer size for copying

void copy_file(const char *source, const char *destination) {
    FILE *src, *dest;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open source file for reading
    src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing
    dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        exit(EXIT_FAILURE);
    }

    // Read from source and write to destination
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    // Close files
    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    copy_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

