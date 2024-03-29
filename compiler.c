#include <stdio.h>
#include "code.h"
#include "parser.h"

int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //  yyin = stdin
  if (yyparse() == 0) {
    if (root != NULL) {
      InstrList code = compileAll(root); //Compile the command list (root)
      printListIntrs(code);
      printMips(code); //Write mips instructions to code.asm file
	}
  }
  return 0;
}
