#ifndef MOCK_HPP
#define MOCK_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cc_appl_x_pri.h"
extern "C"
{
#include<Rte_Type.h>
#include <rbNet_x_app_func.h>
	/* include public header */
#include <cc_appl_x_pub.h>
#include <cc_appl_x_pri.h>
}
#include <precondition_x_pub.hpp>

class cc_appl_x_itf {
public:
	virtual ~cc_appl_x_itf() {}
public:
	virtual void Net_ComCtrl_Switch_Rx_PDU(bool RX_Enable) = 0;
	virtual void Net_ComCtrl_Switch_Tx_PDU(bool RX_Enable) = 0;

};

class Cmocks :public cc_appl_x_itf {
public:
	MOCK_METHOD1(Net_ComCtrl_Switch_Rx_PDU, void(bool));
	MOCK_METHOD1(Net_ComCtrl_Switch_Tx_PDU, void(bool));

};

#endif // !MOCK_HPP