#!/bin/bash

#
# Set environment
#

function simu_killall()
{
  sleep 1 ; killall -SIGINT rviz2
  sleep 1 ; killall -SIGINT sick_generic_caller
  sleep 1 ; killall -SIGINT sick_scan_emulator
  sleep 1 ; killall -9 rviz2
  sleep 1 ; killall -9 sick_generic_caller
  sleep 1 ; killall -9 sick_scan_emulator 
  sleep 1
}

simu_killall
printf "\033c"
pushd ../../../..
source ./install/setup.bash

#
# Run simulation:
# 1. Start sick_scan_emulator
# 2. Start sick_scan driver sick_generic_caller
# 3. Run rviz
#

echo -e "run_linux_ros2_simu_mrs1104.bash: starting MRS1104 emulation with sick_mrs_1xxx.launch\n"
cp -f ./src/sick_scan_xd/test/emulator/scandata/20210722_143600_ros2_mrs1104_sick_scan_xd.pcapng.json /tmp/lmd_scandata.pcapng.json
sleep  1 ; ros2 run sick_scan sick_scan_emulator ./src/sick_scan_xd/test/emulator/launch/emulator_mrs1104.launch &
# sleep  1 ; ros2 run sick_scan sick_generic_caller ./src/sick_scan_xd/launch/sick_mrs_1xxx.launch hostname:=127.0.0.1 port:=2111  & 
sleep  1 ; ros2 run sick_scan sick_generic_caller ./src/sick_scan_xd/launch/sick_mrs_1xxx.launch hostname:=127.0.0.1 port:=2111 sw_pll_only_publish:=False & 
sleep  1 ; ros2 run rviz2 rviz2 -d ./src/sick_scan_xd/test/emulator/config/rviz_emulator_cfg_ros2_mrs1104.rviz &

# Wait for 'q' or 'Q' to exit or until rviz is closed ...
for n in $(seq 25 -1 1) ; do
  echo -e "mrs1104 emulation running. Up to $n seconds until scan data become available..."
  sleep 1
done
while true ; do  
  echo -e "mrs1104 emulation running. Close rviz or press 'q' to exit..." ; read -t 1.0 -n1 -s key
  if [[ $key = "q" ]] || [[ $key = "Q" ]]; then break ; fi
  rviz_running=`(ps -elf | grep rviz2 | grep -v grep | wc -l)`
  if [ $rviz_running -lt 1 ] ; then break ; fi
done

# ... or stop simulation after 30 seconds
# sleep 30

simu_killall  
popd

