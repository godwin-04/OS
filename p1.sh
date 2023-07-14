cd /
cd proc
echo "(a) Find the number of processes your machine has."
cat cpuinfo | grep processor
echo "(b) How many cores does your machine has?"
grep cores cpuinfo
echo "(c) What is the frequency of each processor?"
cat cpuinfo | grep MHz
echo "(d) How much physical memory does your system have?"
cat meminfo | grep -h MemTotal
echo "(e) How much memory is free?"
cat meminfo | grep -h MemFree
echo "(f) What is total no. of forks since the boot in system?"
cat stat | grep -h processes
echo "(g) How many context switches has the system performed since bootup?"
cat stat | grep ctxt
