/*
 * rot13.c: ROT13 cipher test application
 *
 * Authors: Group Member 1 <email address>
 *          Group Member 2 <email address>
 * Date:    The current time & date
 */
# include "stdlib.h"
# include "unistd.h"
# include <bits/fileno.h>
# define BUF_SIZE 100

/** Function declaration */
void caserCipher(char* s, int start_index, int length);
void swap(char* s, int index_1, int index_2);

int main(int argc, void *argv[]) {
    /** check the argument is as expected */
    int i;
    char *input_buf;
    char *output_buf; 
    int readBytes;
    int writeBytes;

    for(i = 0; i < argc; i++) {
        input_buf = (char *)malloc(strlen(argv[i]));
        writeBytes = write(STDOUT_FILENO, buf, argv[i].length);
        if(writeBytes < 0) {
            exit(1);
        }
        free(input_buf);
    }

    /** keep reading from stdin */
    while(1) {
        output_buf = (char *)malloc(BUF_SIZE);
        readBytes = read(STDIN_FILENO, output_buf, BUF_SIZE);
        if(readBytes == 0){
            exit(0)
        } else if(readBytes < 0) {
            exit(1);
        }

        /** deploy the algorithm to manipulate string */
        int j = 0;
        for(; j < strlen(output_buf); j+=13) {
            swap(output_buf, j, strlen(output_buf));
        }
        free(output_buf);
    }
}
/**
 * Helper function: CaserCipher.
 * @param string, the start index;
 */
void caserCipher(char* s, int start_index, int length) {
    int i = 0;
    for(; i < 13; i++) {
        if(start_index + i + 13 < length) {
            swap(s, start_index+i, start_index+i+13);
        }
    }
}

/**
 * Helper function: swap().
 * @param string, index_1, index_2
 */
void swap(char* s, int index_1, int index_2) {
     char temp;
     temp = s[index_1];
     s[index_1] = s[index_2];
     s[index_2] = temp;
}
