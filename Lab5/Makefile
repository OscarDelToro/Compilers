build:
	lex grammar.l 
	yacc grammar.y -d
	gcc lex.yy.c y.tab.c -w -o grammar

run:
	./grammar