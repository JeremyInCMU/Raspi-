/*
 * rot13.c: ROT13 cipher test application
 *
 * Authors: Group Member 1 <email address>
 *          Group Member 2 <email address>
 * Date:    The current time & date
 */
# include "stdlib.h"
# include "unistd.h"
# include "../libc/include/bits/fileno.h"
# define BUF_SIZE 128
# define ROT_NUM 13

int main(int argc, char **argv) {
    /** check the argument is as expected */
    int i,j,k;
    char input_buf[BUF_SIZE];
    char output_buf[BUF_SIZE]; 
    int read_bytes;
    int write_bytes;
    
    for(i = 1; i < argc; i++) {
        write_bytes = write(STDOUT_FILENO, argv[i], 4);
        if(write_bytes < 0) {
            exit(1);
        }
    }

    /** keep reading from stdin */
    while(1) {
        read_bytes = read(STDIN_FILENO, input_buf, BUF_SIZE);
        if(read_bytes == 0 || read_bytes == 1){
            exit(0);
        } else if (read_bytes < 0) {
            exit(1);
        }

     
        /** deploy the algorithm to manipulate string */
        for( j = 0; j < read_bytes - 1; j+=2*ROT_NUM) {
            for (k = 0; k< ROT_NUM; k++) {
                if(j + k + ROT_NUM < read_bytes - 1) {
                    output_buf[j + k] = input_buf[j + k + ROT_NUM];
                    output_buf[j + k + ROT_NUM] = input_buf[j + k];
                } else {
                    output_buf[j + k] = input_buf[j + k];
                    output_buf[j + k + ROT_NUM] = input_buf[j + k + ROT_NUM];
                }
            }
        }
        output_buf[j] = '\n';
        output_buf[j+1] = '\0';

        /** print out the results to the terminal */
        write_bytes = write(STDOUT_FILENO, output_buf, BUF_SIZE);   
    }
}
