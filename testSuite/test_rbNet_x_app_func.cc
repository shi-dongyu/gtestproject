#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mock_rbNet_x_app_func.hpp"

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

using namespace ::testing;
class testfixture :public Test {
public:
	CMocks cm;
};


TEST_F(testfixture, rbNet_X_ComCtrl_Init_V)
{
	rbNet_X_ComCtrl_Init_V();
	//	EXPECT_CALL(ComM_CommunicationAllowed,)
}


TEST_F(testfixture, Net_ComCtrl_PDUGRP_A29_2)
{
	g_vehicle_type_ub = GAC_1R1V_VARIANT;
	g_vehicle_variant_ub = GAC_A18Y_VEHICLE;
	Net_ComCtrl_PDUGRP();
	EXPECT_EQ(g_RxEnable_b, TRUE);
	EXPECT_EQ(g_TxEnable_b, TRUE);

}

TEST_F(testfixture, Net_ComCtrl_PDUGRP_A18YA13)
{
	g_vehicle_type_ub = GAC_A29_2_VEHICLE;
	g_vehicle_variant_ub = GAC_5R1V1D_VARIANT;
	Net_ComCtrl_PDUGRP();

}

TEST_F(testfixture, Net_ComCtrl_PDUGRP_A29Y)
{
	g_vehicle_type_ub = GAC_A29Y_VEHICLE;
	g_vehicle_variant_ub = GAC_1R1V_VARIANT;
	Net_ComCtrl_PDUGRP();

}

TEST_F(testfixture, Net_ComCtrl_PDUGRP_A21)
{
	g_vehicle_type_ub = GAC_A21_VEHICLE;
	g_vehicle_variant_ub = GAC_1R1V_VARIANT;
	Net_ComCtrl_PDUGRP();

}

TEST_F(testfixture, Net_ComCtrl_Switch_TX_PDU_rxenable1) {
	boolean TX_ENABLE = TRUE;
	uint8 arr_g_vehicle_type_ub[4] = { GAC_A18V_VEHICLE,GAC_A18Y_VEHICLE,GAC_A29Y_VEHICLE,GAC_A21_VEHICLE };
	g_vehicle_variant_ub = GAC_1R1V_VARIANT;
	for (int i = 0; i < 4; i++) {
		g_vehicle_type_ub = arr_g_vehicle_type_ub[i];
		Net_ComCtrl_Switch_TX_PDU(TX_ENABLE);
	}
}

TEST_F(testfixture, Net_ComCtrl_Switch_TX_PDU_rxenable2) {
	boolean TX_ENABLE = TRUE;
	uint8 arr_g_vehicle_type_ub[4] = { GAC_A18V_VEHICLE + 10,GAC_A18Y_VEHICLE + 10,GAC_A29Y_VEHICLE + 10,GAC_A21_VEHICLE + 10 };
	g_vehicle_variant_ub = GAC_1R1V_VARIANT + 1;
	for (int i = 0; i < 4; i++) {
		g_vehicle_type_ub = arr_g_vehicle_type_ub[i];
		Net_ComCtrl_Switch_TX_PDU(TX_ENABLE);
	}
}

TEST_F(testfixture, Net_ComCtrl_Switch_TX_PDU_rxenable3) {
	boolean TX_ENABLE = TRUE;
	uint8 arr_g_vehicle_type_ub[4] = { GAC_A18V_VEHICLE + 10,GAC_A18Y_VEHICLE + 10,GAC_A29Y_VEHICLE + 10,GAC_A21_VEHICLE + 10 };
	g_vehicle_variant_ub = GAC_5R1V1D_VARIANT;
	Net_ComCtrl_Switch_TX_PDU(TX_ENABLE);
}

TEST_F(testfixture, Net_ComCtrl_Switch_TX_PDU_rxunable) {
	boolean TX_ENABLE = FALSE;
	Net_ComCtrl_Switch_TX_PDU(TX_ENABLE);
}

TEST_F(testfixture, Net_ComCtrl_Switch_RX_PDU_rxenable1) {
	boolean RX_ENABLE = TRUE;
	uint8 arr_g_vehicle_type_ub[3] = { GAC_A18Y_VEHICLE ,GAC_A18V_VEHICLE,GAC_A13_VEHICLE };
	uint8 arr_g_vehicle_variant_ub[3] = { GAC_1R1V_VARIANT ,GAC_5R1V1D_VARIANT,GAC_5R1V1D_VARIANT };
	for (int i = 0; i < 3; i++) {
		g_vehicle_type_ub = arr_g_vehicle_type_ub[i];
		g_vehicle_variant_ub = arr_g_vehicle_variant_ub[i];
		Net_ComCtrl_Switch_RX_PDU(RX_ENABLE);
	}
}

