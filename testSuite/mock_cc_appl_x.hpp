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


class Cmocks {
public:
	Cmocks();
	~Cmocks();
	MOCK_METHOD1(Net_ComCtrl_Switch_RX_PDU, void(bool));
	MOCK_METHOD1(Net_ComCtrl_Switch_TX_PDU, void(bool));

};

#endif // !MOCK_HPP