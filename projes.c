#include<stdio.h>
int main(){
    char message [100] , original[100];
    int shift , choice , i ;
    printf("choose an option :\n1.encode\n2.decode\n");
    scanf("%d",&choice);
    printf("enter the message(maximum 100 characters):\n ");
    getchar(); //to read the whole line
    scanf("%99[^\n]",message);
    do{
        printf("error:shift key (between 1 and 25):\n");
        scanf("%d",&shift);
        if(shift < 1 || shift > 25){
            printf("error: shift must be between 1 and 25: \n");
        } 
    }
    while (shift < 1 || shift > 25 );
    //save the original massage before changing it
    for (i = 0 ; message[i] != '\0';i++) 
    {
        original[i] = message[i];
    }
    original[i]= '\0';
    //processing(encode or decode)
    for (i=0;message[i] != '\0'; i++)
    {
        //for uppercase
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            if (choice == 1)
            //forward (sumbmission encryption)
            message[i] = (message[i]-'A'+ shift) % 26 + 'A';
            else
            //decryptio(rewind)
            message[i] = (message[i] - 'A' - shift + 26) % 26 +'A' ;  
        }
        //letters are small
        else if(message[i] >= 'a' && message[i] <= 'z'){
            if (choice == 1)
            //encryption
            message[i] = (message[i]-'a'+shift + 26)% 26 + 'a';
            else
            //decryptin
            message[i] = (message[i]-'a'-shift + 26) % 26 + 'a';
        }    
    }
    printf("\n original message: %s \n ",original);
    printf("shift key :%d\n",shift);
    if(choice == 1 )
    printf("encoded message: %s\n",message);
    else
    printf("decoded message: %s\n",message);
    return 0;
}