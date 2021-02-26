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
#define MAX_RDN_LENGTH     256
#define RDN_CN   "CN"
#define RDN_O    "O"
#define RDN_OU   "OU"
#define RDN_C    "C"
#define RDN_L    "L"
#define RDN_ST   "ST"

///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////
/* DistinguishedName is a structure of RDN values. */
typedef struct {
    char commonName[MAX_RDN_LENGTH];
    char organization[MAX_RDN_LENGTH];
    char county[MAX_RDN_LENGTH];
    char organizationUnit[MAX_RDN_LENGTH];
    char locality[MAX_RDN_LENGTH];
    char state[MAX_RDN_LENGTH];
} DistinguishedName;

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////
int GetRelativeDistinguishedName(char *rdnAttribute, char* rdnDescription, char *rdnValue);
char* TrimRight(char* str, const char* trimChars);
void PrintDistinguishedName(DistinguishedName *pDN);

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////

/*****************************************************
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
******************************************************/
int main(int argc, char **argv) {
    DistinguishedName distinguishedName;

    /* function repeated 6 times for DistinguishedName struct members */
    GetRelativeDistinguishedName(RDN_CN, "Common Name", distinguishedName.commonName);
    GetRelativeDistinguishedName(RDN_O, "Organization", distinguishedName.organization);
    GetRelativeDistinguishedName(RDN_OU, "Organization Unit", distinguishedName.organizationUnit);
    GetRelativeDistinguishedName(RDN_C, "County", distinguishedName.county);
    GetRelativeDistinguishedName(RDN_L, "Locality", distinguishedName.locality);
    GetRelativeDistinguishedName(RDN_ST, "State", distinguishedName.state);

    /* populated struct memory address passed into function  */
    PrintDistinguishedName(&distinguishedName);
    return 0;
}

/*****************************************************
 * GetRelativeDistinguishedName
******************************************************/                   /* arg for struct member */
int GetRelativeDistinguishedName(char *rdnAttribute, char* rdnDescription, char *rdnValue) {
    int result = -1;
    rdnValue[0] = '\0';

    printf("Please enter the value for %s (%s): ", rdnDescription, rdnAttribute);
    fgets(rdnValue, 256, stdin);
    if (strlen(rdnValue) > 0 ) {
        TrimRight(rdnValue, NULL);
        result = 0;
    }
    return result;
}

/******************************************************************************
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
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

/*****************************************************
 * PrintDistinguishedName()
******************************************************/
void PrintDistinguishedName(DistinguishedName *pDN) {
    /* prints string length of struct members */
    printf("\nCN len: %i\n", strlen(pDN->commonName));
    printf("O len: %i\n", strlen(pDN->organization));
    printf("OU len: %i\n", strlen(pDN->organizationUnit));
    printf("C len: %i\n", strlen(pDN->county));
    printf("L len: %i\n", strlen(pDN->locality));
    printf("S len: %i\n", strlen(pDN->state));

    /* prints struct member if string length is greater than 0 */
    if(strlen(pDN->commonName) > 0)
         printf("\nCommon Name: %s", pDN->commonName);

    if(strlen(pDN->organization) > 0)
         printf("\nOrganization: %s", pDN->organization);

    if(strlen(pDN->organizationUnit) > 0)
         printf("\nOrganization Unit:  %s", pDN->organizationUnit);

    if(strlen(pDN->county) > 0)
         printf("\nCounty: %s", pDN->county);

    if(strlen(pDN->locality) > 0)
         printf("\nLocality: %s", pDN->locality);

    if(strlen(pDN->state) > 0)
         printf("\nState: %s", pDN->state);
}
