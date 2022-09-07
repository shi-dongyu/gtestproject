/*
 * net_sim.hpp
 *
 *  Created on: Oct 10, 2017
 *      Author: UYU1HC
 */

#include <daddy_receiverport.hpp>
#include <daddy_senderport.hpp>
#include <daddy_mempool.hpp>
#include "mempool/changeable/daddy_mempool_base.hpp"
#include "adapter_itf/daddy_monitor.hpp"
//TODO: please update header file related to your module
#include "dia_runnableUser_cust.hpp"

namespace TEST
{

//====================================================================//
//                        MACRO DEFINE
//====================================================================//
#define CREATE_RECEIVERPORT(portType, portName)                         \
/* Create receiver port */                                              \
daddy::TLatestReceiverPort<portType> portName##_ReceiverPort;           \
/* Create mempool */                                                    \
daddy::TMemPool<portType, 4> mempool_##portName;

#define CONNECT_RECEIVERPORT(portName, runnable)                        \
runnable.portName.connectMemPool(mempool_##portName, Objtype, TLatest); \
runnable.portName.connect(portName##_ReceiverPort, Objtype, TLatest);


#define CREATE_PROXY_SENDERPORT(portType, portName, RunnableClass, receiver_semantic)           \
/* Create sender port and its implementation port*/                                             \
daddy::TSenderPort<portType> portName##_SenderPort;                                             \
daddy::TSenderPortImpl<daddy::TSenderPort<portType, 0>, 1> portName##_SenderPort_Implementation;\
/* Create implementation port of receiver port */                                               \
daddy::receiver_semantic##SequentialReceiverPortImpl<daddy::receiver_semantic##ReceiverPort<portType, 0, std::remove_reference<decltype(RunnableClass::portName)>::type::Intervention_t> > portName##_ReceiverPort_Implementation; \
/* Create mempool */                                                                          \
daddy::TMemPool<portType, 4> mempool_##portName;

#define DISCONNECT_PROXY_SENDERPORT(portName, runnable) \
portName##_SenderPort.disconnect(runnable.portName);

#define CONNECT_PROXY_SENDERPORT_ITF(portName)          \
portName##_SenderPort.connectItf(portName##_SenderPort_Implementation);

#define CONNECT_PROXY_SENDERPORT(portName, runnable)                    \
runnable.portName.connectItf(portName##_ReceiverPort_Implementation);   \
portName##_SenderPort.connect(runnable.portName);                       \
if (!portName##_SenderPort.isMempoolConnected()) {                      \
portName##_SenderPort.connectMemPool(mempool_##portName);}

#define CREATE_PROXY_RECEIVERPORT(portType, portName)                                           \
/* Create receiver port and its implementation port*/                                           \
daddy::TLatestReceiverPort<portType> portName##_ReceiverPort;                                   \
daddy::TLatestSequentialReceiverPortImpl<daddy::TLatestReceiverPort<portType, 0, std::remove_reference<decltype(portName##_ReceiverPort)>::type::Intervention_t> > portName##_ReceiverPort_Implementation;\
/* Create implementation port of sender port*/                                                  \
daddy::TSenderPortImpl<daddy::TSenderPort<portType, 0>, 1> portName##_SenderPort_Implementation;\
/* Create mempool */                                                                            \
daddy::TMemPool<portType, 4> mempool_##portName;

//Adapt for LastX
//#define CREATE_PROXY_RECEIVERPORT(portType, portName)                                             \
///* Create receiver port and its implementation port*/                                             \
//daddy::TLastXReceiverPort<portType, 3> portName##_ReceiverPort;                                   \
//daddy::TLastXReceiverPortImpl<daddy::TLastXReceiverPort<portType, 3, 0, std::remove_reference<decltype(portName##_ReceiverPort)>::type::Intervention_t> > portName##_ReceiverPort_Implementation;\
///* Create implementation port of sender port*/                                                    \
//daddy::TSenderPortImpl<daddy::TSenderPort<portType, 0>, 1> portName##_SenderPort_Implementation;  \
///* Create mempool */                                                                              \
//daddy::TMemPool<portType, 4> mempool_##portName;

#define CONNECT_PROXY_RECEIVERPORT_ITF(portName)                            \
portName##_ReceiverPort.connectItf(portName##_ReceiverPort_Implementation); \

#define CONNECT_PROXY_RECEIVERPORT(portName, runnable)              \
runnable.portName.connectItf(portName##_SenderPort_Implementation); \
runnable.portName.connect(portName##_ReceiverPort);                 \
if (!runnable.portName.isMempoolConnected()) {                      \
runnable.portName.connectMemPool(mempool_##portName);}

#define DISCONNECT_PROXY_SENDERPORT(portName, runnable)             \
portName##_SenderPort.disconnect(runnable.portName);

#define DISCONNECT_PROXY_RECEIVERPORT(portName, runnable)           \
runnable.portName.disconnect(portName##_ReceiverPort);

#define SETDATA(port, value)                    	\
{                                                   \
    /*Reserve a chunk in the mempool*/              \
    auto& portData = port##_SenderPort.reserve();   \
                                                    \
    /*Prepare the data to be sent */                \
    value;                                          \
                                                    \
    /*Send the data*/                               \
    port##_SenderPort.deliver();                    \
}

#define GETDATA(port, value)                                		\
{                                                                   \
    /*Update the receiver ports to be able to get new data*/        \
    port##_ReceiverPort.update();                                   \
                                                                    \
    if(port##_ReceiverPort.hasData())                               \
    {                                                               \
        /*Read the data*/                                           \
        const auto* portData = port##_ReceiverPort.getData()[0];    \
        value;                                                      \
    }                                                               \
                                                                    \
    /*Do cleanup to recycle the mempool chunks*/                    \
    port##_ReceiverPort.cleanup();                                  \
}

//====================================================================//
// CREATE_PROXY_SENDERPORT(Per::DynCalibResponse, m_dynCalibResponsePort_in, dia::CDiaRunnableCust, TLatest);
// CREATE_PROXY_SENDERPORT(::Per::RPersPacket, m_perMountAnglePort_in, dia::CDiaRunnableCust, TLatest);
// CREATE_PROXY_SENDERPORT(Golf::Fct::StatesOutputInfo, m_RadarStatePort_in, dia::CDiaRunnableCust, TLatest);
// CREATE_PROXY_SENDERPORT(Per::DiaSppStalinOut, m_staticCalibrationPort_in, dia::CDiaRunnableCust, TLatest);
// daddy::TLatestReceiverPort<net::CNetTx_GAC_MRR_1> m_MRR_1_in;
CREATE_PROXY_SENDERPORT(net::CNetTx_GAC_MRR_1, m_MRR_1_in, dia::CDiaRunnableCust, TLatest)


// Receiver port definition
// CREATE_PROXY_RECEIVERPORT(Per::DynCalibTrigger, m_dynCalibTriggerPort_out);
// CREATE_PROXY_RECEIVERPORT(Per::DiaSppStalinIn, m_staticCalibrationTriggerPort_out);
// CREATE_PROXY_RECEIVERPORT(Ports::fsicd_x_CodingValue, m_codingValue_SenderPort);
// CREATE_PROXY_RECEIVERPORT(Ports::fsicd_x_DataSetDownload, m_dataSetDownload_SenderPort);
// CREATE_PROXY_RECEIVERPORT(Ports::fsicd_x_SDA_HMI_st, m_HmiState_SenderPort);


void Port_Config_ITF()
{
	// TODO: please update these macro to connect user port to its implement-port (if existed).
	// CONNECT_PROXY_RECEIVERPORT_ITF(port_name): connect user receiver port to its implement-port (_out).
	// CONNECT_PROXY_RECEIVERPORT_ITF(m_dynCalibTriggerPort_out);
	// CONNECT_PROXY_RECEIVERPORT_ITF(m_staticCalibrationTriggerPort_out);
	// CONNECT_PROXY_RECEIVERPORT_ITF(m_codingValue_SenderPort);
	// CONNECT_PROXY_RECEIVERPORT_ITF(m_dataSetDownload_SenderPort);
	// CONNECT_PROXY_RECEIVERPORT_ITF(m_HmiState_SenderPort);

	// CONNECT_PROXY_SENDERPORT_ITF(port_name): connect user sender port to its implement-port (_in).
	// CONNECT_PROXY_SENDERPORT_ITF(m_dynCalibResponsePort_in);
	// CONNECT_PROXY_SENDERPORT_ITF(m_perMountAnglePort_in);
	// CONNECT_PROXY_SENDERPORT_ITF(m_RadarStatePort_in);
	// CONNECT_PROXY_SENDERPORT_ITF(m_staticCalibrationPort_in);
	CONNECT_PROXY_SENDERPORT_ITF(m_MRR_1_in);
}


void Port_Config(dia::CDiaRunnableCust& testObj)
{
	// TODO: please update these macro to connect runnable port to its implement-port (if existed).
	// CONNECT_PROXY_RECEIVERPORT(port_name, runnable_object): connect runnable sender port to its implement-port, to user receiver port and to mempool.
	// CONNECT_PROXY_RECEIVERPORT(m_dynCalibTriggerPort_out, testObj);
	// CONNECT_PROXY_RECEIVERPORT(m_staticCalibrationTriggerPort_out, testObj);
	// CONNECT_PROXY_RECEIVERPORT(m_codingValue_SenderPort, testObj);
	// CONNECT_PROXY_RECEIVERPORT(m_dataSetDownload_SenderPort, testObj);
	// CONNECT_PROXY_RECEIVERPORT(m_HmiState_SenderPort, testObj);
	// CONNECT_PROXY_SENDERPORT(port_name, runnable_object): connect runnable receiver port to its implement-port, and connect user sender port to relevant runnable receiver port and mempool.
	// CONNECT_PROXY_SENDERPORT(m_dynCalibResponsePort_in, testObj);
	// CONNECT_PROXY_SENDERPORT(m_perMountAnglePort_in, testObj);
	// CONNECT_PROXY_SENDERPORT(m_RadarStatePort_in, testObj);
	// CONNECT_PROXY_SENDERPORT(m_staticCalibrationPort_in, testObj);
	CONNECT_PROXY_SENDERPORT(m_MRR_1_in, testObj);

}


void Port_DisConfig(dia::CDiaRunnableCust& testObj)
{
	// TODO: please update these macro to disconnect runnable port with its implement-port (if existed).
	// DISCONNECT_PROXY_RECEIVERPORT(port_name, runnable_object): disconnect runnable sender port with its implement-port.
	// DISCONNECT_PROXY_RECEIVERPORT(m_dynCalibTriggerPort_out, testObj);
	// DISCONNECT_PROXY_RECEIVERPORT(m_staticCalibrationTriggerPort_out, testObj);
	// DISCONNECT_PROXY_RECEIVERPORT(m_codingValue_SenderPort, testObj);
	// DISCONNECT_PROXY_RECEIVERPORT(m_dataSetDownload_SenderPort, testObj);
	// DISCONNECT_PROXY_RECEIVERPORT(m_HmiState_SenderPort, testObj);
	// DISCONNECT_PROXY_SENDERPORT(port_name, runnable_object): disconnect runnable receiver port with its implement-port.
	// DISCONNECT_PROXY_SENDERPORT(m_dynCalibResponsePort_in, testObj);
	// DISCONNECT_PROXY_SENDERPORT(m_perMountAnglePort_in, testObj);
	// DISCONNECT_PROXY_SENDERPORT(m_RadarStatePort_in, testObj);
	// DISCONNECT_PROXY_SENDERPORT(m_staticCalibrationPort_in, testObj);
	DISCONNECT_PROXY_SENDERPORT(m_MRR_1_in, testObj);
}

} // End namespace TEST
