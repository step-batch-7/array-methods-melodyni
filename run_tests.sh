
executable=$1

mkdir -p test_results
rm -rf *.o
gcc -c array.c array_void.c test/*.c
gcc -o test_results/$1 *.o
test_results/$1
rm -rf *.o