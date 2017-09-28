//Functions
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_INPUT_SIZE 256
#define MAX_DUMMY_SIZE 32
#define MAX_OUTPUT_SIZE 256

int skipperNotNeeded = 0;

//Shows Version info
void DisplayVer() {
    // Variable Setup
    int build;
    char version[] = "0.0.4";
    char branch[] = "Alpha/Dev";
    build = 46;


    //Displaying Version
    printf("Just a Suite\n");
    printf("Copyright HG-MainDev\n");
    printf("Branch %s\n", branch);
    printf("Version %s\n", version);
    printf("Build %d\n", build);
}

//Checks Magic Number and halts, if needed
int checkMagicNumber() {
    //Variable Setup
    char * magicNumberInput = malloc(MAX_INPUT_SIZE);
    if(!magicNumberInput) halt(3);
    long magicNumberInputs;
    int inaproppiate = 666;
    int magic = getMagicNumber();
    int error;

    //Scans magicNumberInput
    getString("Please type in your magic number to pass:", magicNumberInput, MAX_INPUT_SIZE);

    //Converting variable
    magicNumberInputs = strtol(magicNumberInput, NULL, 10);

    //Checks if input is magic(input from main program)
    if(magicNumberInputs == magic) {
        printTime();
        printf("\nYou passed.. But this Program is in Alpha!\n");
        skipperNotNeeded = 1;
        menu();
    } else if(magicNumberInput == inaproppiate){
        error = halt(2);
        return error;
    } else {
        error = halt(1);
        return error;
    }
}

//Shows numbers
void number() {
    // Variable Setup
    int number;
    char * max = malloc(MAX_INPUT_SIZE);
    if(!max) abort;
    long maxs;

    //Gets max value
    getString("How many numbers do you want to print:", max, MAX_INPUT_SIZE);

    //Converting max
    maxs = strtol(max, NULL, 10);

    //Number Loop
    for (number=0; number<maxs; number++) {
        printf("Number %d\n", number+1);
    }

    printf("\nSuccess!\n");

    skipperNotNeeded = 1;

    free(max);
}

//Halts with error code
int halt(int error_code){
    int *pointer = &error_code;

    printf("\nThis Program halted. Error Code %d\n", *pointer);
    return *pointer;
}

//Prints time
void printTime(){
    //Variable Setup
    time_t now;
    now = time(0);

    //Printing message
    printf("\nGood Day, User. The time and date is %s\n", ctime(&now));
}

void menu(){
    //Variable Setup
    char * input = malloc(MAX_INPUT_SIZE);
    if(!input) abort;
    char * dummyy = malloc(MAX_DUMMY_SIZE);
    if(!dummyy) abort;
    long inputs;
    int menuON;
    menuON = 1;
    

    //While Loop
    while(menuON == 1) {

        //Bugfix for Bug("Codename Skipper")
        if(skipperNotNeeded == 0){
            getString("", dummyy, MAX_DUMMY_SIZE);
        }

        //Main Menu
        printf("\nMain Menu:\n");
        printf("1. Show numbers\n");
        printf("2. Do simple math\n");
        printf("3. Change magic number\n");
        printf("4. Text Editor\n");
        printf("5. Exit\n");
        getString("Selection:", input, MAX_INPUT_SIZE);

        //Converts input
        inputs = strtol(input, NULL, 10);

        //Checks input
        switch( inputs ){
            case 1:
                number();
                continue;
            case 2:
                math();
                continue;
            case 3:
                changeMagicNumber();
                continue;
            case 4:
                textEditor();
                continue;
            case 5:
                printf("\nExiting...\n");
                menuON = 0;
                break;
            default:
                printf("\nWrong selection!\n");
                continue;
        }
    }

    free(input);
    free(dummyy);

}

void wip(int priority) {
    printf("\nThis program is in WIP and has an priority of %d\n", priority);
}

