if [ $1 = ` ` ]
then
c=` expr 50 \* 51 `;
echo ` expr $c / 2 `;
else
a=` expr $1 + 1 `
if [ ` expr $1 % 2 ` == 0 ]
then
b=` expr $1 / 2 `
echo ` expr $b \* $a `;
else
b=` expr $a / 2 `
echo ` expr $1 \* $b `;
fi
fi
