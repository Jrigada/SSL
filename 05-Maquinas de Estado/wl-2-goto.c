#include <stdio.h>

main()
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;

OUT:
    do
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            goto OUT;
        else
        {
            goto IN;
        }
    } while ((c = getchar()) != EOF);

IN:
    do
    {
        ++nw;
        goto OUT;
    } while ((c = getchar()) != EOF);

        printf("%d %d %d\n", nl, nw, nc);
}