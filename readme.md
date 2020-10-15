# C-FLEXIBLE-TABLE
ID:
Tabel fleksible sederhana untuk bahasa C, yang biasa ditampilan di cmd. 

EN:
Flexible simple table for C program that run in cmd.

## Description:
flextable.c contains method to create a table header and table rows. 
The method is capable of generating the table to certain position(x,y).

## How to add to project:
1. Download flextable.c
2. Put it in the same location with your header.h or main.c
3. Don't forget to include it in your header.h or main.c like this:
```c
#include "./flextable.c"
```

### Method:
```c
headerTabel(int x_coord,int y_coord,int lebar_kolom,int jumlah_kolom, StringContent isi_header[])
isiTabelMakanan(int x_coord,int y_coord,int column_size,int jumlah_kolom,int jumlah_menu, StringContent isi_baris[],int urutan_baris)
```