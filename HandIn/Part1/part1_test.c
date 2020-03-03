#include <stdio.h>
#include <stdlib.h>
#include "part1.h"
int main() {
    setvbuf(stdout,NULL,_IONBF,0);//set the printing ro clear the buffer before program terminates
    setvbuf(stderr,NULL,_IONBF,0);
    FirstNode = (void*) malloc(1000);//malloc the first node
    initialise(FirstNode,1000);//initilise the linked list with one node
    void * a = allocate(0);
    a = allocate(NULL);
    a = allocate(100);
    deallocate(a);
    void * b = allocate(67);
    void * c = allocate(1);
    deallocate(b);
    //random
    a = allocate(20);
    b = allocate(3);
    deallocate(b);
    void * e = allocate(39);
    void * f = allocate(342);
    deallocate(f);
    void * g = allocate(394);
    deallocate(a);
    deallocate(c);
    void * h = allocate(23);
    deallocate(h);
    void * i = allocate(47);
    deallocate(g);
    void * j = allocate(239);
    deallocate(e);
    deallocate(i);
    void * k = allocate(103);
    void * l = allocate(29);
    deallocate(l);
    void * m = allocate(92);
    void * n = allocate(37);
    void * o = allocate(237);
    void * p = allocate(47);
    deallocate(j);
    deallocate(m);
    deallocate(n);
    deallocate(k);
    void * q = allocate(28);
    void * r = allocate(93);
    void * s = allocate(67);
    deallocate(r);
    deallocate(q);
    void * t = allocate(39);
    void * u = allocate(34);
    void * v = allocate(29);
    void * w = allocate(39);
    void * x = allocate(93);
    void * y = allocate(29);
    deallocate(o);
    deallocate(u);
    deallocate(p);
    deallocate(x);
    deallocate(v);
    void * z = allocate(100);
    deallocate(s);
    deallocate(t);
    deallocate(z);
    deallocate(w);
    deallocate(y);
    return 0;
}