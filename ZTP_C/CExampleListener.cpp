
#include <atlstr.h>
#include <iostream>
#include "CExampleListener.h"


BEGIN_ZOOM_INSTANT_SDK_NAMESPACE

CExampleListener::CExampleListener()
{
	InitializeSDK();
	m_pInstantSDK->addListener(this);
}



void CExampleListener::onError(ZoomInstantSDKErrors errorCode, int detailErrorCode)
{
	CString info;

	switch (errorCode)
	{
	case ZoomInstantSDKErrors_Meeting_Disconnecting:
		info.Format(_T("onError(): Disconnecting from session, Error:%d DetailCode: %d"), errorCode, detailErrorCode);
		break;
	case ZoomInstantSDKErrors_Meeting_Reconnecting:
		info.Format(_T("onError(): Reconnecting to session, Error:%d DetailCode: %d"), errorCode, detailErrorCode);
		break;
	case ZoomInstantSDKErrors_Meeting_Join_Failed:
		info.Format(_T("onError(): Failed to join session, Error:%d DetailCode: %d"), errorCode, detailErrorCode);
		break;
	default:
		info.Format(_T("onError(): Error:%d DetailCode: %d"), errorCode, detailErrorCode);
		break;
	}

	std::cout << info.GetString();
}

void CExampleListener::onSessionJoin()
{
	// You have successfully joined the session.
	std::cout << "onSessionJoin\n";
}

void CExampleListener::onSessionLeave()
{
	// You have successfully left the session.
	std::cout << "onSessionLeave\n";
}

void CExampleListener::onUserJoin(IZoomInstantSDKUserHelper* pUserHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList)
{
	CString strInfo;
	IZoomInstantSDKUser* pUser;
	int count = userList->GetCount();

	for (int i = 0; i < count; i++)
	{
		pUser = userList->GetItem(i);
		if (!pUser) continue;

		strInfo.Format(_T("A user joined the session: id=%s, name=%s"), pUser->getUserId(), pUser->getUserName());
	}
	std::cout << strInfo.GetString();
}


void CExampleListener::onUserLeave(IZoomInstantSDKUserHelper* pUserHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList)
{
	CString strInfo;
	IZoomInstantSDKUser* pUser;
	int count = userList->GetCount();

	for (int i = 0; i < count; i++)
	{
		pUser = userList->GetItem(i);
		if (!pUser) continue;

		strInfo.Format(_T("A user left the session: id=%s, name=%s"), pUser->getUserId(), pUser->getUserName());
	}
	std::cout << strInfo.GetString();
}

void CExampleListener::onUserVideoStatusChanged(IZoomInstantSDKVideoHelper* pVideoHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList)
{
	CString strInfo;
	IZoomInstantSDKUser* pUser;
	int count = userList->GetCount();

	for (int i = 0; i < count; i++)
	{
		pUser = userList->GetItem(i);
		strInfo.Format(_T("A user's video status changed: userid=%s, name=%s, status=%s"), pUser->getUserId(), pUser->getUserName(), pUser->getVideoStatus());
	}

	std::cout << strInfo.GetString();
}

void CExampleListener::onUserAudioStatusChanged(IZoomInstantSDKAudioHelper* pAudioHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList)
{
	CString strInfo;
	IZoomInstantSDKUser* pUser;
	int count = userList->GetCount();

	for (int i = 0; i < count; i++)
	{
		pUser = userList->GetItem(i);
		strInfo.Format(_T("A user's audio status changed: userid=%s, name=%s, status=%s"), pUser->getUserId(), pUser->getUserName(), pUser->getAudioStatus());
	}

	std::cout << strInfo.GetString();
}


void CExampleListener::onUserShareStatusChanged(IZoomInstantSDKShareHelper* pShareHelper, IZoomInstantSDKUser* pUser, ZoomInstantSDKShareStatus status)
{
	CString strInfo;
	const zchar_t* userId = pUser->getUserId();

	switch (status)
	{
	case ZoomInstantSDKShareStatus_None:
		strInfo.Format(_T("User's share status changed to None: userid=%s, name=%s"), userId, pUser->getUserName());
		break;
	case ZoomInstantSDKShareStatus_Pause:
		strInfo.Format(_T("User paused sharing: userid=%s, name=%s"), userId, pUser->getUserName());
		break;
	case ZoomInstantSDKShareStatus_Resume:
		strInfo.Format(_T("User resumed sharing: userid=%s, name=%s"), userId, pUser->getUserName());
		break;
	case ZoomInstantSDKShareStatus_Start:
		strInfo.Format(_T("User began sharing: userid=%s, name=%s"), userId, pUser->getUserName());
		break;
	case ZoomInstantSDKShareStatus_Stop:
		strInfo.Format(_T("User stopped sharing: userid=%s, name=%s"), userId, pUser->getUserName());
		break;
	}

	std::cout << strInfo.GetString();
}


