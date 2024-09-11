#include <stdio.h>
#include <stdlib.h>

char* readFile(char*);

int main()
{
   char* test = readFile("res/vertex.glsl");
   fprintf(stdout, test);
   free(test);
}

char* readFile(char* fileName)
{
    char* buffer;
    FILE* filePtr;
    long size;
    size_t result;

    if(!(filePtr = fopen(fileName, "r")))
    {
        fprintf(stderr, "Unable to open file: %s\n", fileName); 
        exit(-1);
    }

    fseek(filePtr, 0, SEEK_END);
    size = ftell(filePtr);
    fprintf(stdout, "%ld\n", size);
    rewind(filePtr);

    if(!(buffer = (char*) malloc(sizeof(char)*size)))
    {
        fprintf(stderr, "Error allocating memory\n");
        exit(-1);
    }

    if((result = fread(buffer, 1, size, filePtr)) != size)
    {
        fprintf(stderr, "Error reading shader file: %s\n", fileName);
        exit(-1);
    }

    fclose(filePtr);

    return buffer;
}