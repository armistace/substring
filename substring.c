#include <stdio.h>
#include <stdlib.h>

int sub_string(char* string1, char* string2);

double string_length(char* string);

int main(int argc, char *argv[]) {
    //cli checkers
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 0;
    }

    //Got Vars!
    char* string1;
    char* string2;
    int substring;

    //get the args
    string1 = argv[1];
    string2 = argv[2];

    //is is what now?
    substring = sub_string(string1, string2);

    if (substring == 1) {
        printf("%s is a substring of %s\n", string2, string1);
    } else if (substring == 0) {
        printf("%s is not a substring of %s\n", string2, string1);
    } else {
        printf("it appears one of the strings were null or another error occured\n");
    }

    return 0;
} 

//string length!
double string_length(char* string) {
    char current_char = 'a';
    double len = 0.0;
    int i = 0;
    while (current_char != '\0') {
        current_char = string[i];
        len += 1;
        i ++;
    }

    //it that this algo adds and extra value to the length
    //so we simply minux it :D
    return len;
}

//C does not have a bool type apparently so I am going to use an int 
//better error handling anyway (gives me a two!)
int sub_string(char* string1, char* string2) {
    /* will determine if string2 is a sub string of string1 */
    
    //if either string is null I am calling this an error
    //could technically return true 
    if (string1 == NULL || string2 == NULL) {
        return 2;
    }
    
    //so we need to loop through the first string
    for (int i = 0; i<string_length(string1); i++) {

        //If I detect that we have a same letter we need to do some checking
        if (string1[i] == string2[0]) {
            
            //set up an integer to count how many are the same
            int count_check = 0;

            //loop through the second string
            for (int j = 0; j<string_length(string2); j++) { 
                //if count check is the same lengthe as string 2 we have a 
                //sub string!
                if (count_check == string_length(string2) - 1) { //This minus one seems magical 
                                                                 //It is not it is here because I don't want to 
                                                                 //count the '\0'

                    return 1;

                //this will increment us through the strings checking they are the same
                //i + j will keep string1 in check
                } else if (string1[i+j] == string2[j]) {
                    count_check ++;

                //if we got to here something it's not a substring but we can keep looking
                } else {
                    break;
                }
            }
        }
    }

    //if we get to here than it is not a substring
    return 0;
}

                    
                    


    








