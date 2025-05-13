Setup Guide
1. Download MANUS Core 3 and MANUS Core 3 - SDK from https://my.manus-meta.com/resources/downloads/quantum-metagloves
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
10. ![image](https://github.com/user-attachments/assets/990afd45-7514-4b40-96c0-c24028e2ede8)
    




