#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#define N 1000

struct Tree {
    short type;
    struct Tree *next;
};

struct Prim {
    short type;
    char* op;

    struct Tree *left;
    struct Tree *right;
};

struct Lit {
    short type;
    int val;
};

struct Let {
    short type;
    char* id;

    struct Prim *val;
};

struct Ref {
    short type;
    char* id;
};

struct If {
    short type;
    struct Prim *cond;
    struct Body *body;
};

struct Env {
    struct Tree *prog[N]; // 0-indexed array representing each line of the program.
    int lines; // 1-indexed amount of lines in the program
};

struct Env *new_env();
struct Prim *new_prim(char* op, struct Tree *left, struct Tree *right);
struct Lit *new_lit(int val);
struct Let *new_let(char* id, struct Prim *val);
struct Ref *new_ref(char* id);
struct If *new_if(struct Prim *cond, struct Env *env);

char * prim_to_string(struct Prim *tree);
char * lit_to_string(struct Lit *lit);
char * let_to_string(struct Let *dec);
char * ref_to_string(struct Ref *ref);
char * tree_to_string(struct Tree *tree);
char * if_to_string(struct If *ifs);
char * env_to_string(struct Env *env);
