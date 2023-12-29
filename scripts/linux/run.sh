echo $1
for i in `ls *.i.txt`; do
    echo $i
    id=`echo $i | cut -d'.' -f1`
    $1 < $i > $id.a.txt
    diff -Z -y $id.o.txt $id.a.txt > $id.d.txt
    if [ -s $id.d.txt ]; then
        echo -e "Failed \033[0;31m$id\033[0m"
        code --diff $id.o.txt $id.a.txt
    else
        echo -e "Passed \033[0;32m$id\033[0m"
    fi
done