#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 4096

int main(int argc, char **argv) {
    int fd;
    char buffer[MAX_LINE];
    int bytes;
    
    if (argc == 1) {
        fd = 0;
        while ((bytes = read(fd, buffer, MAX_LINE)) > 0) {
            write(1, buffer, bytes);
        }
        if (bytes < 0) {
            perror("read");
            return 1;
        }
    } else {
        for (int i = 1; i < argc; ++i) {
            fd = open(argv[i], O_RDONLY);
            if (fd < 0) {
                perror(argv[i]);
                continue;
            }
            while ((bytes = read(fd, buffer, MAX_LINE)) > 0) {
                write(1, buffer, bytes);
            }
            if (bytes < 0) {
                perror("read");
                return 1;
            }
            close(fd);  
        }
    }
}