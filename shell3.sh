echo Print $1 $2 times;
n=` expr $2 + 1 `
for ((i=1;i<$n;i++))
do
echo $1;
done
