#ifndef SYMTABLE
#define SYMTABLE
// #include<iostream>
// template <class T>
struct SymTable_t;
typedef SymTable_t iNode;

// template <void>struct SymTable_t* x;
SymTable_t* SymTable_new ( );
void Print(SymTable_t *);
void SymTable_free (SymTable_t *);
int SymTable_getLength (SymTable_t *oSymTable);
int SymTable_put (SymTable_t *,const char *pcKey,const void *pvValue);
void *SymTable_replace (SymTable_t *,const char *pcKey,const void *pvValue);
int SymTable_contains (SymTable_t *,const char *pcKey);
void *SymTable_get (SymTable_t *, const char *pcKey);
void *SymTable_remove (SymTable_t *,const char *pcKey);
void SymTable_map (SymTable_t *,
                  void (*pfApply) (const char *pcKey,
                  const void *pvValue));
void display(const char *, const void *);
#endif
