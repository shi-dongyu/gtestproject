#include "mock_rbNet_x_app_func.hpp"
#include <functional>

uint8 g_vehicle_variant_ub;
uint8 g_vehicle_type_ub;
FSICOM_PRIVATE_E2E_INFO fsicom_private_e2e_info[i_VFC_End] =
{
	{ i_VFC_Line01, FALSE, FALSE },
	{ i_VFC_Line02, FALSE, FALSE },
	{ i_VFC_Line03, FALSE, FALSE },
	{ i_VFC_Line04, FALSE, FALSE },
	{ i_VFC_Line05, FALSE, FALSE },
	{ i_VFC_Line06, FALSE, FALSE },
	{ i_VFC_Line07, FALSE, FALSE },
	{ i_VFC_Line08, FALSE, FALSE },
	{ i_VFC_LineHdr, FALSE, FALSE },
	{ i_VFC_Obj00A, FALSE, FALSE },
	{ i_VFC_Obj00B, FALSE, FALSE },
	{ i_VFC_Obj01A, FALSE, FALSE },
	{ i_VFC_Obj01B, FALSE, FALSE },
	{ i_VFC_Obj02A, FALSE, FALSE },
	{ i_VFC_Obj02B, FALSE, FALSE },
	{ i_VFC_Obj03A, FALSE, FALSE },
	{ i_VFC_Obj03B, FALSE, FALSE },
	{ i_VFC_Obj04A, FALSE, FALSE },
	{ i_VFC_Obj04B, FALSE, FALSE },
	{ i_VFC_Obj05A, FALSE, FALSE },
	{ i_VFC_Obj05B, FALSE, FALSE },
	{ i_VFC_Obj06A, FALSE, FALSE },
	{ i_VFC_Obj06B, FALSE, FALSE },
	{ i_VFC_Obj07A, FALSE, FALSE },
	{ i_VFC_Obj07B, FALSE, FALSE },
	{ i_VFC_Obj08A, FALSE, FALSE },
	{ i_VFC_Obj08B, FALSE, FALSE },
	{ i_VFC_Obj09A, FALSE, FALSE },
	{ i_VFC_Obj09B, FALSE, FALSE },
	{ i_VFC_Obj10A, FALSE, FALSE },
	{ i_VFC_Obj10B, FALSE, FALSE },
	{ i_VFC_Obj11A, FALSE, FALSE },
	{ i_VFC_Obj11B, FALSE, FALSE },
	{ i_VFC_Obj12A, FALSE, FALSE },
	{ i_VFC_Obj12B, FALSE, FALSE },
	{ i_VFC_Obj13A, FALSE, FALSE },
	{ i_VFC_Obj13B, FALSE, FALSE },
	{ i_VFC_Obj14A, FALSE, FALSE },
	{ i_VFC_Obj14B, FALSE, FALSE },
	{ i_VFC_Obj15A, FALSE, FALSE },
	{ i_VFC_Obj15B, FALSE, FALSE },
	{ i_VFC_Obj16A, FALSE, FALSE },
	{ i_VFC_Obj16B, FALSE, FALSE },
	{ i_VFC_Obj17A, FALSE, FALSE },
	{ i_VFC_Obj17B, FALSE, FALSE },
	{ i_VFC_Obj18A, FALSE, FALSE },
	{ i_VFC_Obj18B, FALSE, FALSE },
	{ i_VFC_Obj19A, FALSE, FALSE },
	{ i_VFC_Obj19B, FALSE, FALSE },
	{ i_VFC_ObjHdr, FALSE, FALSE },
	{ i_VFC_Dev_Video_SyncVisor_TX, FALSE, FALSE },
	{ i_VFC_SensorState, FALSE, FALSE },
	{ i_VFC_TSR_ASL, FALSE, FALSE },
	{ i_VFC_TSR_Req, FALSE, FALSE }
};
//SACONTROLLER_ST NVM_SA_Controller_st;


