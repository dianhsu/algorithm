echo $1
for i in `ls *.i.txt`; do
    echo $i
    id=`echo $i | cut -d'.' -f1`
    $1 < $i > $id.a.txt
    diff -Z -y $id.o.txt $id.a.txt > $id.d.txt
    if [ -s $id.d.txt ]; then
        echo "Failed $id"
        code $id.d.txt
    else
        echo "Passed $id"
    fi
done