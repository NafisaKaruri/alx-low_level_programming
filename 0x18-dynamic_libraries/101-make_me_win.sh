#!/bin/bash
wget -O /tmp/librand.so https://github.com/NafisaKaruri/alx-low_level_programming/raw/master/0x18-dynamic_libraries/librandom.so
export LD_PRELOAD=/tmp/librand.so
