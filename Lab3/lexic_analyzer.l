%{
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <sys/types.h>
int fileDescriptor;
void openfile();
void writeToFile(char *str);

%}

eol 	\n

intdcl   i
floatdcl f
print    p
id    [a-e|g-h|j-o|q-z]
inum  [0-9]+
fnum  {inum}.{inum}
comment ("//".*\n)



%%
{eol} 	{writeToFile("\n");}
{intdcl} 	{writeToFile("intdcl ");}
{floatdcl} 	{writeToFile("floatdcl ");}
{print} {writeToFile("print ");}
{id} {writeToFile("id ");}
{inum} {writeToFile("inum ");}
{fnum} {writeToFile("fnum ");}
{comment} {writeToFile("");}
"+" {writeToFile("plus ");}
"*" {writeToFile("times ");}
"-" {writeToFile("minus ");}
"/" {writeToFile("divided_by ");}
"=" {writeToFile("assign ");}

%%

int main(int argc, char **argv){
    FILE    *fd;
    if (argc == 2)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("\033[93mError: Could not open the source file.\033[0m\n");
            return (-1);
        }
        openfile();
        yyset_in(fd);
        yylex();
        fclose(fd);
        close(fileDescriptor);
    }
    else
        printf("Usage: lexical_scan  sourcefile\n");
    printf("\033[92mAnalyzer has finished. Saved at \033[95mlex.out\033[0m\n");
	return 0;
}
 void openfile(){
    fileDescriptor = open("lex.out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fileDescriptor < 0) {
        printf("\033[93mCould not open the .out file\033[0m\n"); 
        exit(1);
    }
} 
void writeToFile(char *str){
    printf("%s",str);
    write(fileDescriptor,str,strlen(str));
}