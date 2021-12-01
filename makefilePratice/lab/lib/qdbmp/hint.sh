# create PIC(position independent code) object
gcc -fPIC -c something.c
# create lib
gcc -shared -o libqdbmp.so something.o