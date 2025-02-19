REM 
REM Run a basic sick_generic_caller unittest on Windows 64 (standalone, no ROS required) with a test server emulating a basic LMS5xx device
REM 

set PATH=%ProgramFiles(x86)%\Microsoft Visual Studio\Shared\Python36_64;%ProgramFiles(x86)%\Microsoft Visual Studio\Shared\Python37_64;%PATH%
set PATH=c:\vcpkg\installed\x64-windows\bin;%PATH%

REM 
REM Start html view
REM 

pushd ..\..\demo
del /f/q scan.jpg scan.csv
start "ImageViewer" image_viewer.html
@timeout /t 1
popd

REM 
REM Start test server
REM 

pushd ..\..\build_win64
python --version
start "python ../test/emulator/test_server.py" cmd /k python ../test/emulator/test_server.py --scandata_file=../test/emulator/scandata/20210302_lms511.pcapng.scandata.txt --scandata_frequency=20.0 --tcp_port=2112
@timeout /t 3
popd

REM 
REM Run sick_generic_caller
REM 

pushd ..\..\build_win64
.\Debug\sick_generic_caller.exe ../launch/sick_lms_5xx.launch hostname:=127.0.0.1 sw_pll_only_publish:=False
popd

@pause
