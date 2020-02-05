n=140001
q=100000

# n=10
# q=10

echo $n
echo "-1"
seq 1 $(($n-1))
echo $q
for ((i=0;i<$q;i=i+1));do
    echo "$(($RANDOM % $q + 1)) $(($RANDOM % $q + 1))"
done