#ifndef _SDK_MINIMAL_CLIENT_HPP_
#define _SDK_MINIMAL_CLIENT_HPP_

//#include "../PlatformSpecific/ClientPlatformSpecific.hpp"
#include "../SDKClient_Windows/PlatformSpecific/ClientPlatformSpecific.hpp"
#include "ManusSDK/include/ManusSDK.h"
#include <mutex>
#include <vector>
//ZMQ
#include <zmq.hpp>
//ZMQ

 /// @brief The type of connection to core.
enum class ConnectionType : int
{
	ConnectionType_Invalid = 0,
	ConnectionType_Integrated,
	ConnectionType_Local,
	ConnectionType_Remote,
	ClientState_MAX_CLIENT_STATE_SIZE
};

/// @brief Values that can be returned by this application.
enum class ClientReturnCode : int
{
	ClientReturnCode_Success = 0,
	ClientReturnCode_FailedPlatformSpecificInitialization,
	ClientReturnCode_FailedToResizeWindow,
	ClientReturnCode_FailedToInitialize,
	ClientReturnCode_FailedToFindHosts,
	ClientReturnCode_FailedToConnect,
	ClientReturnCode_UnrecognizedStateEncountered,
	ClientReturnCode_FailedToShutDownSDK,
	ClientReturnCode_FailedPlatformSpecificShutdown,
	ClientReturnCode_FailedToRestart,
	ClientReturnCode_FailedWrongTimeToGetData,

	ClientReturnCode_MAX_CLIENT_RETURN_CODE_SIZE
};

/// @brief Used to store the information about the skeleton data coming from the estimation system in Core.
class ClientRawSkeleton
{
public:
	RawSkeletonInfo info;
	std::vector<SkeletonNode> nodes;
};

/// @brief Used to store all the skeleton data coming from the estimation system in Core.
class ClientRawSkeletonCollection
{
public:
	std::vector<ClientRawSkeleton> skeletons;
};

class SDKMinimalClient : public SDKClientPlatformSpecific
{
public:
	SDKMinimalClient();
	~SDKMinimalClient();
	ClientReturnCode Initialize();
	ClientReturnCode InitializeSDK();
	ClientReturnCode ShutDown();
	ClientReturnCode RegisterAllCallbacks();
	ClientReturnCode RegisterRawSkeletonStreamCallback();
	ClientReturnCode RegisterErgonomicStreamCallback();
	void Run();

	void PrintRawSkeletonNodeInfo();
	static bool isRawErgoCombined;
	static void OnRawSkeletonStreamCallback(const SkeletonStreamInfo* const p_RawSkeletonStreamInfo);
	static void OnErgonomicsCallback(const ErgonomicsStream* const p_Ergo);
	

protected:

	ClientReturnCode Connect();

	static SDKMinimalClient* s_Instance;
	bool m_Running = true;
	bool m_PrintedNodeInfo = false;
	
	uint32_t m_FirstLeftGloveID = 1434490787;
	uint32_t m_FirstRightGloveID = 3778947570;

	ErgonomicsData m_LeftGloveErgoData;
	ErgonomicsData m_RightGloveErgoData;
	ManusTimestampInfo m_ErgoTimestampInfo;

	ConnectionType m_ConnectionType = ConnectionType::ConnectionType_Invalid;

	std::mutex m_RawSkeletonMutex;
	ClientRawSkeletonCollection* m_NextRawSkeleton = nullptr;
	ClientRawSkeletonCollection* m_RawSkeleton = nullptr;

	uint32_t m_FrameCounter = 0;

	//ZMQ
	char char_buf[512];
	zmq::context_t ctx;      // Context for ZMQ
	zmq::socket_t sockRaw;      // Socket for ZMQ for raw skeleton data
	zmq::socket_t sockErgo;      // Socket for ZMQ for ergonomic data
	//ZMQ
};
#endif
