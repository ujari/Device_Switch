#include <iostream>
#include <Windows.h>
#include <SetupAPI.h>
#include <Cfgmgr32.h>
#pragma comment(lib, "SetupAPI.lib")
#pragma comment(lib, "Cfgmgr32.lib")

// 장치 활성화 함수
bool EnableDevice(const std::string& deviceInstanceId) {
    DEVINST devInst;
    CONFIGRET cr = CM_Locate_DevNodeA(&devInst, const_cast<DEVINSTID_A>(deviceInstanceId.c_str()), CM_LOCATE_DEVNODE_NORMAL);

    if (cr != CR_SUCCESS) {
        std::cerr << "장치를 찾을 수 없습니다. 오류 코드: " << cr << std::endl;
        return false;
    }

    cr = CM_Enable_DevNode(devInst, 0);
    if (cr != CR_SUCCESS) {
        std::cerr << "장치를 활성화할 수 없습니다. 오류 코드: " << cr << std::endl;
        return false;
    }

    std::cout << "장치가 활성화되었습니다." << std::endl;
    return true;
}

// 장치 비활성화 함수
bool DisableDevice(const std::string& deviceInstanceId) {
    DEVINST devInst;
    CONFIGRET cr = CM_Locate_DevNodeA(&devInst, const_cast<DEVINSTID_A>(deviceInstanceId.c_str()), CM_LOCATE_DEVNODE_NORMAL);

    if (cr != CR_SUCCESS) {
        std::cerr << "장치를 찾을 수 없습니다. 오류 코드: " << cr << std::endl;
        return false;
    }

    cr = CM_Disable_DevNode(devInst, 0);
    if (cr != CR_SUCCESS) {
        std::cerr << "장치를 비활성화할 수 없습니다. 오류 코드: " << cr << std::endl;
        return false;
    }

    std::cout << "장치가 비활성화되었습니다." << std::endl;
    return true;
}

int main() {
    std::string deviceInstanceId = "Your instant ID";
    int choice;

    std::cout << "1. 장치 활성화\n2. 장치 비활성화\n선택하세요: ";
    std::cin >> choice;

    if (choice == 1) {
        EnableDevice(deviceInstanceId);
    }
    else if (choice == 2) {
        DisableDevice(deviceInstanceId);
    }
    else {
        std::cout << "잘못된 선택입니다." << std::endl;
    }

    return 0;
}
