#include <stdio.h>

typedef enum state
{
    In,
    Out
} State;
main()
{
    int c, nl, nw, nc, state;
    state = Out;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        switch (c)
        {
        case '\n':
            ++nl;
            break;

        case ' ' || '\n' || '\t':
            state = Out;
            break;

        default:
            state = In;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}