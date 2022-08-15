#include "gtest/gtest.h"
#include "gmock/gmock.h"
extern "C"
{
#include "net_cfg.h"
#include "Com.h"
#include "ComM.h"
#include "rbNet_x_app_func.h"
#include "mon_inputhandler.h"
#include "rbNet_x_ProtectRxP05.h"
#include "globaltime_cfg.h"
}

struct CMocks
{
	CMocks();
	~CMocks();
	MOCK_METHOD3(Com_SetIpduGroup, void(Com_IpduGroupVector, Com_IpduGroupIdType, boolean));
	MOCK_METHOD2(Com_IpduGroupControl, void(uint8*, boolean));
	MOCK_METHOD1(Com_ClearIpduGroupVector, void(uint8*));
	MOCK_METHOD2(ComM_CommunicationAllowed, void(NetworkHandleType, boolean));
	MOCK_METHOD2(ComM_RequestComMode, Std_ReturnType(ComM_UserHandleType, ComM_ModeType));
	MOCK_METHOD2(Com_ReceiveSignal, uint8(Com_SignalIdType, void*));
	MOCK_METHOD2(Com_SendSignal, uint8(Com_SignalIdType, const void*));
	//MOCK_METHOD0(Net_GAC_Transfer_VFC2PUB, void(void));

};
