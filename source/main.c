#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "functions.h"

// Main Program
int main() {

    // Variable Setup
    int error;

    /*
    Hello World, Disabled
    printf("Hello world!\n");
    */

    DisplayVer();

    //Magic Number
    printf("\nThis Program isn't ready yet!\n");
    error = checkMagicNumber();

    Sleep(2000);
    //Says that program is finished successfully
    return error;
}
