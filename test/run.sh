arg_1=$1

QEMU="qemu-system-i386"
Prekernel_Target=Prekernel/Prekernel
Kernel_Target=Kernel
PORT=1235
QEMU_ARGUMENT=" -gdb tcp:127.0.0.1:${PORT} -kernel ${Prekernel_Target} -initrd ${Kernel_Target} -append disable_kaslr"
LLDB=lldb

CMAKE_CURRENT_SOURCE_DIR="/Users/lee/Desktop/Computer_Systems/serenity/Build/i686/Kernel/"
SUDO="sudo -S <<< lh1992524"
osascript -e "tell application \"Terminal\" to quit"
if [ "$arg_1" = "debug" ];then

osascript -e "tell application \"Terminal\" \
to do script \"cd ${CMAKE_CURRENT_SOURCE_DIR} \n  ${SUDO} pkill -f ${QEMU} \n  kill -9 $(lsof -ti:${PORT}) \n ${QEMU} ${QEMU_ARGUMENT}\" in window 1" \
-e "tell application \"Terminal\" to activate" \
-e "tell application \"System Events\" to tell process \"Terminal\" to keystroke \"t\" using command down" \
-e "tell application \"Terminal\" to set background color of window 1 to {0,0,0,1}" \
-e "tell application \"Terminal\" \
to do script \"cd ${CMAKE_CURRENT_SOURCE_DIR} \n sleep 0.18 \n ${LLDB} ${Prekernel_Target} \n b start\n gdb-remote localhost:${PORT}\n\" in window 1 "

else

cd ${CMAKE_CURRENT_SOURCE_DIR}
qemu-system-i386 -kernel ${Prekernel_Target}

fi;
