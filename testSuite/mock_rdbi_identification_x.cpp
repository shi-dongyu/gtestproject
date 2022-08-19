#include "mock_rdbi_identification_x.hpp"
#include <functional>

static std::function<Std_ReturnType(Dcm_SesCtrlType*)> _Dcm_GetSesCtrlType;
static std::function<Std_ReturnType(uint8*)> _RbSecu_BJEV_GetLifeCycle;
static std::function<uint8(uint32,uint32,void*)> _PDA_GetSubBlockHeaderAddress_U8;

CMocks::CMocks()
{
    assert(!_Dcm_GetSesCtrlType);
    _Dcm_GetSesCtrlType = [this](Dcm_SesCtrlType* SesCtrlType){return Dcm_GetSesCtrlType(SesCtrlType);};

    assert(!_RbSecu_BJEV_GetLifeCycle);
    _RbSecu_BJEV_GetLifeCycle = [this](uint8* Data){return RbSecu_BJEV_GetLifeCycle(Data);};

    assert(!_PDA_GetSubBlockHeaderAddress_U8);
    _PDA_GetSubBlockHeaderAddress_U8 = [this](uint32 f_blockID_u32, uint32 f_SubBlockID_u32, void *f_BlockPrt_pv){return PDA_GetSubBlockHeaderAddress_U8(f_blockID_u32,f_SubBlockID_u32,f_BlockPrt_pv);};
}

CMocks::~CMocks()
{
    _Dcm_GetSesCtrlType = {};
    _RbSecu_BJEV_GetLifeCycle = {};
    _PDA_GetSubBlockHeaderAddress_U8 = {};
}


Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType * SesCtrlType)
{
    return _Dcm_GetSesCtrlType(SesCtrlType);
}

Std_ReturnType RbSecu_BJEV_GetLifeCycle(uint8* Data)
{
    return _RbSecu_BJEV_GetLifeCycle(Data);
}

uint8 PDA_GetSubBlockHeaderAddress_U8(uint32 f_blockID_u32, uint32 f_SubBlockID_u32, void *f_BlockPrt_pv)
{
    return _PDA_GetSubBlockHeaderAddress_U8(f_blockID_u32, f_SubBlockID_u32, f_BlockPrt_pv);
}
