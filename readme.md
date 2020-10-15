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

### Feature:
#### Datatype
```c
typedef StringContent char[255];
```
Use StringContent / StringContent[] to pass your data to the table. Example is shown in ExampleUsage

#### Method:
```c
headerTabel(int x_coord,int y_coord,int column_width,int number_of_columns, StringContent header_content[])
kontenTabel(int x_coord,int y_coord,int column_size,int number_of_columns,int number_of_rows, StringContent rows_content[],int row_number);
```
headerTabel is for generating the header of the table, meanwhile the kontenTabel is for generating a single row. So you need to do the for loops yourself (I will try to improve this to ease you guys). Example is shown in ExampleUsage
Attribute meaning:
x_coord, y_coord      --> is the coordinate where you want the table it
column_width          --> is the column width, make sure your data is not larger than the column width
number_of_columns     --> is how many column do you want.
number_of_rows        --> is how many rows do you plan to generate
row_number            --> is the current order of the row you want to generate (please look in ExampleUsage for more information)
header_content[]      --> is an array of StringContent, containing the name of your column. Make sure the size of the array is the same with number of columns
rows_content[]        --> is an array of StringContent, containing the the content of your rows. Make sure the size of the array is the same with number of columns

For more information please look in the ExampleUsage