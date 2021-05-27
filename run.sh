make clean
make

gcc test.c -L./libmy_malloc.so -o test
echo
echo "+---------------+"
echo "| \e[38;5;226mStarting test \e[0m|"
echo "+---------------+"
echo

LD_PRELOAD=./libmy_malloc.so ./test

echo
echo "+---------------+"
echo "| \e[38;5;226m End of test  \e[0m|"
echo "+---------------+"
echo

echo -n "Return code is : " ; echo $?
rm test