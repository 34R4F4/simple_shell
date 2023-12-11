#!/bin/bash
pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Max PID value: $pid_max"
