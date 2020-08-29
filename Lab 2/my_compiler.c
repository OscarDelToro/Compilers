#include<stdio.h>
#include <stdbool.h>
int main(int argc, char **argv){
    int c,
        parentheses=0,
        brackets=0,
        braces=0,
        sinQuote=0,
        doubQuote=0,
        comment=0,
        last=0;
    bool inLineComment=0,
        inComment=0;
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL){
        printf("Error opening file!\n");
        return -1;
    }
    while ((c = fgetc(fp)) != EOF){
        if(inComment){
            if(c==47&&last==42){
                comment--;
                inComment=false;
            }
        }
        else if(inLineComment){
            if(c==10)
                inLineComment=false;
        }
        else{
            if (c==40)
                parentheses++;
            else if(c==41)
                parentheses--;
            else if(c==91)
                braces++;
            else if(c==93)
                braces--;
            else if(c==123)
                brackets++;
            else if(c==125)
                brackets--;
            else if(c==39)
                sinQuote++;
            else if(c==34)
                doubQuote++;
            else if(c==42&&last==47){
                comment++;
                inComment=true;
            }
            else if(c==47&&last==42)
                comment--;
            else if(c==47&&last==47)
                inLineComment=true;
        }
        last=c;
    }
    fclose(fp);
    if(parentheses==0&&
        brackets==0&&
        braces==0&&
        sinQuote%2==0&&
        doubQuote%2==0&&
        comment==0){
            printf("There are no errors\n");
        }
    else{
        while(parentheses!=0){
            if(parentheses>0){
                printf("There is a missing )\n");
                parentheses--;
            }
            else{
                printf("There is a missing (\n");
                parentheses++;
            }
        }
        while(brackets!=0){
            if(brackets>0){
                printf("There is a missing }\n");
                brackets--;
            }
            else{
                printf("There is a missing {\n");
                brackets++;
            }
        }
        while(braces!=0){
            if(braces>0){
                printf("There is a missing ]\n");
                braces--;
            }
            else{
                printf("There is a missing [\n");
                braces++;
            }
        }
        while(comment!=0){
            if(comment>0){
                printf("There is a missing */ WARNING: part of the code may have not been analyzed because of this error\n");
                comment--;
            }
            else{
                printf("There is a missing /*\n");
                comment++;
            }
        }
        if(sinQuote%2!=0)
            printf("There is a missing '\n");
        
        if(doubQuote%2!=0)
            printf("There is a missing %c\n",34);
    }
    return 0;
}