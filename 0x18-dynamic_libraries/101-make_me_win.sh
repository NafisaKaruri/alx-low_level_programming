#!/bin/bash
wget -O /tmp/librand.so https://github.com/NafisaKaruri/alx-low_level_programming/blob/master/0x18-dynamic_libraries/librand.so
export LD_PRELOAD=/tmp/librand.so