static std::function<void(Com_IpduGroupVector, Com_IpduGroupIdType, boolean)> _Com_SetIpduGroup;
static std::function<void(uint8*)> _Com_ClearIpduGroupVector;
static std::function<void(NetworkHandleType, boolean)> _ComM_CommunicationAllowed;
static std::function<Std_ReturnType(ComM_UserHandleType, ComM_ModeType)> _ComM_RequestComMode;
static std::function<void(uint8*, boolean)> _Com_IpduGroupControl;
static std::function<void(void)> _Net_GAC_Transfer_VFC2PUB;
static std::function<uint8(Com_SignalIdType, void*)> _Com_ReceiveSignal;
static std::function<uint8(Com_SignalIdType, const void*)> _Com_SendSignal;


CMocks::CMocks() {

	assert(!_Com_SetIpduGroup);
	_Com_SetIpduGroup = [this](Com_IpduGroupVector ipduGroupVector, Com_IpduGroupIdType IpduGroupId, boolean bitval) { return Com_SetIpduGroup(ipduGroupVector, IpduGroupId, bitval); };
	assert(!_Com_ClearIpduGroupVector);
	_Com_ClearIpduGroupVector = [this](uint8* ipduGroupVector) { return Com_ClearIpduGroupVector(ipduGroupVector); };
	assert(!_ComM_CommunicationAllowed);
	_ComM_CommunicationAllowed = [this](NetworkHandleType Channel, boolean Allowed) { return ComM_CommunicationAllowed(Channel, Allowed); };
	assert(!_ComM_RequestComMode);
	_ComM_RequestComMode = [this](ComM_UserHandleType User, ComM_ModeType ComMode) {return ComM_RequestComMode(User, ComMode); };
	assert(!_Com_IpduGroupControl);
	_Com_IpduGroupControl = [this](uint8* ipduGroupVector, boolean initialize) {return Com_IpduGroupControl(ipduGroupVector, initialize); };
	assert(!_Com_ReceiveSignal);
	_Com_ReceiveSignal = [this](Com_SignalIdType Signalld, void* SignalDataPtr) {return Com_ReceiveSignal(Signalld, SignalDataPtr); };
	assert(!_Com_SendSignal);
	_Com_SendSignal = [this](Com_SignalIdType Signalld, const void* SignalDataPtr) {return Com_SendSignal(Signalld, SignalDataPtr); };
	//assert(!_Net_GAC_Transfer_VFC2PUB);
	//_Net_GAC_Transfer_VFC2PUB = [this]() {return Net_GAC_Transfer_VFC2PUB(); };

}
CMocks::~CMocks() {
	_Com_SetIpduGroup = {};
	_ComM_CommunicationAllowed = {};
	_Com_ClearIpduGroupVector = {};
	_ComM_RequestComMode = {};
	_Com_IpduGroupControl = {};
	_Com_ReceiveSignal = {};
	_Com_SendSignal = {};
	_Net_GAC_Transfer_VFC2PUB = {};

}

void Com_SetIpduGroup(uint8* ipduGroupVector, Com_IpduGroupIdType IpduGroupId, boolean bitval) {
	return _Com_SetIpduGroup(ipduGroupVector, IpduGroupId, bitval);
}

void Com_IpduGroupControl(uint8* ipduGroupVector, boolean initialize) {
	return _Com_IpduGroupControl(ipduGroupVector, initialize);
}

void Com_ClearIpduGroupVector(uint8* ipduGroupVector) {
	return _Com_ClearIpduGroupVector(ipduGroupVector);
}

void ComM_CommunicationAllowed(NetworkHandleType Channel, boolean Allowed) {
	return _ComM_CommunicationAllowed(Channel, Allowed);
}

Std_ReturnType ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode) {
	return _ComM_RequestComMode(User, ComMode);
}

uint8 Com_ReceiveSignal(Com_SignalIdType Signalld, void* SignalDtaPtr) {
	return  _Com_ReceiveSignal(Signalld, SignalDtaPtr);
}

uint8 Com_SendSignal(Com_SignalIdType Signalld, const void* SignalDtaPtr) {
	return  _Com_SendSignal(Signalld, SignalDtaPtr);
}
//
//void Net_GAC_Transfer_VFC2PUB(void) {
//	return _Net_GAC_Transfer_VFC2PUB();
//}
//
