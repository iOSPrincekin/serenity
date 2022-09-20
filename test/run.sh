arg_1=$1

QEMU="qemu-system-i386"
Prekernel_Target=Kernel/Prekernel/Prekernel
Kernel_Target=Kernel/Kernel
PORT=1235
QEMU_ARGUMENT=" -gdb tcp:127.0.0.1:${PORT}  
                -kernel ${Prekernel_Target} -initrd ${Kernel_Target}  
                -gdb tcp:127.0.0.1:1235

                -m 1G
                -smp 2
                -display cocoa,gl=off
                -device VGA,vgamem_mb=64
                -device virtio-serial,max_ports=2
                -device virtconsole,chardev=stdout
                -device isa-debugcon,chardev=stdout
                -device virtio-rng-pci
                -audiodev coreaudio,id=snd0
                -machine pcspk-audiodev=snd0
                -device ac97,audiodev=snd0
                -device pci-bridge,chassis_nr=1,id=bridge1 -device e1000,bus=bridge1
                -device i82801b11-bridge,bus=bridge1,id=bridge2 -device sdhci-pci,bus=bridge2
                -device i82801b11-bridge,id=bridge3 -device sdhci-pci,bus=bridge3
                -device ich9-ahci,bus=bridge3
                -chardev stdio,id=stdout,mux=on
                -drive file=_disk_image,format=raw,index=0,media=disk,id=disk

                -qmp unix:qmp-sock,server,nowait
                -cpu max,-x2apic
-name SerenityOS
-d guest_errors
-usb


    -netdev user,id=breh,hostfwd=tcp:127.0.0.1:8888-10.0.2.15:8888,hostfwd=tcp:127.0.0.1:8823-10.0.2.15:23,hostfwd=tcp:127.0.0.1:8000-10.0.2.15:8000,hostfwd=tcp:127.0.0.1:2222-10.0.2.15:22
    -device e1000,netdev=breh
    -append disable_kaslr
                -append disable_kaslr"
LLDB=lldb

CMAKE_CURRENT_SOURCE_DIR="/Users/lee/Desktop/Computer_Systems/serenity/Build/i686/"
SUDO="sudo -S <<< lh1992524"
osascript -e "tell application \"Terminal\" to quit"
if [ "$arg_1" = "debug" ];then

osascript -e "tell application \"Terminal\" \
to do script \"cd ${CMAKE_CURRENT_SOURCE_DIR} \n  ${SUDO} pkill -f ${QEMU} \n ${QEMU} ${QEMU_ARGUMENT}\" in window 1" \
-e "tell application \"Terminal\" to activate" \
-e "tell application \"System Events\" to tell process \"Terminal\" to keystroke \"t\" using command down" \
-e "tell application \"Terminal\" to set background color of window 1 to {0,0,0,1}" \
-e "tell application \"Terminal\" \
to do script \"cd ${CMAKE_CURRENT_SOURCE_DIR} \n sleep 0.1 \n ${LLDB} ${Prekernel_Target} \n b start\n gdb-remote localhost:${PORT}\n\" in window 1 "

else

cd ${CMAKE_CURRENT_SOURCE_DIR}
qemu-system-i386 -kernel ${Prekernel_Target}

fi;
