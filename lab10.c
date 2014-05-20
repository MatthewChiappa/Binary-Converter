#include <stdio.h>
#include <stdlib.h>

char* convert(int, int);

int count = 0;

int main(int argc, const char * argv[]){

    int input, i, x;
    
    // opens the file to write to
    FILE *fileOut = fopen(argv[1], "w");
    
    // asks the user to input a positive number
    puts("Enter a positive integer:");
    scanf("%d", &input);
    
    // checks to see if that number is positive
    if (input < 0) {
    	puts("Integer is not positive.");
    	exit(1);
    }
    
    // sends the integer along with the name of the file
    // to write to convert for every base from 2 to 16
    for (i = 1; i < 16; i++) {
        // returns an array with the conversion to the base
        char *output = convert(i+1, input);
        
        // traverses the array and writes the chars to the file
        for (x = count-1; x >= 0; x--)
            fprintf(fileOut, "%c", output[x]);
        fprintf(fileOut, "\n");
        
        if (output)
            free(output);
        
        count = 0;
    }

    fclose(fileOut);
    
    return 0;
}

// converts the number input to whatever base number is called
// then returns a char array
char* convert(int base, int input){
    
    int i = 0, remainder, divisor = input;
    char letterRemain;
    char *output = (char *)malloc(8*sizeof(char));
    if (!output) {
        return  NULL;
    }
    
    // gets the conversion while the divisor is not equal to 0
    while (divisor != 0) {
        remainder = divisor % base;
        
        // if the remainder is greater than 9 it converts the remainder
        // to a letter and puts it in the char array
        if (remainder > 9) {
            switch (remainder) {
                case 10:
                    letterRemain = 'A';
                    break;
                case 11:
                    letterRemain = 'B';
                    break;
                case 12:
                    letterRemain = 'C';
                    break;
                case 13:
                    letterRemain = 'D';
                    break;
                case 14:
                    letterRemain = 'E';
                    break;
                case 15:
                    letterRemain = 'F';
                    break;
                default:
                    letterRemain = 'E';
                    break;
            }
            output[i] = letterRemain;
        }
        else {
            // if the number is not greater than 9 convert the integer
            // to a char then put it in the char array
            letterRemain = (char)(((int)'0')+remainder);
            output[i] = letterRemain;
        }
                
        divisor /= base;
        i++;
        count++;
    }
    
    return output;
}

