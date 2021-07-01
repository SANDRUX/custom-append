#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{   
    const int file_count = argc - 1;

    FILE * fp[file_count];

    for (int i = 0; i < file_count - 1; i++)
    {
        fp[i] = fopen(argv[i + 1], "r");
    }

    fp[file_count - 1] = fopen(argv[file_count], "w");

    char c;

    for (int i = 0; i < file_count - 1; i++)
    {
        while ((c = fgetc(fp[i])) != EOF)
        {
            fputc(c, fp[file_count - 1]);
        }
    }

    for (int i = 0; i < file_count; i++)
    {
        fclose(fp[i]);
    }
    
    return 0;
}
