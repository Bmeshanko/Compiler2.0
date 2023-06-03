#include <stdlib.h>
#include <stdio.h>
#include <map>

typedef std::map<char *, int> mci;

void eval(struct Env *prog, int start, int end, mci &variables);
int findEnd(struct Env *prog, int start);
void evalLet(struct Let *let, mci &variables);
bool evalCond(struct Tree *tree, int type, mci &variables);
int evalNum(struct Tree *tree, mci &variables);