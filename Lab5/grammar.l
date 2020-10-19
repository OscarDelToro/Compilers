%{ 
   /* Definition section */
  #include "y.tab.h" 

%}
/* Rule Section */

%%
[iI] {return I;} 
[eE] {return E;}
"+" {return P;}  
\n {return NL;} 
.  {return yytext[0];} 
%% 
  
int yywrap()  
 {  
  return 1;  
 } 
