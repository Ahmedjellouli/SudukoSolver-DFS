#include<windows.h>
#include<cstdio>
#include <stdlib.h>

#include <string>
#include <iostream>

#include <sstream>

using namespace std;


int Square[9] ;
int Xline[9];
int Yline[9];
int Possibilities[9];
int suduko[9][9] ={
        {0,5,0,    9,0,0,    7,2,0},
        {9,2,6,    1,7,0,    3,0,0},
        {0,0,3,    6,5,2,    0,0,0},

        {5,6,8,    0,0,0,    0,1,3},
        {1,9,7,    0,0,6,    0,0,4},
        {3,0,0,    5,0,9,    6,0,7},

        {0,0,0,    4,0,7,    0,0,0},
        {0,0,4,    8,0,0,    0,0,0},
        {6,0,0,    2,3,1,    0,0,0}
};
//int suduko[9][9] ={
//        {8,5,0,    9,0,0,    7,2,0},
//        {9,2,6,    1,7,0,    3,0,0},
//        {0,0,3,    6,5,2,    0,0,0},
//
//        {5,6,8,    0,0,0,    0,1,3},
//        {1,9,7,    0,0,6,    0,0,4},
//        {3,0,0,    5,0,9,    6,0,7},
//
//        {0,0,0,    4,0,7,    0,0,0},
//        {0,0,4,    8,0,0,    0,0,0},
//        {9,0,0,    2,3,1,    0,0,0}
//};


void PrintArray( const int *Array,int m, int n){
//    printf("%d",Array);
    int i, j;
    for (i = 0; i < m; i++){
//        printf("\n");
        if ( i % 3 ==0  )    printf(" \n");
        for (j = 0; j < n; j++){
            if ( j % 3 ==0 )    printf(" ");
            printf(" %d", *((Array+i*n) + j));

        }
        printf("\n");} }
void SavePossibilities(char *file){
    int j;
    FILE *fptr;
    fptr = fopen(file, "a");
    fprintf(fptr,"%c","");
    fclose(fptr);
    char *Mode  = "w";



        for (j = 0; j < 8; j++){
            if (Possibilities[j] == 0)continue;
//            PrintArray((int *) Possibilities,1,9);


            fptr = fopen(file, Mode);
            fprintf(fptr,"%d",Possibilities[j]);
            fclose(fptr);
            Mode  ="a";
        } }
void getSquare(int row, int col){
    int m=0;
    int n=0;
    int row2 =0;
    if (row <=2 )            {m =0 ;}
    if (row >= 3 && row <=5 ){m =3 ;}
    if (row >= 6 && row <=8 ){m =6 ;}
    if (col <=2 )            {n =0 ;}
    if (col >= 3 && col <=5 ){n =3 ;}
    if (col >= 6 && col <=8 ){n =6 ;}
    for (int   row1 = m ; row1 <= m+2 ; row1++){
        for (int   col1 = n ; col1 <= n+2 ; col1++){
            Square[row2] = suduko[row1][col1];
            row2++;
}}}
void getXline(int Row){
    for (int i  = 0 ; i<=8; i++){
        Xline[i]=suduko[Row][i];}}
void getYline(int Col){
    for (int i  = 0 ; i<=8; i++){
        Yline[i]=suduko[i][Col];}}
int getPossibilities(int row, int col){
    getSquare( row,  col);
    getXline(row);
    getYline(col);
    int m,n = 0;
    for (int i = 0; i<=8; i++)Possibilities[i] = 0;
    for (int i = 1; i<=9; i++){
        for ( m = 0; m<=8; m++){
           if  (Square[m] ==i) break;
           if  (Xline [m] ==i) break;
           if  (Yline [m] ==i) break;}
           if (m>8){Possibilities[n]=i;n++; }

    }


    return 1;
}

void SaveAllPossibilites(){
    for (int row = 0; row<=8; row++ ){
        for (int col = 0; col<=8; col++  ){
            if (suduko[row][col]  != 0) continue;
            char NumChar[] = "0123456789";

            char a[] = "data\\RC.txt";
            a[5] =NumChar[row];
            a[6] = NumChar[col];
            char  *file = a;
            FILE *fptr;
            fptr = fopen(file, "w");
            fprintf(fptr,"%c","");
            fclose(fptr);

//            printf("%d", row);
//            printf(", %d\n", col);

            getPossibilities(row,col  );
            SavePossibilities( file);
//           printf("%d\n",  Possibilities[0]);
//           printf("%d%d\n",row,col);
//           PrintArray((int *) Possibilities,1,9);
        }}
}
int str2int(char StrNum){
    int Num  = 0;
    if (StrNum == '0') Num = 0;
    if (StrNum == '1') Num = 1;
    if (StrNum == '2') Num = 2;
    if (StrNum == '3') Num = 3;
    if (StrNum == '4') Num = 4;
    if (StrNum == '5') Num = 5;
    if (StrNum == '6') Num = 6;
    if (StrNum == '7') Num = 7;
    if (StrNum == '8') Num = 8;
    if (StrNum == '9') Num = 9;
    return Num;
}

int readNum(int order ,int row, int col ){
    FILE *fptr ;
    char str  ;
    char NumChar[] = "0123456789";
    char a[] = "data\\RC.txt";
    a[5] =NumChar[row];
    a[6] = NumChar[col];
    char  *file = a;
    fptr = fopen(file,"r");
    fseek(fptr , order, SEEK_SET);
    str = char(fgetc(fptr));
    int Num = str2int(str) ;
//    printf("%d",Num);
    fclose(fptr);
    return Num;
}
int main() {
 SaveAllPossibilites();

    int rowQ[81] ;
    int colQ[81] ;
    int order[9][9] = {0};
    int iq = 0;
    bool isRowZero, isColZero = false;
    for (int row = 0; row<=8; row++ ){

        for (int col = 0; col<=8; col++  ){
            if (isColZero) {col = 0; isColZero = false;}
            if (isRowZero) {row = 0; isRowZero = false;}

            if (suduko[row][col]  != 0) continue;

            SaveAllPossibilites();    //save possibilities in each grid
            int num   = readNum(  order[row][col] , row,col);// read one of the possibilies (choice the adjacent unmarked node)
            order[row][col] ++; // mark this possibilities (node)
            printf(" row = %d  row = %d num = %d order = %d  \n",row,col, num, order[row][col]);


           if (num == 0){ // no possibilities in this grid using this path (no unmarked adjacent node)

                order[row][col] = 0; //ila makanch possibilité init l'ordre
                iq--;
//                printf("RowQ");
//                PrintArray((int *) rowQ,1,iq+1);
//                printf("colQ");
//                PrintArray((int *) colQ,1,iq+1);
//                printf("rowQ = %d  colQ = %d\n",rowQ[iq],colQ[iq]);



                row = rowQ[iq]-1  ; // backtrack and check for other unmarked nodes and traverse them
                col = colQ[iq]-1 ;
                if (col == -1 ) isColZero= true;
                if (row == -1 ) isRowZero= true;
                suduko[rowQ[iq]][colQ[iq]]  = 0;
//                cout << "Press Enter to continue" << endl;
//                cin.get();
                continue;
            }
//            printf("rowQ = %d  colQ1 = %d\n",rowQ[iq],colQ[iq]);

            rowQ[iq]  = row;
            colQ[iq]  = col;
            iq++;
            suduko[row][col]  = num;


            PrintArray(  (int *) suduko,9, 9);

//            cout << "Press Enter to continue" << endl;
//            cin.get();



    }}

}

