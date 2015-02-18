echo Enter a string
read str
str1=` rev<<<$str `
if [ "$str" == "$str1" ]
then
echo String is palindrome;
else
echo String is not palindrome;
fi
