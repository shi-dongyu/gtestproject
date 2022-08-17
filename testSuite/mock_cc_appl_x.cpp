#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mock_cc_appl_x.hpp"
#include <functional>


static std::function<void(boolean)> _Net_ComCtrl_Switch_RX_PDU;
static std::function<void(boolean)> _Net_ComCtrl_Switch_TX_PDU;

Cmocks::Cmocks() 
{
	assert(!_Net_ComCtrl_Switch_RX_PDU);
		_Net_ComCtrl_Switch_RX_PDU = [this](boolean Rx_Enable) {return Net_ComCtrl_Switch_RX_PDU(Rx_Enable);};
	assert(!_Net_ComCtrl_Switch_TX_PDU);
		_Net_ComCtrl_Switch_TX_PDU = [this](boolean Rx_Enable) {return Net_ComCtrl_Switch_TX_PDU(Rx_Enable); };

}
Cmocks::~Cmocks(){
	_Net_ComCtrl_Switch_RX_PDU = {};
	_Net_ComCtrl_Switch_TX_PDU = {};
}


void Net_ComCtrl_Switch_RX_PDU(boolean RX_Enable) {

	return _Net_ComCtrl_Switch_RX_PDU(RX_Enable);

}


void Net_ComCtrl_Switch_TX_PDU(boolean RX_Enable) {
	return _Net_ComCtrl_Switch_TX_PDU(RX_Enable);
}
