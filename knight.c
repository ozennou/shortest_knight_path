#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//In this case I use linked lists

typedef struct {
    int x, y, dist;
} node;

typedef struct cell{
    node val;
    struct cell *next;
} cell;

node *convert(char* a){
    node *c=(node*)malloc(sizeof(node));
    c->x=a[0]-97;
    c->y=a[1]-49;
    return c;
}

cell *create(node *p){
    cell* c;
    c=(cell*)malloc(sizeof(cell));
    c->val.x=p->x;
    c->val.y=p->y;
    c->val.dist=p->dist;
    c->next=NULL;
    return c;
}

cell *push(cell *c,cell *list){
   if(c==NULL){ c=list;} 
   else{ cell *p=c;
   while(p->next!=NULL){ p=p->next;}
   p->next=list;}
   return c;
}

cell *pop(cell *c,node* x){
    cell *l=NULL; (*x)=c->val; l=c; c=c->next; free(l); return c;
}

int longeur(cell *c){
    cell *p=c;
    int i=0;
    while(p!=NULL){ i++; p=p->next;}
    return i;
}

int valid(int x,int y){
    if(x<8 && x>=0 && y<8 && y>=0){
        return 1;
    }
    return 0;
}

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, 2, -2};

short knight(const char *p1, const char *p2){
    node* c1=convert(p1);
    node* c2=convert(p2);
    node m;
    node n;
    int visited[8][8]={{0}};
    c1->dist=0;
    cell* p=create(c1);
    while(longeur(p)!=0){
        p=pop(p,&m);
        int x=m.x;
        int y=m.y;
        int d=m.dist;
        if(x==c2->x && y==c2->y){
            return d;
        }
        if(visited[x][y]!=1){
            visited[x][y]=1;
            for(int i=0;i<8;i++){
                int x0=x+row[i];
                int y0=y+col[i];
                if(valid(x0,y0)==1){
                    n.x=x0;
                    n.y=y0;
                    n.dist=d+1;
                    cell *j=create(&n);
                    p=push(p,j);
                }
            }
        }
    }
    return INT_MAX;
}
