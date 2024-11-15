#./wrench.sh -v -d -C -L -p 80 
./wrench.sh -v -d -A -C -L -p 80 

#stap -L 'kernel.statement("tcp_rcv_state_process@*:*")'
#stap -L 'module("ip_vs").function("*")'
#https://unix.stackexchange.com/questions/726146/systemtap-probe-kernel-module-function-while-that-module-is-loaded
#/usr/lib/debug/lib/modules/6.8.0-48-generic/kernel/net/netfilter/ipvs/    unzstd ip_vs.ko.zst 
