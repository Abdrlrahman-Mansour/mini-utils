#include <stdio.h>

int main(int argc, char *argv[]) {
    // Loop through all arguments (excluding program name)
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" ");  // Add space between arguments
        }
    }
    printf("\n");  // Print a newline at the end
    return 0;
}
