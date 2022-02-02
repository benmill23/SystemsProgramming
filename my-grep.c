#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int counter = 2;

    int i = 0;

    int numChar = 5;
    //make a character array of size 100
    char *ptr = malloc(sizeof(char) * numChar);
    //temp pointer to resize
    char *temp;
    char c;
    int count = 0;
    int flag = 1;

    if (argc == 2)
    {
        //read from stdin
        while (scanf("%c", &ptr[count]) != EOF)
        {
            count++;
            if (count == numChar)
            {
                numChar *= 2;
                temp = malloc(sizeof(char) * numChar);
                for (i = 0; i < count; i++)
                {
                    temp[i] = ptr[i];
                    free(ptr);
                }
                free(ptr);
                ptr = temp;
            }
        }
        //now go through and check if it is in the substring
        if (strstr(ptr, argv[1]) != NULL)
        {
            printf("%s\n", ptr);
        }
    }
    else
    {
        while (counter < argc)
        {
            fp = fopen(argv[counter], "r");
            if (fp == NULL)
            {
                fprintf(stderr, "%s", "Bad File!\n");
            }
            else
            {
                //read in the file character at a time until endline
                while ((c = fgetc(fp)) != EOF)
                {
                    //if c is equal to a newline character send it to be processed
                    if (c == '\n')
                    {
                        flag = 0;
                    }

                    if (flag == 1)
                    {
                        count++;
                        if (count == numChar)
                        {
                            numChar *= 2;
                            temp = malloc(sizeof(char) * numChar);
                            for (i = 0; i < count; i++)
                            {
                                temp[i] = ptr[i];
                                free(ptr);
                            }
                            free(ptr);
                            ptr = temp;
                        }
                    }
                    else
                    {
                        //print to screen
                        if (strstr(ptr, argv[1]) != NULL)
                        {
                            printf("%s\n", ptr);
                        }
                        //reset arrays
                        free(ptr);
                        free(temp);

                        ptr = malloc(sizeof(char) * (numChar * 2));

                        flag = 1;
                    }
                }
                free(ptr);
                free(temp);
            }
            counter++;
        }
        free(ptr);
        free(temp);
        fclose(fp);
    }
    return 0;
}