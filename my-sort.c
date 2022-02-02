#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int countLines(char *ptr)
{
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen(ptr, "r");
    if (fp == NULL)
    {
        printf("Could not open file \n");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;

    fclose(fp);
    return count;
}

int main(int argc, char *argv[])
{
    int counter = 1;
    int numLines = 0;

    if (argc == 1)
    {
        //read from stdin
    }
    else
    {
        //read from files
        while (counter < argc)
        {
            numLines += countLines(argv[counter]);
            counter++;
        }
    }

    char storage[numLines];

    // iterate through the storage array and sort
    for (int n = 0; n < 1000; n++)
    {
        for (int m = 0; m < 1000; m++)
        {
            if (storage[n][m] > storage[n][m + 1])
            {
                swap(storage[n][m] > storage[n][m + 1]);
            }
        }
    }

    fclose(fp);
    return 0;
}