void CExampleListener::onLiveStreamStatusChanged(IZoomInstantSDKLiveStreamHelper* pLiveStreamHelper, ZoomInstantSDKLiveStreamStatus status)
{
	CString strInfo;
	switch (status)
	{
	case ZoomInstantSDKLiveStreamStatus_Connecting:
		strInfo = _T("Live stream is connecting.");
		break;
	case ZoomInstantSDKLiveStreamStatus_Ended:
		strInfo = _T("Live stream has ended.");
		break;
	case ZoomInstantSDKLiveStreamStatus_FailedTimeout:
		strInfo = _T("Live stream failed: Timeout.");
		break;
	case ZoomInstantSDKLiveStreamStatus_InProgress:
		strInfo = _T("Live stream is in progress.");
		break;
	case ZoomInstantSDKLiveStreamStatus_StartFailed:
		strInfo = _T("Live stream failed to start.");
		break;
	case ZoomInstantSDKLiveStreamStatus_None:
		strInfo = _T("Live stream status changed to none.");
		break;
	}

	std::cout << strInfo.GetString();
}


void CExampleListener::onChatNewMessageNotify(IZoomInstantSDKChatHelper* pChatHelper, IZoomInstantSDKChatMessage* messageItem)
{
#ifdef __ENABLE_THIS_CODE__
	if (!messageItem)
		return;

	CString strInfo;
	const zchar_t* szMessageContent = messageItem->getContent();
	IZoomInstantSDKUser* pRecievingUser = messageItem->getReceiveUser();
	IZoomInstantSDKUser* pSendingUser = messageItem->getSendUser();

	// Check if this is a public message. If false, this is a private message.
	bool bIsChatToAll = messageItem->isChatToAll();
	// Check if this message was sent from the local user.
	bool bIsSelfSend = messageItem->isSelfSend();

	time_t time = messageItem->getTimeStamp();

	if (!pSendUser)
		return;

	strInfo.Format(_T("New message from %s to %s  %s"), pSendUser->getUserName(), pRcvUser->getUserName(), szContent);
	std::cout << strInfo.GetString();
#endif 
}

void CExampleListener::onUserHostChanged(IZoomInstantSDKUserHelper* pUserHelper, IZoomInstantSDKUser* pUser)
{
	CString strInfo;

	const zchar_t* newHostID = pUser->getUserId();
	strInfo.Format(_T("The host of the session is now: userid=%s, name=%s"), newHostID, pUser->getUserName());
	std::cout << strInfo.GetString();
}

// onUserActiveAudioChanged is different from onUserAudioStatusChanged. onUserActiveAudioChanged is called when a given user's audio changes, while onUserAudioStatusChanged is called when the user's audio status changes. For example, if the user is unmuted and is using their device's microphone, this callback will be triggered whenever their microphone detects a noise.
void CExampleListener::onUserActiveAudioChanged(IZoomInstantSDKAudioHelper* pAudioHelper, IInstantSDKVector<IZoomInstantSDKUser*>* list)
{
	CString strInfo;
	IZoomInstantSDKUser* pUser;
	int count = list->GetCount();

	for (int i = 0; i < count; i++)
	{
		pUser = list->GetItem(i);
		strInfo.Format(_T("User's audio activity changed: userid=%s, name=%s"), pUser->getUserId(), pUser->getUserName());
	}

	std::cout << strInfo.GetString();
}


void CExampleListener::onSessionNeedPassword(IZoomInstantSDKPasswordHandler* handler)
{
#ifdef __ENABLE_THIS_CODE__
	// Store password handler. 
	m_pPasswordHandler = handler;

	// When ready, call inputSesstionPassword on the handler.
	if (m_pPasswordHandler)
	{
		CString strPassword;
		m_pPswHandler->inputSessionPassword(strPassword.GetBuffer());
	}

	// Or ignore the password request and leave the session with leaveSessionIgnorePassword.
   /* if (m_pPasswordHandler)
	{
		m_pPasswordHandler->leaveSessionIgnorePassword();
	}*/
#endif 
}



