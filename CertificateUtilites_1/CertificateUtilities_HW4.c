/*****************************************************
 * 
 * Author:  CYBV310 Students and Instructor
 *
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////
int GetRelativeDistinguishedName(char *rdnAttribute, char *rdnValue);
char* TrimRight(char* str, const char* trimChars);

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char **argv) {
    char commonName[256];
    char organization[256];
    char country[256];

    GetRelativeDistinguishedName("CN", commonName);
    GetRelativeDistinguishedName("O", organization);
    GetRelativeDistinguishedName("C", country);

    printf("\nThe Distinguished Name (DN) is:\n");
    if (strlen(commonName) != 0) {
        printf("CN=%s\n", commonName);
    }

    if (strlen(organization) != 0) {
        printf("O=%s\n", organization);     /* The IF statements will print the value */
    }                                       /* if the string length is not equal to zero */

    if (strlen(country) != 0) {
        printf("C=%s\n", country);
    }
    return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char *rdnValue) {
    int result = -1;
    rdnValue[0] = '\0';

    printf("Please enter the value for %s: ", rdnAttribute);
    fgets(rdnValue, 256, stdin);
    if (strlen(rdnValue) > 0 ) {
        TrimRight(rdnValue, NULL);
        result = 0;
    }
    return result;
}

/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars) {
    int i;

    if (trimChars == NULL) {
        trimChars = "\t\n\v\f\r ";
    }

    i = strlen(str) - 1;
    while (i >= 0 && strchr(trimChars, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}
