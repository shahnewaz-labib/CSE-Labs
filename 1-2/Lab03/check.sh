for((i = 1; ; i++)); do
    echo $i
    ./gen.out $i > int
    diff -w <(./1.3.out < int) <(./brute.out < int) || break
done
