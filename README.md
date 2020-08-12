Use Offline Information, No Use HLT Information.

How To CMake

cd /home/shiomi/.
setupATLAS
lsetup "root 6.12.04-x86_64-slc6-gcc62-opt"
cd -

cd build
cmake ../
make

cd ../run/
sh run.sh
