#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//writing rules:
// function name -> camelCase
// varibel -> snake_case
// defined datatype -> PascalCase
// constant ALL CAPS

typedef struct
{
    int x_coord_table;
    int y_coord_table;
    int no_of_columns;
    int column_width;
}TableAttribute;

#define SIKUKANANATAS 187
#define SIKUKIRIATAS 201
#define SIKUKANANBAWAH 188
#define SIKUKIRIBAWAH 200
#define INTERSECTIONATAS 209
#define INTERSECTIONBAWAH 207
#define GARISTENGAH 179
#define GARISMENDATAR 205
#define GARISTEPI 186
#define INTERSECTIONDOUBLEGARISTENGAH 216
#define SIMPANGTIGAKIRI 204
#define SIMPANGTIGAKANAN 185
typedef char StringContent[255];


TableAttribute TABLE_ATTRIBUTE;

void goToXY(int x_coord, int y_coord)
{
  COORD pos = {x_coord, y_coord};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void tableHeader(StringContent header_contents[])
{
    int i,j,k,l;
    int x_coord_table = TABLE_ATTRIBUTE.x_coord_table;
    int y_coord_table = TABLE_ATTRIBUTE.y_coord_table;
    int column_width   = TABLE_ATTRIBUTE.column_width;
    int no_of_columns = TABLE_ATTRIBUTE.no_of_columns;

    int temp_lebar;
    for(i=0; i<3;i++)
    {
        goToXY(x_coord_table,y_coord_table+i);
        temp_lebar = no_of_columns;
        if(i==0 || i==2) //atas
        {   
            if(i==0)
            {
                printf("%c",SIKUKIRIATAS);

                while(temp_lebar>0)
                {
                    
                        for(j=0;j<=column_width;j++)
                        {
                            printf("%c",GARISMENDATAR);
                        }

                        if(temp_lebar==1)
                        {
                            printf("%c",SIKUKANANATAS);
                        }
                        else
                        {
                            printf("%c",INTERSECTIONATAS);
                        }
                    temp_lebar--;
                }
            }
            else
            {
                printf("%c",SIMPANGTIGAKIRI);

                while(temp_lebar>0)
                {
                    
                    for(j=0;j<=column_width;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }

                    if(temp_lebar==1)
                    {
                        printf("%c",SIMPANGTIGAKANAN);
                    }
                    else
                    {
                        printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
                    }
                    temp_lebar--;
                }
            } 
        }
        else //isi tengah
        { 
            printf("%c",GARISTEPI);
            int j;
            
            for(j=0 ;j <no_of_columns; j++)
            {
                l = strlen(header_contents[j]);
                printf(" %s",header_contents[j]);

                for(k=0; k<column_width-l;k++)
                {
                    printf(" ");
                }

                if(j==no_of_columns-1)
                {
                    printf("%c",GARISTEPI);
                }
                else
                {
                    printf("%c",GARISTENGAH);
                }

            }
        }
        printf("\n");
    }
}

void setTableAttribute(int x, int y, int column_width, int no_of_columns)
{
    TABLE_ATTRIBUTE.x_coord_table = x;
    TABLE_ATTRIBUTE.y_coord_table = y;
    TABLE_ATTRIBUTE.column_width  = column_width;
    TABLE_ATTRIBUTE.no_of_columns = no_of_columns;
}

void tableContent(int no_of_rows, StringContent row_contents[],int order_of_the_row)
{
    int i,j,l;
    StringContent temp_harga;
    int x_coord_table = TABLE_ATTRIBUTE.x_coord_table;
    int y_coord_table = TABLE_ATTRIBUTE.y_coord_table;
    int column_size   = TABLE_ATTRIBUTE.column_width;
    int no_of_columns = TABLE_ATTRIBUTE.no_of_columns;

    for(i=order_of_the_row;i<=order_of_the_row+1;i++) // membuat baris ( terdiri dari 2 ) baris pembatas dan baris konten tabel
    {
        //move to X, and Y + i - 2 + 5
        // i is the order of the row
        //+3 represent the how many line header take up
        goToXY(x_coord_table,y_coord_table+order_of_the_row+i+3);
        if(i==order_of_the_row) //Kolom  isi tabel konten
        {
            printf("%c",GARISTEPI);
            int cont_index;
            for(cont_index=0; cont_index<no_of_columns; cont_index++)
            {
                printf(" %s",row_contents[cont_index]);

                for(l=0 ; l<column_size-strlen(row_contents[cont_index]) ;l++)
                {
                    printf(" ");
                }
                if(cont_index!=no_of_columns-1)
                {
                    printf("%c",GARISTENGAH);
                }
            }
            printf("%c",GARISTEPI);
        }
        else if(order_of_the_row==no_of_rows-1)
        {
            printf("%c",SIKUKIRIBAWAH);
            
            int temp_lebar = no_of_columns;
            while(temp_lebar>0)
            {
                
                    for(j=0;j<=column_size;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }

                    if(temp_lebar==1)
                    {
                        printf("%c",SIKUKANANBAWAH);
                    }
                    else
                    {
                        printf("%c",INTERSECTIONBAWAH);
                    }
                temp_lebar--;
            }
            
        }
        else if(i==order_of_the_row+1) //* baris batas antar baris /
        {
            printf("%c",SIMPANGTIGAKIRI);
            int temp_lebar = no_of_columns;
            while(temp_lebar>0)
            {
                
                    for(j=0;j<=column_size;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }

                    if(temp_lebar==1)
                    {
                        printf("%c",SIMPANGTIGAKANAN);
                    }
                    else
                    {
                        printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
                    }
                temp_lebar--;
            }
        }
    }
    printf("\n");
    // } 
}
