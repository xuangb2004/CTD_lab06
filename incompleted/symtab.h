/* symtab.h */
#ifndef __SYMTAB_H__
#define __SYMTAB_H__

#include "token.h"

// --- 1. Forward Declarations ---
struct Object_;
struct ObjectNode_;
struct Scope_;
struct Type_;

// --- 2. Typedefs ---
typedef struct Object_ Object;
typedef struct ObjectNode_ ObjectNode;
typedef struct Scope_ Scope;
typedef struct Type_ Type;

// --- 3. Enums ---
typedef enum {
  OBJ_CONSTANT, OBJ_VARIABLE, OBJ_TYPE, OBJ_FUNCTION, OBJ_PROCEDURE, OBJ_PARAMETER, OBJ_PROGRAM
} ObjectKind;

typedef enum {
  PARAM_VALUE, PARAM_REFERENCE
} ParamKind;

typedef enum {
  TP_INT, TP_CHAR, TP_ARRAY
} TypeClass;

// --- 4. Structs ---
struct Type_ {
  TypeClass typeClass;
  int arraySize;
  struct Type_ *elementType;
};

typedef struct {
  TypeClass type;
  int intValue;
  char charValue;
} ConstantValue;

typedef struct { ConstantValue* value; } ConstantAttributes;
typedef struct { struct Type_* actualType; } TypeAttributes;
typedef struct { struct Type_* type; struct Scope_* scope; int localOffset; } VariableAttributes;

typedef struct {
  ParamKind kind; // [SỬA LỖI] Bỏ từ khóa 'enum' ở đây
  struct Type_* type;
  struct Scope_* scope;
  int localOffset;
} ParameterAttributes;

typedef struct { struct Scope_* scope; int codeAddress; } ProgramAttributes;

typedef struct {
  struct Type_* returnType;
  ObjectNode* paramList;
  int paramCount;
  struct Scope_* scope;
  int codeAddress;
} FunctionAttributes;

typedef struct {
  ObjectNode* paramList;
  int paramCount;
  struct Scope_* scope;
  int codeAddress;
} ProcedureAttributes;

struct Object_ {
  char name[MAX_IDENT_LEN];
  ObjectKind kind;
  union {
    ConstantAttributes* constAttrs;
    VariableAttributes* varAttrs;
    TypeAttributes* typeAttrs;
    FunctionAttributes* funcAttrs;
    ProcedureAttributes* procAttrs;
    ProgramAttributes* progAttrs;
    ParameterAttributes* paramAttrs;
  };
};

struct ObjectNode_ {
  Object *object;
  struct ObjectNode_ *next;
};

struct Scope_ {
  ObjectNode *objList;
  Object *owner;
  struct Scope_ *outer;
  int frameSize;
  int level;
};

typedef struct {
  Object *program;
  Scope *currentScope;
  ObjectNode *globalObjectList;
} SymTab;

// --- Macros ---
#define RESERVED_WORDS 4
#define PROCEDURE_SCOPE(obj) (obj->procAttrs->scope)
#define FUNCTION_SCOPE(obj) (obj->funcAttrs->scope)

// --- Prototypes ---
Type* makeIntType(void);
Type* makeCharType(void);
Type* makeArrayType(int arraySize, Type* elementType);
Type* duplicateType(Type* type);
int compareType(Type* type1, Type* type2);
void freeType(Type* type);
int sizeOfType(Type* type);

ConstantValue* makeIntConstant(int i);
ConstantValue* makeCharConstant(char ch);
ConstantValue* duplicateConstantValue(ConstantValue* v);

Scope* createScope(Object* owner, Scope* outer);

Object* createProgramObject(char *programName);
Object* createConstantObject(char *name);
Object* createTypeObject(char *name);
Object* createVariableObject(char *name);
Object* createFunctionObject(char *name);
Object* createProcedureObject(char *name);

// [SỬA LỖI] Bỏ từ khóa 'enum' ở đây
Object* createParameterObject(char *name, ParamKind kind);

Object* findObject(ObjectNode *objList, char *name);
Object* lookupObject(char *name);

void initSymTab(void);
void cleanSymTab(void);
void enterBlock(Scope* scope);
void exitBlock(void);
void declareObject(Object* obj);
void addObject(ObjectNode **objList, Object* obj);

#endif