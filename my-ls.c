#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

bool is_file(const char *path)
{
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool is_dir(const char *path)
{
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

int main(int argc, char *argv[])
{

    DIR *temp;
    struct dirent *directory;
    char *ptr;

    //if they provide a directory
    if (argc == 2)
    {
        temp = opendir(argv[1]);
        if (temp == NULL)
        {
            fprintf(stderr, "%s", "Bad File!\n");
        }
        while ((directory = readdir(temp)) != NULL)
        {
            if (directory->d_name[0] != '.')
            {
                //check to see if its a file or a directory

                ptr = strcat(argv[1], "/");
                ptr = strcat(ptr, directory->d_name);

                if (is_file(ptr))
                {
                    printf("%s\n", directory->d_name);
                }
                else if (is_dir(ptr))
                {
                    printf("%s\n", directory->d_name);
                }
            }
        }

        closedir(temp);
    }
    else if (argc == 1)
    {
        temp = opendir(".");
        if (temp == NULL)
        {
            fprintf(stderr, "%s", "Bad File!\n");
        }

        while ((directory = readdir(temp)) != NULL)
        {
            if (directory->d_name[0] != '.')
            {
                ptr = strcat(argv[1], "/");
                ptr = strcat(ptr, directory->d_name);

                if (is_file(ptr))
                {
                    printf("%s\n", directory->d_name);
                }
                else if (is_dir(ptr))
                {
                    printf("%s\n", directory->d_name);
                }
            }
        }

        closedir(temp);
    }

    // if (argc == 0)
    // {
    //     //use current directory
    //     temp = opendir(".");
    //     if (temp)
    //     {
    //         //opened the directory
    //         DIR *d;
    //         struct dirent *dir;
    //         d = opendir(".");
    //         if (d)
    //         {
    //             while ((dir = readdir(d)) != NULL)
    //             {
    //                 //check if directory and add /
    //                 printf("%s\n", dir->d_name);
    //             }
    //             closedir(d);
    //         }
    //         closedir(temp);
    //     }
    // }
    // else
    // {
    //     //use the user input
    //     if (argc > 1)
    //     {
    //         //print error, too many arguments
    //         fprintf(stderr, "%s", "Too Many Arguments!\n");
    //     }
    //     else
    //     {
    //         //print all the files in said directory
    //         temp = opendir(argv[1]);
    //         if (temp)
    //         {
    //             DIR *d;
    //             struct dirent *dir;
    //             d = opendir(".");
    //             if (d)
    //             {
    //                 while ((dir = readdir(d)) != NULL)
    //                 {
    //                     //check if directory and add /
    //                     printf("%s\n", dir->d_name);
    //                 }
    //                 closedir(d);
    //             }
    //             closedir(temp);
    //         }
    //     }
    // }
    return 0;
}