#include <iostream>
#include <Windows.h>
#include <SetupAPI.h>
#include <Cfgmgr32.h>
#pragma comment(lib, "SetupAPI.lib")
#pragma comment(lib, "Cfgmgr32.lib")

// ��ġ Ȱ��ȭ �Լ�
bool EnableDevice(const std::string& deviceInstanceId) {
    DEVINST devInst;
    CONFIGRET cr = CM_Locate_DevNodeA(&devInst, const_cast<DEVINSTID_A>(deviceInstanceId.c_str()), CM_LOCATE_DEVNODE_NORMAL);

    if (cr != CR_SUCCESS) {
        std::cerr << "��ġ�� ã�� �� �����ϴ�. ���� �ڵ�: " << cr << std::endl;
        return false;
    }

    cr = CM_Enable_DevNode(devInst, 0);
    if (cr != CR_SUCCESS) {
        std::cerr << "��ġ�� Ȱ��ȭ�� �� �����ϴ�. ���� �ڵ�: " << cr << std::endl;
        return false;
    }

    std::cout << "��ġ�� Ȱ��ȭ�Ǿ����ϴ�." << std::endl;
    return true;
}

// ��ġ ��Ȱ��ȭ �Լ�
bool DisableDevice(const std::string& deviceInstanceId) {
    DEVINST devInst;
    CONFIGRET cr = CM_Locate_DevNodeA(&devInst, const_cast<DEVINSTID_A>(deviceInstanceId.c_str()), CM_LOCATE_DEVNODE_NORMAL);

    if (cr != CR_SUCCESS) {
        std::cerr << "��ġ�� ã�� �� �����ϴ�. ���� �ڵ�: " << cr << std::endl;
        return false;
    }

    cr = CM_Disable_DevNode(devInst, 0);
    if (cr != CR_SUCCESS) {
        std::cerr << "��ġ�� ��Ȱ��ȭ�� �� �����ϴ�. ���� �ڵ�: " << cr << std::endl;
        return false;
    }

    std::cout << "��ġ�� ��Ȱ��ȭ�Ǿ����ϴ�." << std::endl;
    return true;
}

int main() {
    std::string deviceInstanceId = "Your instant ID";
    int choice;

    std::cout << "1. ��ġ Ȱ��ȭ\n2. ��ġ ��Ȱ��ȭ\n�����ϼ���: ";
    std::cin >> choice;

    if (choice == 1) {
        EnableDevice(deviceInstanceId);
    }
    else if (choice == 2) {
        DisableDevice(deviceInstanceId);
    }
    else {
        std::cout << "�߸��� �����Դϴ�." << std::endl;
    }

    return 0;
}
