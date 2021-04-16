/* Nathan Azoulay, Cssc3302, Red ID: 821871239
 * Erik Morua , Cssc3333, Red ID: 816670615
 * CS570, Professor Roch
 * Spring 2021
 * Program 1
 * myls.c
 * The program will replicate the "ls" command which lists files in a directory
 * An input of the "-h" flag will print hidden files and directories that include a "."
 */

#include "myls.h"
int flag = 0;
int main(int argc, char **argv){    
    int count = 1;

    if(argc == 1){ // When argc == 1, this means there are no arguments and will print all the files listed in the current directory
        printdir(".");
    }

    //if more than 1 input at command line, we check to see if the =h flag is set
    //-h flag will print hidden files or directories that start with "."
    if(argc > 1){
        //if argv[1] = -h show hidden
        if(strcmp(argv[1], "-h") == 0){
            flag = 1;
            if(argc == 2){
            printdir(".");
        }   
        // print non hidden regular files/directories
        else{
            count++;
            }
        }
    }
   
    // Loop through each argument(directory) and call our printdir method
    while(++count <= argc){ 
        printdir(argv[count-1]);
    }

    return 0;
}


int printdir(const char *path){
    struct dirent *dp;
    DIR *dir;
    dir = opendir(path);
    //checks for an empty directory.
    if(dir == NULL){
        return -1;
    } 
    
    //if "-h" isn't found 
    if(flag == 0){
        //dp adds the name of the current directory and prints until done
        while((dp = readdir(dir)) != NULL){
            //ignores files/directories with a "." meaning hidden
            if(dp->d_name[0] != '.')
                printf("%s\n",dp->d_name);
        }
    }
    //flag  = 1
    else{
        //when flag is 1, also print hidden directories.
        while((dp = readdir(dir)) != NULL){
            printf("%s\n",dp->d_name);
        }
    }

    closedir(dir);
    return 0;
}//end printdir
    


