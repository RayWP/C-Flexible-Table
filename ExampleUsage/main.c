#include <stdio.h>
#include "./flextable.c"

int main()
{
    StringContent header[3];
    StringContent isikonten[3];
    strcpy(header[0],"kol 1");
    strcpy(header[1],"kol 2");
    strcpy(header[2],"kol 3");
    system("cls");
    
    int k = 0;

    headerTabel(10,10,20,3,header);
    strcpy(isikonten[0],"isi 1");
    strcpy(isikonten[1],"isi 2");
    strcpy(isikonten[2],"isi 3");
    
    for(k=0; k<3; k++)
    {
        isiTabelMakanan(10,10,20,3,3,isikonten,k);
    }
    

    return 0;
}