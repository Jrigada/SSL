#! /bin/bash


calc1="@2+2/"
calc2="@2*3/"
calc3="@2+(2*3)/"
calc4="@2*(2+3*2)/"
calc5="a=1;@a+2/"
calc6="a=1;b=2;@a+b/"
calc7="a=3;b=2;@a+(a*b)/"
calc8="a=3;b=2;@(a+b)*2/"


echo -n $calc1 > example.txt

./parser > output

echo -n $calc2 > example.txt

./parser >> output

echo -n $calc3 > example.txt

./parser >> output

echo -n $calc4 > example.txt

./parser >> output

echo -n $calc5 > example.txt

./parser >> output

echo -n $calc6 > example.txt

./parser >> output

echo -n $calc7 > example.txt

./parser >> output

echo -n $calc8 > example.txt

./parser >> output

echo -n $calc9 > example.txt

./parser >> output

echo -n $calc10 > example.txt

./parser >> output

cat output

diff --brief <(sort output) <(sort results) >/dev/null
comp_value=$?

if [ $comp_value -eq 1 ]
then
    echo "Failed"
else
    echo "All tests OK"
fi
