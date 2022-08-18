#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    //length
    char strng[20];
    int count = 0;
    printf("To find Length of string\n");
    printf("############################################\n");
    printf("Enter the string: \n");
    fgets(strng, sizeof strng, stdin);
    
    while(strng[count]!='\0'){
        count++;
    }
    
    printf("Length of string is: %d\n\n" , count-1);
    printf("############################################\n");
    
    //copy
    printf("\n\nTo Copy string\n");
    printf("############################################\n");
    char array1[20], array2[20];
    int i;
    
    printf("\nInput string 1:\n");
    fgets(array1, sizeof array1, stdin);
    
    i=0;
    while(array1[i]!='\0'){
        array2[i] = array1[i];
        i++;
    }
    array2[i] = '\0';
    
    printf("\nEntered string: %s\n", array1);
    printf("Copied string: %s\n", array2);
    printf("############################################\n");
    
    //reverse
    printf("\nTo Reverse a string\n");
    printf("############################################\n");
    char revers[20];
    int m=0;
    
    printf("Enter string to be reversed: \n");
    fgets(revers, sizeof revers, stdin);
    m= strlen(revers);
    
    printf("reversed string is:\n");
    for(revers[m] != '\0'; m>=0; m--){
        printf("%c ", revers[m]);
    }
    printf("\n############################################\n");
    
    //concatenate
    printf("\nTo Concatenate two strings\n");
    printf("############################################\n");
    char con1[20], con2[20];
    int x;
    
    printf("Enter first string: \n");
    scanf("%s" , con1);
    printf("\nEnter second string: \n");
    scanf("%s" , con2);
    for(x=0; con1[x]!='\0'; x++);
    for(int j=0; con2[j]!='\0'; j++){
            con1[x] = con2[j];
            x++;
    }
    
    con1[x] = '\0';
    printf("\nConcatenated strings: %s", con1);
    printf("\n############################################\n");
    
    //compare
    char s1[20], s2[20];
    int k;
    printf("\nString comparision without pointers\n");
    printf("############################################\n");
    printf("Enter first string:\n");
    scanf("%s", s1);
    printf("\nEnter second string:\n");
    scanf("%s", s2);
    
    k = strcmp(s1, s2);
    if(k==0)
       printf("Strings are same");
    else
       printf("Strings are not same");
       
       
    //pointers
    printf("\n\nString comparision with pointers result:\n");
    
    char *a, *b;
    a = s1;
    b = s2;
    
    while(*a == *b)
    {

        if ( *a == '\0' || *b == '\0' )
            break;

        a++;
        b++;

    }

    if( *a == '\0' && *b == '\0' )
        printf("Both the Strings Are Equal.");

    else
        printf("Both the Strings Are Not Equal.");

}