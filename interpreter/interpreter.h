#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "parser.h"

typedef struct {
    struct EnvEntry* entries;
} Environment;

typedef struct EnvEntry {
    char* name;
    Token value;
    struct EnvEntry* next;
} EnvEntry;

void initEnvironment(Environment* env);
void defineVariable(Environment* env, char* name, Token value);
Token getVariable(Environment* env, char* name);

typedef struct {
    Environment* environment;
} Interpreter;

void initInterpreter(Interpreter* interpreter, Environment* env);
void interpret(Interpreter* interpreter, Expr* expression);

#endif
