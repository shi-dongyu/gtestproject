#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "mock_rdbi_identification_x.hpp"

extern "C"
{
#include <sw_version_cfg.h>
#include <BoschDataBlock_Table.h>
#include <ECUMemoryLayout.h>
#include <string.h> // memcpy
#include <NvM.h>
#include <rbPda.h>
#include <seca_appl_x_pub.h>
#include "dsc_appl_x.h"
#include "rbSec_Lifecycle_pub.h"
#include "dc_interfaces/dc_types/define.h"
}

#include <rdbi_identification_x.hpp>
#include <wdbi_identification_x.hpp>
#include <wdbi_codingdata_x.hpp>
#include <dia_static_alignment.hpp>

#include <daddy_mempool.hpp>
#include <daddy_senderport.hpp>
#include <dia_runnableUser_cust.hpp>

using namespace testing;
using namespace dia;

NvM_Bldr_ProgrammingDate_t NvM_Bldr_ProgrammingDate;
NvM_Bldr_SparePartNumber_t NvM_Bldr_SparePartNumber;
NVM_DIA_X_AlignmentData_st NVM_dia_x_Nvm_AlignmentData_st;
NvM_Bldr_SystemName_t NvM_Bldr_SystemName;
NvM_Bldr_ReprogAttemptCounter_t NVM_Bldr_ReprogAttemptCounter;
NvM_Bldr_KitAsssemblePartNumber_t NvM_Bldr_KitAsssemblePartNumber;
NVM_dia_x_wdbi_coding_value_t NVM_dia_x_wdbi_coding_value_st;
NvM_Bldr_ReprogCounter_t NvM_Bldr_ReprogCounter;
NVM_dia_x_wdbi_identification_value_t NVM_dia_x_wdbi_identification_value_st;
NvM_Bldr_SoftwareFingerPrint_t NVM_Bldr_SoftwareFingerPrint;
NvM_Bldr_BootSoftwareIdentificationNumber_t Dia_AppSoftwareIdentificationNumber;
NvM_Bldr_BootSoftwareIdentificationNumber_t Dia_SoftwareIdentificationNumber;
NvM_Bldr_BootSoftwareIdentificationNumber_t NVM_Bldr_BootSoftwareIdentificationNumber;
NvM_Bldr_BootSoftwareIdentificationNumber_t Dia_HardwareIdentificationNumber;
uint8 Dia_VehicleType_uint8;


//////////////////////卡车工程写法///////////////////////////

namespace dia
{
    CDiaRunnableCust* g_diaRunnableCust_p ;// = &dia_CDiarunnableCust_obj;
	CDiaRunnableCust dia_CDiarunnableCust_obj;
}

// Implement the metholds that defines in dia_runnableUser_cust.hpp
CDiaRunnableCust::CDiaRunnableCust(){g_diaRunnableCust_p = this;}
void dia::CDiaRunnableCust::initUser(){}
void dia::CDiaRunnableCust::runUser(){}
void dia::CDiaRunnableCust::init(){}
void dia::CDiaRunnableCust::run(){}

// Implement the metholds that defines in rbDia_RunnableProductline.hpp
rbDia::CDiaRunnablePl::CDiaRunnablePl(){}
void rbDia::CDiaRunnablePl::init_user(){}
void rbDia::CDiaRunnablePl::run_user(){}
void rbDia::CDiaRunnablePl::updatePorts(){}
void rbDia::CDiaRunnablePl::cleanupPorts(){}

// Implement the metholds that defines in rbDia_Runnable.hpp
rbDia::CDiaRunnable::CDiaRunnable(){}
void rbDia::CDiaRunnable::init(){}
void rbDia::CDiaRunnable::run(){}
void rbDia::CDiaRunnable::init_user(){}
void rbDia::CDiaRunnable::run_user(){}
void rbDia::CDiaRunnable::updatePorts(){}
void rbDia::CDiaRunnable::cleanupPorts(){}


class diaRunnableCustTest : public Test
{
public:
	daddy::TSenderPort<net::CNetTx_GAC_MRR_1> m_dummy_MRR_1_out;
    daddy::TMemPool<net::CNetTx_GAC_MRR_1,10> m_dummy_MRR_1_Mempool{};
    net::CNetTx_GAC_MRR_1*                    m_MRR_1{};	// Why define this?

public:
	virtual void SetUp() override
	{
		m_dummy_MRR_1_out.connectMemPool(m_dummy_MRR_1_Mempool);
		m_dummy_MRR_1_out.connect(g_diaRunnableCust_p->m_MRR_1_in);
	}
	virtual void TearDown() override
	{
		m_dummy_MRR_1_out.disconnect(g_diaRunnableCust_p->m_MRR_1_in);
	}
};

TEST_F(diaRunnableCustTest, FCWSystemStatus_ReadData_1)
{
	uint8 p_Data_pub[1] = {0};
	Std_ReturnType returnval = E_OK;
    returnval = FCWSystemStatus_ReadData(p_Data_pub);
	EXPECT_EQ(returnval, E_OK);
}

