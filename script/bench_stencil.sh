#!/bin/bash

mkdir ../build

OUT_FILE="../data/stencil_permutation.csv"
TMP_FILE="/tmp/stencil.log"
TIME="10"

echo "permutation,size,time,throughput,iter,flops" >$OUT_FILE

cd ../build/
cmake .. -DCMAKE_BUILD_TYPE=Release 2>&1 1>/dev/null
if [ $? -ne 0 ]; then
  echo "CMAKE failed with release build."
  cd ..
  rm -rf ../build
  exit 1
fi

# ijk
for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DIJK=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

# ikj
for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DIKJ=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

# jik
for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DJIK=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

# jki
for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DJKI=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

# kij
for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DKIJ=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

# kji
for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DKJI=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DVECTO=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done

rm -rf *

for size in $(seq 100 100 600); do
  cmake .. -DCMAKE_BUILD_TYPE=Release -DBLOCKS=ON -DSIZE="$size" -DTIME=$TIME >/dev/null
  make -s -j2 1>/dev/null
  ./Stencil | grep summary | gawk '{print $4 }' >>$OUT_FILE
done