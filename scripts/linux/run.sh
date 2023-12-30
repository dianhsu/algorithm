# $1: executable file
for i in `ls *.i.txt`; do
    id=`echo $i | cut -d'.' -f1`
    echo -n "Running test case $id ... "
    $1 < $i > $id.a.txt
    cnt=`diff -Z $id.o.txt $id.a.txt | wc -l`
    if [ $cnt -gt 0 ]; then
        echo -e "\033[0;31mFailed\033[0m."
        code --diff $id.o.txt $id.a.txt
    else
        echo -e "\033[0;32mPassed\033[0m."
    fi
done