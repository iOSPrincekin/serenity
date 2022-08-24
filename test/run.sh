QEMU="qemu-system-i386"
target=Prekernel
PORT=1235
QEMU_ARGUMENT=" -gdb tcp:127.0.0.1:${PORT} -kernel ${target} "
LLDB=lldb

CMAKE_CURRENT_SOURCE_DIR="/Users/lee/Desktop/Computer_Systems/serenity/Build/i686/Kernel/Prekernel"
SUDO="sudo -S <<< lh1992524"
osascript -e "tell application \"Terminal\" to quit"
osascript -e "tell application \"Terminal\" \
to do script \"cd ${CMAKE_CURRENT_SOURCE_DIR} \n  ${SUDO} pkill -f ${QEMU} \n  kill -9 $(lsof -ti:${PORT}) \n ${QEMU} ${QEMU_ARGUMENT}\" in window 1" \
-e "tell application \"Terminal\" to activate" \
-e "tell application \"System Events\" to tell process \"Terminal\" to keystroke \"t\" using command down" \
-e "tell application \"Terminal\" to set background color of window 1 to {0,0,0,1}" \
-e "tell application \"Terminal\" \
to do script \"cd ${CMAKE_CURRENT_SOURCE_DIR} \n sleep 0.18 \n ${LLDB} ${target} \n b start\n gdb-remote localhost:${PORT}\n\" in window 1 "
