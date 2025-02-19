#!/bin/bash

function simu_ldmrs_killall()
{
  rosnode kill -a ; sleep 1
  killall sick_generic_caller ; sleep 1
  killall test_server ; sleep 1
}

simu_ldmrs_killall
printf "\033c"
pushd ../../../..
source /opt/ros/melodic/setup.bash
source ./install/setup.bash

echo -e "run_simu_ldmrs.bash: starting ldmrs emulation\n"

# Start roscore if not yet running
roscore_running=`(ps -elf | grep roscore | grep -v grep | wc -l)`
if [ $roscore_running -lt 1 ] ; then 
  roscore &
  sleep 3
fi

# Start test server
roslaunch sick_scan test_server_ldmrs.launch &
sleep 1

# Start rviz
# Note: Due to a bug in opengl 3 in combination with rviz and VMware, opengl 2 should be used by rviz option --opengl 210
# See https://github.com/ros-visualization/rviz/issues/1444 and https://github.com/ros-visualization/rviz/issues/1508 for further details

rosrun rviz rviz -d ./src/sick_scan_xd/launch/rviz/sick_ldmrs_ros1.rviz --opengl 210 &
sleep 1

# Start sick_scan driver for ldmrs
echo -e "Launching sick_scan sick_ldmrs.launch\n"
# roslaunch sick_scan sick_ldmrs.launch hostname:=192.168.0.111 &
roslaunch sick_scan sick_ldmrs.launch hostname:=127.0.0.1 &

# Run for 30 seconds and then close
sleep 30
simu_ldmrs_killall

# Run cola based simulation
for launch_file in sick_tim_240.launch sick_tim_5xx.launch sick_mrs_1xxx.launch ; do
  sleep  1 ; roslaunch sick_scan test_server_cola.launch &
  sleep  1 ; roslaunch sick_scan $launch_file hostname:=127.0.0.1 port:=2112 frame_id:=cloud sw_pll_only_publish:=False &
  sleep  1 ; rosrun rviz rviz -d ./src/sick_scan_xd/launch/rviz/sick_cola_ros1.rviz --opengl 210 &
  sleep 10 ; simu_ldmrs_killall
done

# Shutdown
echo -e "Finishing ldmrs emulation, shutdown ros nodes\n"
simu_ldmrs_killall
popd

