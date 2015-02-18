read a
read b
if [ -f $a ]
then
echo $a exists;
else
echo $a does not exist;
fi
if [ -f $b ]
then
echo $b exists;
cat $a>>$b
else
cat $a>$b
fi