TEST_F(testfixture, Net_ComCtrl_Switch_RX_PDU_rxenable2) {
	boolean RX_ENABLE = TRUE;
	g_vehicle_type_ub = GAC_A29_2_VEHICLE;
	g_vehicle_variant_ub = GAC_5R1V1D_VARIANT;
	Net_ComCtrl_Switch_RX_PDU(RX_ENABLE);
}

TEST_F(testfixture, Net_ComCtrl_Switch_RX_PDU_rxenable3) {
	boolean RX_ENABLE = TRUE;
	uint8 arr_g_vehicle_type_ub[3] = { GAC_A21_VEHICLE ,GAC_A20_VEHICLE };
	uint8 arr_g_vehicle_variant_ub[3] = { GAC_1R1V_VARIANT ,GAC_1R1V_VARIANT };
	for (int i = 0; i < 3; i++) {
		g_vehicle_type_ub = arr_g_vehicle_type_ub[i];
		g_vehicle_variant_ub = arr_g_vehicle_variant_ub[i];
		Net_ComCtrl_Switch_RX_PDU(RX_ENABLE);
	}
}


TEST_F(testfixture, Net_ComCtrl_Switch_RX_PDU_rxenable4) {
	boolean RX_ENABLE = TRUE;
	g_vehicle_type_ub = GAC_A29Y_VEHICLE;
	g_vehicle_variant_ub = GAC_1R1V_VARIANT;
	Net_ComCtrl_Switch_RX_PDU(RX_ENABLE);
}

TEST_F(testfixture, Net_ComCtrl_Switch_RX_PDU_rxunable) {
	boolean RX_ENABLE = FALSE;
	g_vehicle_type_ub = GAC_A29Y_VEHICLE;
	g_vehicle_variant_ub = GAC_1R1V_VARIANT;
	Net_ComCtrl_Switch_RX_PDU(RX_ENABLE);
}

TEST_F(testfixture, Net_ComCtrl_Enable_Tx_1) {
	uint8 arr_g_vehicle_type_ub[4] = { GAC_A18V_VEHICLE,GAC_A18Y_VEHICLE,GAC_A29Y_VEHICLE,GAC_A21_VEHICLE };
	g_vehicle_variant_ub = GAC_1R1V_VARIANT;
	for (int i = 0; i < 4; i++) {
		g_vehicle_type_ub = arr_g_vehicle_type_ub[i];
		Net_ComCtrl_Enable_Tx();
	}


}

TEST_F(testfixture, Net_ComCtrl_Enable_Tx_2) {
	uint8 arr_g_vehicle_type_ub[4] = { GAC_A18V_VEHICLE + 10,GAC_A18Y_VEHICLE + 10,GAC_A29Y_VEHICLE + 10,GAC_A21_VEHICLE + 10 };
	g_vehicle_variant_ub = GAC_1R1V_VARIANT + 10;
	for (int i = 0; i < 4; i++) {
		g_vehicle_type_ub = arr_g_vehicle_type_ub[i];
		Net_ComCtrl_Enable_Tx();
	}

}

TEST_F(testfixture, Net_ComCtrl_Enable_Tx_3) {
	g_vehicle_variant_ub = GAC_5R1V1D_VARIANT;
	Net_ComCtrl_Enable_Tx();
}



TEST_F(testfixture, Net_ComCtrol_Disable_Tx_test1) {

	Net_ComCtrl_Disable_Tx();
}

TEST_F(testfixture, Net_GAC_Transfer_VFC2PUB_test) {

}

TEST_F(testfixture, Net_GAC_Transfer_VFC2PUB_VARIANT_1) {
	g_vehicle_type_ub = GAC_A29_2_VEHICLE;
	g_vehicle_variant_ub = GAC_5R1V1D_VARIANT;
	Net_GAC_Transfer_VFC2PUB_VARIANT();
}

TEST_F(testfixture, Net_GAC_Transfer_VFC2PUB_VARIANT_2) {
	g_vehicle_type_ub = GAC_A29_2_VEHICLE + 100;
	g_vehicle_variant_ub = GAC_5R1V1D_VARIANT + 100;
	Net_GAC_Transfer_VFC2PUB_VARIANT();
}
//TEST_F(a, Net_GAC_Transfer_VFC2PUB_test1) {
//	Net_GAC_Transfer_VFC2PUB();
//}
