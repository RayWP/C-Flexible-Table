#include <stdio.h>
#include "../flextable.c"

int main()
{
    StringContent header[3]; //table header
    StringContent isikonten[2][2]; //table content row
    
    int k;
    system("cls");

    strcpy(header[0],"1234567890");
    strcpy(header[1],"kol 2");
    strcpy(header[2],"kol 3");

    printf("hello world\n");
    strcpy(isikonten[0][0],"isi 7");
    strcpy(isikonten[0][1],"isi 2");
    // strcpy(isikonten[0][2],"isi 3");
    printf("hello world\n");
    strcpy(isikonten[1][0],"isi 4");
    strcpy(isikonten[1][1],"isi 5");
    // strcpy(isikonten[1][2],"isi 6");
    printf("hello world\n");
    // StringContent SC = (isikonten+2);
    printf("hello world\n");
    printf("ini 1: %s\n",(*(isikonten+1))); //isi 2
    printf("size: %d", sizeof(isikonten)/sizeof(StringContent));
    // printf("ini 2: %s",*(*SC+1)+1); //isi 5
    
    // setTableAttribute(6,5,10,3);
    //creating header
    // tableHeader(header);    
    // for(k=0; k<3; k++)
    // {
    //     //adding row
    //     tableContent(3,isikonten,k);
    // }

    getch();
    return 0;
}