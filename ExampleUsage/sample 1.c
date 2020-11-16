#include <stdio.h>
#include "../flextable.c"

int main()
{
    StringContent header[3]; //table header
    StringContent isikonten[4][3]; //table content 4 row 3 column
    
    int row;
    system("cls");

    strcpy(header[0],"column 1");
    strcpy(header[1],"column 2");
    strcpy(header[2],"column 3");

    // create row 1
    strcpy(isikonten[0][0],"isi 7");
    strcpy(isikonten[0][1],"isi 2");
    strcpy(isikonten[0][2],"isi 3");

    // create row 2
    strcpy(isikonten[1][0],"isi 4");
    strcpy(isikonten[1][1],"isi 5");
    strcpy(isikonten[1][2],"isi 6");

    // create row 3
    strcpy(isikonten[2][0],"isi 1");
    strcpy(isikonten[2][1],"isi 9");
    strcpy(isikonten[2][2],"isi 10");

    // create row 4
    strcpy(isikonten[3][0],"isi 14");
    strcpy(isikonten[3][1],"isi 94");
    strcpy(isikonten[3][2],"isi 125");
    
    setTableAttribute(6,5,15,3);
    tableHeader(header);    
    for(row=0; row<3; row++)
    {
        //adding row
        tableContent(3,isikonten[row], row);
    }
    
    getch();
    return 0;
}