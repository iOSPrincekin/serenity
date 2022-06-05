set arch i386:x86-64
file /Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Kernel/Prekernel/Prekernel32
set confirm off
directory /Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default
add-symbol-file /Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Kernel/Kernel -o 0xc0200000
set confirm on
source /Users/lee/Desktop/Computer_Systems/serenity/Meta/serenity_gdb.py