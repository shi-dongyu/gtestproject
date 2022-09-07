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

#include "net_sim.hpp"

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


/*****************************************************************************/
/* Abstract class implementation declaration                                 */
/*****************************************************************************/
namespace daddy
{
namespace receiver
{
namespace interface
{
    class imp_test_dia_runnableUser_cust_CBase : public CBase
    {
    public:
        bool assign(const daddy::receiver::interface::CBase::PortDataBase_t * const, const daddy::receiver::interface::CBase::PortDataBase_t *&);
        bool isConnected() const;
        bool isReleased(const daddy::receiver::interface::CBase::PortDataBase_t *&);
        void connect();
        void disconnect();
    };
}
}
}

namespace daddy
{
namespace mempool
{
    class imp_test_dia_runnableUser_cust_CConstMemPoolBase : public CConstMemPoolBase
    {
    public:
        const void * getChunk() const;
    };
}
}

namespace net 
{
    class imp_test_dia_runnableUser_cust_CRbNetComMonitorBase : public CRbNetComMonitorBase
    {
    public:
        void update(uint16);
    };
}

namespace daddy
{
namespace runnable
{
    class imp_test_dia_runnableUser_cust_CRunnableBase : public CRunnableBase
    {
    public:
        void init();
        void run();
    };
}
}


namespace daddy
{
namespace adapter
{
    void MeasureDeliveredData(
        const void*       currentModifiedChunk,
        const void* const currentMempoolPtr,
        vfc::uint32_t     mempoolSize,
        vfc::uint32_t     measurementId )
    {
        vfc::nop(currentModifiedChunk);
        vfc::nop(currentMempoolPtr);
        vfc::nop(mempoolSize);
        vfc::nop(measurementId);
    }
}
}


/* Global Functions */
namespace daddy
{
namespace adapter
{
    void handleError(daddy::EErrorIDs ErrorID, const void * currentThis, daddy::EModuleIDs ModuleID, daddy::EApiIDs ApiID);
}
}


extern "C" uint32 rbMcu_SetLock_u32(uint32* p_LockVar_pu32, uint32 p_LockPattern_u32);
extern "C" void   rbMcu_ReleaseLock(uint32* p_LockVar_pu32);
extern "C" void   rbMcu_RequestSpinLock_u32(uint32* p_LockVar_pu32, uint32 p_LockPattern_u32);
extern "C" void   rbMcu_ReleaseSpinLock_u32(uint32* p_LockVar_pu32);

extern "C" Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

namespace dia
{
    CDiaRunnableCust* g_diaRunnableCust_p;
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
	virtual void SetUp() override
	{
	}
	virtual void TearDown() override
	{
	}
};

TEST_F(diaRunnableCustTest, FCWSystemStatus_ReadData_1)
{
	uint8 p_Data_pub[1] = {0};
	Std_ReturnType returnval = E_OK;
    returnval = FCWSystemStatus_ReadData(p_Data_pub);
	EXPECT_EQ(returnval, E_OK);

	TEST::Port_Config_ITF();
	dia::CDiaRunnableCust testObj;
	dia::g_diaRunnableCust_p = &testObj;
	// Config port for using netsim
	TEST::Port_Config(testObj);
	net::CNetTx_GAC_MRR_1 m_MRR_1_indata;
	m_MRR_1_indata.setMRR_FCWFaultSt(1);
	SETDATA(TEST::m_MRR_1_in, portData = m_MRR_1_indata;);
	returnval = FCWSystemStatus_ReadData(p_Data_pub);
	EXPECT_EQ(p_Data_pub[0], 1);
	EXPECT_EQ(returnval, E_OK);
	TEST::Port_DisConfig(testObj);
}


/* Stub for function daddy::adapter::handleError */
namespace daddy 
{
namespace adapter
{
    void handleError(daddy::EErrorIDs ErrorID, const void * currentThis, daddy::EModuleIDs ModuleID, daddy::EApiIDs ApiID)
    {
        // REGISTER_CALL("daddy::adapter::handleError(daddy::EErrorIDs, const void *, daddy::EModuleIDs, daddy::EApiIDs)");

        // IF_INSTANCE("default") {
        //     return;
        // }

        // LOG_SCRIPT_ERROR("Call instance not defined.");
        return;
    }
}
}


extern "C" uint32 rbMcu_SetLock_u32(uint32* m_value, uint32 value)
{
    if (daddy::adapter::AtomicValue::VALUE_UNSET == value)
    {
        value = 1;
    }

    uint32 ret = *m_value;
    *m_value   = value;

    return ret;
}

extern "C" void rbMcu_ReleaseLock(uint32* m_value)
{
    *m_value = daddy::adapter::AtomicValue::VALUE_UNSET;
}


/* Stub for function rbMcu_RequestSpinLock_u32 */
extern "C" void rbMcu_RequestSpinLock_u32(uint32* p_LockVar_pu32, uint32 p_LockPattern_u32)
{
//    REGISTER_CALL("rbMcu_RequestSpinLock_u32(uint32 *, uint32)");

//    IF_INSTANCE("default")
//    {
//       return;
//    }

//    LOG_SCRIPT_ERROR("Call instance not defined.");
}

/* Stub for function rbMcu_ReleaseSpinLock_u32 */
extern "C" void rbMcu_ReleaseSpinLock_u32(uint32* p_LockVar_pu32)
{
//    REGISTER_CALL("rbMcu_ReleaseSpinLock_u32(uint32 *)");

//    IF_INSTANCE("default")
//    {
//       return;
//    }

//    LOG_SCRIPT_ERROR("Call instance not defined.");
}


/* Stub for function Det_ReportRuntimeError */
extern "C" Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    // REGISTER_CALL("Det_ReportRuntimeError(uint16, uint8, uint8, uint8)");

    // IF_INSTANCE("default") {
    //     return CANTATA_DEFAULT_VALUE;
    // }

    // LOG_SCRIPT_ERROR("Call instance not defined.");
    return 0;
}