int math() {
    char * first = malloc(MAX_INPUT_SIZE);
    if(!first) abort;
    long firsts;
    char * second = malloc(MAX_INPUT_SIZE);
    if(!second) abort;
    long seconds;
    int result;
    char * input = malloc(MAX_INPUT_SIZE);
    if(!input) abort;
    long inputs;
    char * dummyy = malloc(MAX_DUMMY_SIZE);
    if(!dummyy) abort;
    int mathON = 1;
    int skipperFixed = 0;

    while(mathON == 1) {

        //Bugfix for Bug("Codename Skipper")
        //if(skipperFixed == 0){
            //getString("", dummyy, MAX_DUMMY_SIZE);
            //skipperFixed = 1;
        //}
        
        //Gets numbers
        getString("\nPlease type in your first number:", first, MAX_INPUT_SIZE);
        getString("\nPlease type in your second number:", second, MAX_INPUT_SIZE);

        //Converting numbers
        firsts = strtol(first,NULL,10);
        seconds = strtol(second,NULL,10);

        //Gets input value
        printf("\nWhich type of math do you want?\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        getString("Selection:", input, MAX_INPUT_SIZE);
        inputs = strtol(input,NULL,10);

        //Checks Input
        switch( inputs ){
            case 1:
                result = firsts + seconds;
                printf("\nYour result is: %d\n", result);
                mathON = 0;
                break;
            case 2:
                result = firsts - seconds;
                printf("\nYour result is: %d\n", result);
                mathON = 0;
                break;
            case 3:
                result = firsts * seconds;
                printf("\nYour result is: %d\n", result);
                mathON = 0;
                break;
            case 4:
                result = firsts / seconds;
                printf("\nYour result is: %d\n", result);
                mathON = 0;
                break;
            default:
                printf("\nWrong selection!\n");
                continue;
        }
    }

    skipperNotNeeded = 1;

    free(first);
    free(second);
    free(input);
    free(dummyy);
}

void changeMagicNumber(){
    //Variable Setup
    char * magicNumber1 = malloc(MAX_INPUT_SIZE);
    if(!magicNumber1) abort;
    long magicNumber1s;
    char * magicNumber2 = malloc(MAX_INPUT_SIZE);
    if(!magicNumber2) abort;
    long magicNumber2s;
    int correct;
    correct = 0;
    char magicPath[] = "../magic/magic.txt";

    while(correct == 0) {
        getString("\nPlease type your new magic number in:", magicNumber1, MAX_INPUT_SIZE);
        getString("And again:", magicNumber2, MAX_INPUT_SIZE);

        //Converting variables
        magicNumber1s = strtol(magicNumber1, NULL, 10);
        magicNumber2s = strtol(magicNumber2, NULL, 10);

        if(magicNumber1s == magicNumber2s){
            correct = 1;
            break;
        } else {
            printf("Wrong passwords!\n");
            continue;
        }
    }

    //Write magic number
    FILE *fp;
    fopen_s(&fp, magicPath, "w");
    fprintf_s(fp, "%d", magicNumber1s);
    fclose(fp);

    skipperNotNeeded = 1;

    printf("Success!\n");
}

int getMagicNumber() {
    //Variable Setup
    char magicPath[] = "../magic/magic.txt";
    int magicNumber;

    FILE *fp;
    fopen_s(&fp, magicPath, "r");
    fscanf_s(fp, "%d", &magicNumber);
    fclose(fp);

    return magicNumber;
}

void textEditor() {
    //Variable Setup
    int input;
    int finished = 0;
    
    //Menu
    while(finished == 0){
        printf("\nText Edit:\n");
        printf("1. Create\n");
        printf("2. Edit\n");
        printf("3. View\n");
        printf("4. Exit\n");
        printf("Selection: ");
        scanf("%d", &input);
    
        switch( input ){
            case 1:
                createFile();
                continue;
            case 2:
                editFile();
                continue;
            case 3:
                readFile();
                continue;
            case 4:
                finished = 1;
                break;
            default:
                printf("\nWrong selection!\n");
                continue;
        }
    }

    skipperNotNeeded = 0;
}

void createFile(){
    //Variable Setup
    char * basicFilePath = "../files/";
    char * fileName1 = malloc(MAX_INPUT_SIZE);
    if(!fileName1) abort;
    char * lineTypedIn = malloc(MAX_INPUT_SIZE);
    if(!lineTypedIn) abort;
    char * header = "HEADER\"DON'T DELETE IF YOU USE M-SUITE TexEdit\"\n";
    char * endheader = "HEADER\"DON'T DELETE IF YOU USE M-SUITE TexEdit\"\n";
    char * newline = "\n";
    char * exitcombo = ",.q";
    char * exitcomboandend = ",.s";
    int textFinished = 0;
    int skipperFixed = 0;
    char * dummyy = malloc(MAX_DUMMY_SIZE);
    if(!dummyy) abort;

    //Setup Lengths
    size_t len1 = strlen(basicFilePath);
    size_t len4 = strlen(newline);

    //Bugfix for Bug("Codename Skipper")
    if(skipperFixed == 0){
        getString("", dummyy, MAX_DUMMY_SIZE);
        skipperFixed = 1;
    }

    //Set filename
    getString("Please type in the file to create:", fileName1, MAX_INPUT_SIZE);

    size_t len2 = strlen(fileName1);
    
    //Concatenate the FilePath
    //Allocates the memory needed for the variable
    char * filePath = malloc(len1 + len2 + 1);

    //If filepath isn't set halt
    if (!filePath) abort;

    //Copy basicFilePath to filePath
    memcpy(filePath,        basicFilePath, len1);
    //Copy fileName to filePath
    memcpy(filePath + len1, fileName1, len2);
    filePath[len1 + len2] = '\0';
    //Done

    //Writes Header
    FILE *fp;
    fopen_s(&fp, filePath, "w");
    fprintf_s(fp, header);
    fclose(fp);

    //Opens file for writing
    fopen_s(&fp, filePath, "a");

    //Editing Loop
    while(textFinished == 0){
        //Gets line
        getString("Please type in your line:", lineTypedIn, MAX_INPUT_SIZE);
        
        //If line is exit combo, exit
        if(strstr(lineTypedIn, exitcombo)){
            textFinished = 1;
            break;
        } else if(strstr(lineTypedIn, exitcomboandend)){
            //Writes Header
            fprintf_s(fp, endheader);
            textFinished = 1;
            break;
        }

        size_t len3 = strlen(lineTypedIn);

        //Concat newline on Line(Same process)
        char * convertedLine = malloc(len3 + len4 + 1);
        if(!convertedLine) abort;

        memcpy(convertedLine,        lineTypedIn, len3);
        memcpy(convertedLine + len3, newline, len4);
        convertedLine[len3 + len4] = '\0';

        fprintf_s(fp, convertedLine);
    }

    //Saves file
    fclose(fp);

    free(fileName1);
    free(lineTypedIn);
    free(dummyy);

    //Writes success!
    printf("\nSuccess!\n");
}

void getString(char *message, char *variable, int size) {
    printf("\n%s ", message);
    fgets(variable, sizeof(char) * size, stdin);
    sscanf(variable, "%[^\n]", variable);
}

void readFile(){
    //Variable Setup
    char * basicFilePath = "../files/";
    FILE* fp;
    int fileRight = 0;
    int skipperFixed = 0;
    char * fileName1 = malloc(MAX_INPUT_SIZE);
    if(!fileName1) abort;
    char * dummyy = malloc(MAX_DUMMY_SIZE);
    if(!dummyy) abort;
    char * buffer = malloc(MAX_OUTPUT_SIZE);
    if(!buffer) abort;

    //Setup Length of basicFilePath
    size_t len1 = strlen(basicFilePath);

    while(fileRight == 0){
        //Bugfix for Bug("Codename Skipper")
        if(skipperFixed == 0){
            getString("", dummyy, MAX_DUMMY_SIZE);
            skipperFixed = 1;
        }

        //Set filename
        getString("Please type in the file to read:", fileName1, MAX_INPUT_SIZE);
        size_t len2 = strlen(fileName1);

        //Concatenate the FilePath
        //Allocates the memory needed for the variable
        char * filePath = malloc(len1 + len2 + 1);

        //If filepath isn't set halt
        if (!filePath) abort;

        //Copy basicFilePath to filePath
        memcpy(filePath,        basicFilePath, len1);
        //Copy fileName to filePath
        memcpy(filePath + len1, fileName1, len2);
        filePath[len1 + len2] = '\0';
        //Done

        //Opening file to check if it exists
        fopen_s(&fp, filePath, "r");
        if(fp){
            fileRight = 1;
            fclose(fp);

            //Open file for reading
            fopen_s(&fp, filePath, "r");
            printf("Now reading file %s:\n\n", filePath);
            break;
        } else {
            printf("\nWrong file\n");
            continue;
        }
    }

    while(fgets(buffer, MAX_OUTPUT_SIZE, (FILE*) fp)) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    free(fileName1);
    free(buffer);
    free(dummyy);
    
}

void editFile(){
    //Variable Setup
    char * basicFilePath = "../files/";
    char * fileName1 = malloc(MAX_INPUT_SIZE);
    if(!fileName1) abort;
    char * lineTypedIn = malloc(MAX_INPUT_SIZE);
    if(!lineTypedIn) abort;
    char * endheader = "HEADER\"DON'T DELETE IF YOU USE M-SUITE TexEdit\"\n";
    char * newline = "\n";
    char * exitcombo = ",.q";
    char * exitcomboandend = ",.s";
    int textFinished = 0;
    int fileRight = 0;
    int skipperFixed = 0;
    char * dummyy = malloc(MAX_DUMMY_SIZE);
    FILE* fp;
    if(!dummyy) abort;

    //Setup Lengths
    size_t len1 = strlen(basicFilePath);
    size_t len4 = strlen(newline);

    while(fileRight == 0){
        //Bugfix for Bug("Codename Skipper")
        if(skipperFixed == 0){
            getString("", dummyy, MAX_DUMMY_SIZE);
            skipperFixed = 1;
        }

        //Set filename
        getString("Please type in the file to edit:", fileName1, MAX_INPUT_SIZE);
    
        size_t len2 = strlen(fileName1);
        
        //Concatenate the FilePath
        //Allocates the memory needed for the variable
        char * filePath = malloc(len1 + len2 + 1);
    
        //If filepath isn't set halt
        if (!filePath) abort;
    
        //Copy basicFilePath to filePath
        memcpy(filePath,        basicFilePath, len1);
        //Copy fileName to filePath
        memcpy(filePath + len1, fileName1, len2);
        filePath[len1 + len2] = '\0';
        //Done

        //Opening file to check if it exists
        fopen_s(&fp, filePath, "r");
        if(fp){
            fileRight = 1;
            fclose(fp);

            //Opens file for editing
            fopen_s(&fp, filePath, "a");
            break;
        } else {
            printf("\nWrong file\n");
            continue;
        }
    }

    //Editing Loop
    while(textFinished == 0){
        //Gets line
        getString("Please type in your line:", lineTypedIn, MAX_INPUT_SIZE);
            
        //If line is exit combo, exit
        if(strstr(lineTypedIn, exitcombo)){
            textFinished = 1;
             break;
        } else if(strstr(lineTypedIn, exitcomboandend)){
            //Writes Header
            fprintf_s(fp, endheader);
            textFinished = 1;
            break;
        }
    
        size_t len3 = strlen(lineTypedIn);
    
        //Concat newline on Line(Same process)
        char * convertedLine = malloc(len3 + len4 + 1);
        if(!convertedLine) abort;
    
        memcpy(convertedLine,        lineTypedIn, len3);
        memcpy(convertedLine + len3, newline, len4);
        convertedLine[len3 + len4] = '\0';
    
        fprintf_s(fp, convertedLine);
    }
    
    //Saves file
    fclose(fp);
    
    free(fileName1);
    free(lineTypedIn);
    free(dummyy);
}

#endif // FUNCTIONS_H
