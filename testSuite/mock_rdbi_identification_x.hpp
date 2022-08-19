#ifndef MOCK_RDBI_IDENTIFICATION
#define MOCK_RDBI_IDENTIFICATION

#include "gtest/gtest.h"
#include "gmock/gmock.h"

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


class CMocks
{
public:
    CMocks();
    ~CMocks();
    MOCK_METHOD1(Dcm_GetSesCtrlType,Std_ReturnType(Dcm_SesCtrlType*));
    MOCK_METHOD1(RbSecu_BJEV_GetLifeCycle,Std_ReturnType(uint8*));
    MOCK_METHOD3(PDA_GetSubBlockHeaderAddress_U8,uint8(uint32,uint32,void*));
};

#endif // end of MOCK_RDBI_IDENTIFICATION
