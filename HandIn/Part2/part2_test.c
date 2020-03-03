#include <stdio.h>
#include <stdlib.h>
#include "part2.h"
int main() {
    setvbuf(stdout,NULL,_IONBF,0);//set the printing ro clear the buffer before program terminates
    setvbuf(stderr,NULL,_IONBF,0);
    void *mem = (void*) malloc(5000);//malloc the first node
    initialise(mem,1000,"First");//initilise the linked list with one node
    void * a = allocate(10);
    void * b = allocate(20);
    deallocate(a);
    void * c = allocate(30);
    //random
    deallocate(b);
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
    initialise(mem+1000,1000,"Next");//initilise the linked list with one node
    a = allocate(200);
    b = allocate(100);
    deallocate(a);
    c = allocate(500);
    deallocate(c);
    //random
    deallocate(b);
    a = allocate(20);
    b = allocate(3);
    deallocate(b);
    e = allocate(39);
    f = allocate(342);
    deallocate(f);
    g = allocate(394);
    deallocate(a);
    deallocate(c);
    h = allocate(23);
    deallocate(h);
    i = allocate(47);
    deallocate(g);
    j = allocate(239);
    deallocate(e);
    deallocate(i);
    k = allocate(103);
    l = allocate(29);
    deallocate(l);
    m = allocate(92);
    n = allocate(37);
    o = allocate(237);
    p = allocate(47);
    deallocate(j);
    deallocate(m);
    deallocate(n);
    deallocate(k);
    q = allocate(28);
    r = allocate(93);
    s = allocate(67);
    deallocate(r);
    deallocate(q);
    t = allocate(39);
    u = allocate(34);
    v = allocate(29);
    w = allocate(39);
    x = allocate(93);
    y = allocate(29);
    deallocate(o);
    deallocate(u);
    deallocate(p);
    deallocate(x);
    deallocate(v);
    z = allocate(100);
    deallocate(s);
    deallocate(t);
    deallocate(z);
    deallocate(w);
    deallocate(y);
    initialise(mem+2000,1000,"Best");//initilise the linked list with one node
    a = allocate(200);
    b = allocate(300);
    c = allocate(200);
    void *d = allocate(100);
    deallocate(b);
    deallocate(d);
    b = allocate(100);
    //random
    deallocate(b);
    b = allocate(3);
    deallocate(b);
    e = allocate(39);
    f = allocate(342);
    deallocate(f);
    g = allocate(394);
    deallocate(a);
    deallocate(c);
    h = allocate(23);
    deallocate(h);
    i = allocate(47);
    deallocate(g);
    j = allocate(239);
    deallocate(e);
    deallocate(i);
    k = allocate(103);
    l = allocate(29);
    deallocate(l);
    m = allocate(92);
    n = allocate(37);
    o = allocate(237);
    p = allocate(47);
    deallocate(j);
    deallocate(m);
    deallocate(n);
    deallocate(k);
    q = allocate(28);
    r = allocate(93);
    s = allocate(67);
    deallocate(r);
    deallocate(q);
    t = allocate(39);
    u = allocate(34);
    v = allocate(29);
    w = allocate(39);
    x = allocate(93);
    y = allocate(29);
    deallocate(o);
    deallocate(u);
    deallocate(p);
    deallocate(x);
    deallocate(v);
    z = allocate(100);
    deallocate(s);
    deallocate(t);
    deallocate(z);
    deallocate(w);
    deallocate(y);
    initialise(mem+3000,1000,"Worst");//initilise the linked list with one node
    a = allocate(200);
    b = allocate(300);
    c = allocate(200);
    d = allocate(100);
    deallocate(b);
    deallocate(d);
    b = allocate(100);
    //random
    deallocate(b);
    b = allocate(3);
    deallocate(b);
    e = allocate(39);
    f = allocate(342);
    deallocate(f);
    g = allocate(394);
    deallocate(a);
    deallocate(c);
    h = allocate(23);
    deallocate(h);
    i = allocate(47);
    deallocate(g);
    j = allocate(239);
    deallocate(e);
    deallocate(i);
    k = allocate(103);
    l = allocate(29);
    deallocate(l);
    m = allocate(92);
    n = allocate(37);
    o = allocate(237);
    p = allocate(47);
    deallocate(j);
    deallocate(m);
    deallocate(n);
    deallocate(k);
    q = allocate(28);
    r = allocate(93);
    s = allocate(67);
    deallocate(r);
    deallocate(q);
    t = allocate(39);
    u = allocate(34);
    v = allocate(29);
    w = allocate(39);
    x = allocate(93);
    y = allocate(29);
    deallocate(o);
    deallocate(u);
    deallocate(p);
    deallocate(x);
    deallocate(v);
    z = allocate(100);
    deallocate(s);
    deallocate(t);
    deallocate(z);
    deallocate(w);
    deallocate(y);
    initialise(mem+4000,1000,NULL);//initilise the linked list with one node
    a = allocate(100);
    b = allocate(200);
    deallocate(a);
    c = allocate(300);
    //random
    deallocate(b);
    a = allocate(20);
    b = allocate(3);
    deallocate(b);
    e = allocate(39);
    f = allocate(342);
    deallocate(f);
    g = allocate(394);
    deallocate(a);
    deallocate(c);
    h = allocate(23);
    deallocate(h);
    i = allocate(47);
    deallocate(g);
    j = allocate(239);
    deallocate(e);
    deallocate(i);
    k = allocate(103);
    l = allocate(29);
    deallocate(l);
    m = allocate(92);
    n = allocate(37);
    o = allocate(237);
    p = allocate(47);
    deallocate(j);
    deallocate(m);
    deallocate(n);
    deallocate(k);
    q = allocate(28);
    r = allocate(93);
    s = allocate(67);
    deallocate(r);
    deallocate(q);
    t = allocate(39);
    u = allocate(34);
    v = allocate(29);
    w = allocate(39);
    x = allocate(93);
    y = allocate(29);
    deallocate(o);
    deallocate(u);
    deallocate(p);
    deallocate(x);
    deallocate(v);
    z = allocate(100);
    deallocate(s);
    deallocate(t);
    deallocate(z);
    deallocate(w);
    deallocate(y);
    return 0;
}