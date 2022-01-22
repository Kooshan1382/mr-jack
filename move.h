#include "map.h"

int possible_moves(char name[],char move[],struct tile** matrix,int x , int y){
    int xrecord,yrecord;
    for(int i=0;i<2+2;i++){
        for(int j=0;j<x+2;j++){
            if(strcmp(matrix[i][j].character,name)==0){
                yrecord=i;
                xrecord=j;
            }
        }
    }
    if(strcmp(name,"MS")==0){
        return 1;
    }
    if(x%2==1){
        if(strcmp(move,"N")==0){
          //if(matrix[i-1][j]!=)  
        }
    }
}
