#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mock_cc_appl_x.hpp"
//cc_appl_x includes headers
extern "C"
{
#include<Rte_Type.h>
#include<common_x_pub.h>
#include <DcmAppl.h>
#include <rbNet_x_app_func.h>
/* include public header */
#include <cc_appl_x_pub.h>
#include <cc_appl_x_pri.h>
}
#include <precondition_x_pub.hpp>


using namespace ::testing;
class testFixture :public Test
{
public:
	Cmocks cm;
};



TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_1)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_ENABLE_RX_TX_NORM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}
TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_2)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_ENABLE_RX_TX_NORM_NM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}
TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_3)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_ENABLE_RX_DISABLE_TX_NORM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}
TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_4)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}

TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_5)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_DISABLE_RX_ENABLE_TX_NORM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}
TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_6)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}
TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_7)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_DISABLE_RX_TX_NORMAL;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}
TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_8)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = DCM_DISABLE_RX_TX_NORM_NM;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}

TEST_F(testFixture, DcmAppl_DcmSwitchCommunicationControl_9)
{
	boolean RX_Enable = TRUE;
	uint8_t p_NetworkID_ub = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode_ub = 0xff;
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	DcmAppl_DcmSwitchCommunicationControl(p_NetworkID_ub, p_RequestedMode_ub);
}

TEST_F(testFixture, DcmAppl_DcmIsComModeDefault_1)
{
	boolean p_retVal = true;
	uint8 p_NetworkID = 0x00u;
	Dcm_CommunicationModeType p_RequestedMode = DCM_ENABLE_RX_TX_NORM;
	//EXPECT_CALL(cm, Net_ComCtrl_Switch_Rx_PDU(RX_Enable)).Times(1);
	//EXPECT_CALL(cm, Net_ComCtrl_Switch_Tx_PDU(RX_Enable)).Times(1);
	p_retVal = DcmAppl_DcmIsComModeDefault(p_NetworkID);
}

TEST_F(testFixture, DcmAppl_DcmCommControlConditionCheck_1) {
	uint8_t ControlType_u8;
	uint8_t DataCommType_u8;
	const UBYTE Requestdata[2] = {0x04};
	uint16_t ReqLen;
	Dcm_NegativeResponseCodeType* ErrorCode_pt;
}
