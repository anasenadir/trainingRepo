#!/bin/bash

read -r line < /proc/sys/kernel/pid_max
echo "the maximum process id is = $line"
