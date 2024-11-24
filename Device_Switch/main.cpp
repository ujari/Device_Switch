#include <iostream>
#include <Windows.h>
#include <Cfgmgr32.h>
#pragma comment(lib, "SetupAPI.lib")
#pragma comment(lib, "Cfgmgr32.lib")

void Device_op(const std::string& deviceInstanceId) {

    DEVINST devInst;
    ULONG s,p;
    CONFIGRET cr = CM_Locate_DevNodeA(&devInst, const_cast<DEVINSTID_A>(deviceInstanceId.c_str()), CM_LOCATE_DEVNODE_NORMAL);

    if (cr != CR_SUCCESS) {
        std::cerr << "��ġ�� ã�� �� �����ϴ�. ���� �ڵ�: " << cr << std::endl;
    }
    
    //��ġ ���� �ҷ�����
    CM_Get_DevNode_Status(&s,&p,devInst,0);

    
    if (s & DN_DRIVER_LOADED)//��ġ�� Ȱ��ȭ ���ִ� ���
    {
        CM_Disable_DevNode(devInst, 0);//��Ȱ����ȭ
    }
    else CM_Enable_DevNode(devInst, 0);
}


int main() {
    std::string deviceInstanceId = "Your instant ID";
    Device_op(deviceInstanceId);
    return 0;
}
