#!/bin/bash
wget -P /tmp https://github.com/NafisaKaruri/alx-low_level_programming/raw/master/0x18-dynamic_libraries/librandom.so
export LD_PRELOAD=/tmp/librandom.so
