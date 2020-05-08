
executable=$1

mkdir -p test_results
rm -rf *.o
gcc -c functions.c looping_structure.c list.c test/*.c
gcc -o test_results/$1 *.o
test_results/$1
rm -rf *.o