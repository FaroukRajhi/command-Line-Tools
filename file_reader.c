#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(const char *prog)
{
    printf("Usage: %s [-n] <filename>\n", prog);
    printf("  -n    Show line numbers\n");
}

int main(int argc, char *argv[])
{
    int show_numbers = 0;
    const char *filename = NULL;

    // Parse arguments

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i],"-n")== 0)
        {
            show_numbers = 1;
        }
        else if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0 )
        {
            print_usage(argv[0]);
            return 0;
        }
        else
        {
            filename = argv[i];
        }

        if(!filename)
        {
            fprintf(stderr,"Error!: no filename\n");
            print_usage(argv[0]);

            return 1;
        }

        FILE *fp = fopen(filename, "r");
          if (!fp) {
        perror("Error opening file");
        return 1;
    }
    
        char line[1024];
        int line_num = 1;
        
        while (fgets(line, sizeof(line), fp)) {
            if (show_numbers) {
                printf("%4d: %s", line_num++, line);
            } else {
                printf("%s", line);
            }
     }
        
        fclose(fp);
        return 0;
    }
}