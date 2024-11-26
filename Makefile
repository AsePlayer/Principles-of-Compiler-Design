
parser.tab.c parser.tab.h: parser.y
	bison -t -v -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser:  clearOutputs lex.yy.c parser.tab.c parser.tab.h
	gcc -o parser parser.tab.c lex.yy.c
	./parser test.txt

clean:
	rm -f parser lexer parser.tab.c lex.yy.c parser.tab.h parser.output MIPScode.asm
	clear
	ls -l

clearOutputs:
	echo "" > MIPScode.asm
	echo "" > IRcode.ir