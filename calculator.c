#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(const char *prog)
{
    printf("Usage: %s <operation> <num1> <num2>\n", prog);
    printf("Operations: add, sub, mul, div\n");
    printf("Example: %s add 5 3\n", prog);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }
    
    double a = atof(argv[2]);
    double b = atof(argv[3]);
    double result;
    
    if (strcmp(argv[1], "add") == 0) {
        result = a + b;
    } else if (strcmp(argv[1], "sub") == 0) {
        result = a - b;
    } else if (strcmp(argv[1], "mul") == 0) {
        result = a * b;
    } else if (strcmp(argv[1], "div") == 0) {
        if (b == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            return 1;
        }
        result = a / b;
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        print_usage(argv[0]);
        return 1;
    }
    
    printf("%.2f\n", result);
    return 0;
}