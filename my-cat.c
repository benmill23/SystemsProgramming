#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int counter = 2;
    char line[256];

    while (counter < argc)
    {
        fp = fopen(argv[counter], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "%s", "Bad File!\n");
        }
        else
        {
            while (fgets(line, sizeof(line), fp))
            {
                printf("%s\n", line);
            }
        }
        counter++;
    }
    fclose(fp);
    return 0;
}