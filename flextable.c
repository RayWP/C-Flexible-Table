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

int x_coord_table = 1;
int y_coord_table = 1;


void goToXY(int x_coord, int y_coord)
{
  COORD pos = {x_coord, y_coord};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void headerTabel(int x_coord_table,int y_coord_table,int lebar_kolom,int jumlah_kolom, StringContent isi_header[])
{
  int i,j,k,l;
  int panjang_string=0;
  StringContent temp;
  va_list arg;
  int temp_lebar;
  for(i=0; i<3;i++)
  {
    goToXY(x_coord_table,y_coord_table+i);
    temp_lebar = jumlah_kolom;
    if(i==0 || i==2) //atas
    {   
      if(i==0)
      {
            printf("%c",SIKUKIRIATAS);

            while(temp_lebar>0)
            {
                
                    for(j=0;j<=lebar_kolom;j++)
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
                
                    for(j=0;j<=lebar_kolom;j++)
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
      
      for(j=0 ;j <jumlah_kolom; j++)
      {
         l = strlen(isi_header[j]);
        printf(" %s",isi_header[j]);
        for(k=0; k<lebar_kolom-l;k++)
        {
          printf(" ");
        }
        if(j==jumlah_kolom-1)
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

void setXYCoord(int x, int y)
{
    x_coord_table = x;
    y_coord_table = y;
}

void kontenTabel(int x_coord_table,int y_coord_table,int column_size,int jumlah_kolom,int jumlah_menu, StringContent isi_baris[],int urutan_baris)
{
    int i,j,l;
    y_coord_table += 5;
    StringContent temp_harga;
    // for(k=1;k<jumlahMenu;k++) // mengulang sebanyak jumlah menu
    // {
        for(i=urutan_baris;i<=urutan_baris+1;i++) // membuat baris ( terdiri dari 2 ) baris pembatas dan baris konten tabel
        {
        	goToXY(x_coord_table,y_coord_table+urutan_baris+i-2);
            if(i==urutan_baris) //Kolom  isi tabel konten
            {
                printf("%c",GARISTEPI);
                int cont_index;
                for(cont_index=0; cont_index<jumlah_kolom; cont_index++)
                {
                    printf(" %s",isi_baris[cont_index]);

                    for(l=0 ; l<column_size-strlen(isi_baris[cont_index]) ;l++)
                    {
                        printf(" ");
                    }
                    if(cont_index!=jumlah_kolom-1)
                    {
                        printf("%c",GARISTENGAH);
                    }
                }
                printf("%c",GARISTEPI);
            }
            else if(urutan_baris==jumlah_menu-1)
			{
				printf("%c",SIKUKIRIBAWAH);
                
				int temp_lebar = jumlah_kolom;
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
            else if(i==urutan_baris+1) //* baris batas antar baris /
            {
            	printf("%c",SIMPANGTIGAKIRI);
				int temp_lebar = jumlah_kolom;
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