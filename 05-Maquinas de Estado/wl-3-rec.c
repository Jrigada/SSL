#include <stdio.h>

main()
{
    int  nl, nc, nw;
    nl = nc = nw = 0;
    out(nl,nc,nw);
    printf("%d %d %d\n", nl, nw, nc);
}

void out(int nl, int nc, int nw){
    nc++;
    char c = getchar();
    if (c == EOF)
        return;
    switch (c)
        {
        case '\n':
            ++nl;
            out(nl,nc,nw);
            break;

        case ' ' || '\n' || '\t':
            out(nl,nc,nw);
            break;

        default:
            in(nl,nc,nw);
        }

}

void in(int nl, int nc, int nw){
    nw++;
    out(nl,nc,nw);
}