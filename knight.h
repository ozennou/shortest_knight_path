typedef struct {
    int x, y, dist;
} node;

typedef struct cell{
    node val;
    struct cell *next;
} cell;

node *convert(char*);
cell *create(node*);
cell *push(cell*,cell*);
cell *pop(cell*,node*);
int lenght(cell*);
int valid(int,int);
int knight(const char*,const char*);