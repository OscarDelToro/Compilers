%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token I E P NL
%%
stmt: S NL {printf("Valid string\n"); 
            exit(0);}
;
S: I F
;
F: P I F | E
;
%%

int yyerror(char *msg){
    printf("invalid string\n");
    exit(1);
}
main(){
    printf("Enter the string \n");
    yyparse();
}