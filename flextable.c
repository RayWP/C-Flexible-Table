#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//writing rules:
// function name -> camelCase
// varibel -> snake_case
// defined datatype -> PascalCase
// constant ALL CAPS

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

void goToXY(int x_coord, int y_coord)
{
  COORD pos = {x_coord, y_coord};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void headerTabel(int x_coord,int y_coord,int column_width,int number_of_columns, StringContent header_content[])
{
  int i,j,k,l;
  int panjang_string=0;
  int temp_lebar;
  for(i=0; i<3;i++)
  {
    goToXY(x_coord,y_coord+i);
    temp_lebar = number_of_columns;
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
      
      for(j=0 ;j <number_of_columns; j++)
      {
         l = strlen(header_content[j]);
        printf(" %s",header_content[j]);
        for(k=0; k<column_width-l;k++)
        {
          printf(" ");
        }
        if(j==number_of_columns-1)
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


void kontenTabel(int x_coord,int y_coord,int column_size,int number_of_columns,int number_of_rows, StringContent rows_content[],int row_number)
{
    int i,j,l;
    y_coord += 5;
    for(i=row_number;i<=row_number+1;i++) // membuat baris ( terdiri dari 2 ) baris pembatas dan baris konten tabel
    {
        goToXY(x_coord,y_coord+row_number+i-2);
        if(i==row_number) //Kolom  isi tabel konten
        {
            printf("%c",GARISTEPI);
            int cont_index;
            for(cont_index=0; cont_index<number_of_columns; cont_index++)
            {
                printf(" %s",rows_content[cont_index]);

                for(l=0 ; l<column_size-strlen(rows_content[cont_index]) ;l++)
                {
                    printf(" ");
                }
                if(cont_index!=number_of_columns-1)
                {
                    printf("%c",GARISTENGAH);
                }
            }
            printf("%c",GARISTEPI);
        }
        else if(row_number==number_of_rows-1)
        {
            printf("%c",SIKUKIRIBAWAH);
            int temp_lebar = number_of_columns;
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
        else if(i==row_number+1) //* baris batas antar baris /
        {
            printf("%c",SIMPANGTIGAKIRI);
            int temp_lebar = number_of_columns;
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
}