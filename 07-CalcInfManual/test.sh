#! /bin/bash


calc1="@2+2/"
calc2="@2*3/"
calc3="@2+(2*3)/"
calc4="@2*(2+3*2)/"
calc5="a=1;@a+2/"
calc6="a=1;b=2;@a+b/"
calc7="a=3;b=2;@a+(a*b)/"
calc8="a=3;b=2;@(a+b)*2/"


echo $calc1 | ./calc > output
echo $calc2 | ./calc >> output
echo $calc3 | ./calc >> output
echo $calc4 | ./calc >> output
echo $calc5 | ./calc >> output
echo $calc6 | ./calc >> output
echo $calc7 | ./calc >> output
echo $calc8 | ./calc >> output

cat output

diff --brief <(sort output) <(sort results) >/dev/null
comp_value=$?

if [ $comp_value -eq 1 ]
then
    echo "Failed"
else
    echo "All tests OK"
fi
