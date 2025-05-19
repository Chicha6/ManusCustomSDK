Setup Guide
1. Download MANUS Core 2.5.1 and MANUS Core - SDK 2.5.1 from https://my.manus-meta.com/resources/downloads/quantum-metagloves
2. Navigate to SDKMinimalClient_Windows subfolder and locate the SDKMinimalClient.cpp and SDKMinimalClient.hpp files
3. Replace the 2 files from the previous step with the ones in this repo
4. Open the .vcxproj file in /SDKMinimalClient_Windows with Visual Studio (install Visual Studio if you have not) 
5. Build cppzmq via [vcpkg](https://github.com/zeromq/cppzmq/tree/master). This does an out of source build and installs the build files.
    ```
    git clone https://github.com/Microsoft/vcpkg.git
    cd vcpkg
    ./bootstrap-vcpkg.sh (bootstrap-vcpkg.bat for Powershell)
    ./vcpkg integrate install
    ./vcpkg install cppzmq
    ```
6. Build project in Visual Studio
7. Launch the executable
8. ![image](https://github.com/user-attachments/assets/a197d419-315e-4678-89a0-6e6e93ec81f2)
9. Press 2 for local and enter
10. ![image](https://github.com/user-attachments/assets/28f693e5-d12b-4dd3-b1b6-88240dfa890f)
    - Select data to be streamed that corresponds to the [mode of robot hand control](https://github.com/Chicha6/LEAPHand/blob/main/README.md)
        - Joint position for IK robot hand control
        - Joint angles for FK robot hand control
        - Combined data for combined IK and FK robot hand control
12. Upon mode selection, data will be streamed to the socket and to be received by the LEAP HAND python API
13. You can start running [LEAP Hand python API](https://github.com/Chicha6/LEAPHand/tree/main/python) 

    
    




