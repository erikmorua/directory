/*
Program 1 MYLS
CS 570 Prof. Roch
Spring 2021
Erik Morua, cssc3333, Red ID: 816670615
Nathan Azoulay, cssc3302 Red ID: 821871239
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

class myls{
    public:
        int printdir(const char *);
}
