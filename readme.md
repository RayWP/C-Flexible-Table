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

## Feature:
### Datatype:
```c
typedef char StringContent[255];
typedef struct
{
    int x_coord_table;
    int y_coord_table;
    int no_of_columns;
    int column_width;
}TableAttribute;
```
Use StringContent / StringContent[] to pass your data to the table. Example is shown in ExampleUsage
TableAttribute is only used as constant datatype to set the table attribute shown above

### Constant/Default variable:
```c
TableAttribute TABLE_ATTRIBUTE;
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
```
all the define, is using extended 255-bit ascii to make the table border
TABLE_ATTRIBUTE is used for setting the table attribute, please modify it using setTableAttribute();

### Method:
```c
void tableHeader(int column_width,int no_of_columns, StringContent header_contents[]);
void tableContent(int column_size,int no_of_columns,int no_of_rows, StringContent row_contents[],int order_of_the_row);
void setTableAttribute(int x, int y, int column_width, int no_of_columns)
```

```c
// headerTabel is for generating the header of the table, meanwhile the kontenTabel is for generating a single row. So you need to do the for loops yourself (I will try to improve this to ease you guys). Example is shown in ExampleUsage
// Attribute meaning:
// x_coord, y_coord      --> is the coordinate where you want the table it.  
// column_width          --> is the column width, make sure your data is not larger than the column width.  
// number_of_columns     --> is how many column do you want.  
// number_of_rows        --> is how many rows do you plan to generate.  
// row_number            --> is the current order of the row you want to generate (please look in ExampleUsage for more information).  
// header_content[]      --> is an array of StringContent, containing the name of your column. Make sure the size of the array is the same with number of columns.  
// rows_content[]        --> is an array of StringContent, containing the the content of your rows. Make sure the size of the array is the same with number of columns.  

//setXYCoord to set the x and y coordinate of the table, please call this before generating table
// For more information please look in the ExampleUsage
```