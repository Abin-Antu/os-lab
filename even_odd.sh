echo "enter a number"
read num
if [$(expr $num%2 -eq 0)]; then
    echo "number is even"
else 
    echo "number is odd"
fi