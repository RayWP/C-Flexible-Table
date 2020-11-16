#include <stdio.h>
#include "../flextable.c"

int main()
{
    StringContent header[3]; //table header
    StringContent isikonten[3]; //table content row
    int k;
    system("cls");

    strcpy(header[0],"kol 1");
    strcpy(header[1],"kol 2");
    strcpy(header[2],"kol 3");
    
    strcpy(isikonten[0],"isi 2");
    strcpy(isikonten[1],"isi 2");
    strcpy(isikonten[2],"isi 3");

    //creating header
    headerTabel(20,3,header);    
    for(k=0; k<3; k++)
    {
        //adding row
        kontenTabel(20,3,3,isikonten,k);
    }

    getch();
    return 0;
}