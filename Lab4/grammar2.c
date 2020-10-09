#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//FIXME

/***************************
Example:
Grammar:
E --> i E'
E' --> + i E' | e
***************************/

char l[1024];

int E(int);

int T(int);
int T1(int);//int
int T3(int);//(E)



void error(){
	printf("Error\n");
	exit(-1);
}

bool match(char t,int n) {
    if (l[n] == t) {
        
		return true;
    }
    else
		return false;
}


int E(int n){
    int a=T(n);
    if (a==0)
        return 0;
    else if(match('+',a)){
        return E(a+1);
    }
    return a;
}

int T1(int n){
    return match('i',n)&&match('n',n+1)&&match('t',n+2) ? n+3 : 0;
}

int T3(int n){
    int a=E(n+1);
    return match('(',n)&&match(')',a)&&a!=0 ? a+1 : 0;
}
int T(int n){
    int a=T1(n);
    if(a){
        if(match('*',a)){
            return T(a+1);
        }
        return a;
    }
    else{
        return T3(n);
    }
    return 0;
}

int main() {
    scanf ("%s",l);

    if(E(0)){
        printf("Parsing Succesful\n");
    }
    else{
        error();
    }
}