void CExampleListener::onSessionPasswordWrong(IZoomInstantSDKPasswordHandler* handler)
{
#ifdef __ENABLE_THIS_CODE__
	// Store password handler. 
	m_pPasswordHandler = handler;

	// When ready, call inputSesstionPassword on the handler.
	if (m_pPasswordHandler)
	{
		CString strPassword;
		m_pPswHandler->inputSessionPassword(strPassword.GetBuffer());
	}

	// Or ignore the password request and leave the session with leaveSessionIgnorePassword.
	/* if (m_pPasswordHandler)
	 {
		 m_pPasswordHandler->leaveSessionIgnorePassword();
	 }*/

#endif 

}

void CExampleListener::onMixedAudioRawDataReceived(AudioRawData* data_)
{

}

void CExampleListener::onOneWayAudioRawDataReceived(AudioRawData* data_, IZoomInstantSDKUser* pUser)
{

}


void CExampleListener::onUserManagerChanged(IZoomInstantSDKUser* pUser)
{

}
void CExampleListener::onUserNameChanged(IZoomInstantSDKUser* pUser)
{

}


int CExampleListener::joinSession()
{
	ZoomInstantSDKSessionContext sessionContext;
	sessionContext.sessionName = L"Sessionname15081977";
	sessionContext.sessionPassword = L"Sessionpassword";
	sessionContext.userName = L"Username";

	// JWT for this session.
	sessionContext.token = L"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhcHBLZXkiOiJ1SlZ5ZGNOZWhpSVdQRUVIdGJ2c1dCT1FJSDBFbGMyaE1jVnIiLCJ2ZXJzaW9uIjoxLCJ1c2VyX2lkZW50aXR5IjoiQUFBVDE4NzYiLCJpYXQiOjE2MjIzOTI1NTMsImV4cCI6MTYyMjQ3ODk1MywidHBjIjoiU2Vzc2lvbm5hbWUxNTA4MTk3NyJ9.d2-WoQFhaEpBa9vX69A_hkfKZMCnCdOCarMgLMT6OPo";

	// Video and audio options.
	sessionContext.videoOption.localVideoOn = true;
	sessionContext.audioOption.connect = true;
	sessionContext.audioOption.mute = false;

	IZoomInstantSDKSession* pSession = m_pInstantSDK->joinSession(sessionContext);
	if (!pSession)
	{
		//CString cstrInfo;
		//cstrInfo.Format(_T("Failed to join session"));
		std::cout << "Failed to join session!\n";
		return -1;
	}
	else
	{
		//CString cstrInfo;
		//cstrInfo.Format(_T("Joined session successfully."));
		std::cout << "Joined session successfully.!\n";
		return 0;
	}
}

int CExampleListener::InitializeSDK()
{

	// Create an instance of ZoomInstantSDKInitParams and specify the initialization parameters.
	ZoomInstantSDKInitParams initParams;

	// Set network domain
	initParams.domain = L"https://zoom.us";
	// Set raw data memory mode
	initParams.audioRawDataMemoryMode = ZoomInstantSDKRawDataMemoryModeStack;
	initParams.videoRawDataMemoryMode = ZoomInstantSDKRawDataMemoryModeStack;
	initParams.shareRawDataMemoryMode = ZoomInstantSDKRawDataMemoryModeStack;
	// Set to enable indirect raw data
	initParams.enableIndirectRawdata = false;
	// Set to enable SDK logging
	initParams.enableLog = true;
	// Set to specify the prefix of the log file name
	initParams.logFilePrefix = L"prefix";

	//The SDK requires initialization before you can call any other functions.
	//To initialize, create an instance of IZoomInstantSDK using CreateZoomInstantSDKObj().

	m_pInstantSDK = CreateZoomInstantSDKObj();


	//Call the initialize function on the IZoomInstantSDK objectand pass in the ZoomInstantSDKInitParams object.
	int returnVal = m_pInstantSDK->initialize(initParams);
	if (returnVal != ZoomInstantSDKErrors_Success)
	{
		// Call to initialize failed. Inspect returnVal to see error.
		std::cout << "Call to initialize failed: " << returnVal ;
		std::cout << "https://marketplace.zoom.us/docs/sdk/video/windows/error-codes";
		return returnVal;
	}
	std::cout << "InitializeSDK: Success!\n" ;


	return 0;

}




END_ZOOM_INSTANT_SDK_NAMESPACE
