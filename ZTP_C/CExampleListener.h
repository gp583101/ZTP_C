#ifndef _C_EXAMPLE_LISTENER_H_
#define _C_EXAMPLE_LISTENER_H_

#include <zoom_instant_sdk_api.h>
#include <zoom_instant_sdk_def.h>
#include <zoom_instant_sdk_platform.h>
#include <zoom_instant_sdk_interface.h>
#include <zoom_instant_sdk_delegate_interface.h>

BEGIN_ZOOM_INSTANT_SDK_NAMESPACE

class CExampleListener : IZoomInstantSDKDelegate
{
public:
    // ...
    CExampleListener();
    void onSessionJoin();
    void onSessionLeave();
    void onUserJoin(IZoomInstantSDKUserHelper* pUserHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList);
    void onUserLeave(IZoomInstantSDKUserHelper* pUserHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList);
    void onUserVideoStatusChanged(IZoomInstantSDKVideoHelper* pVideoHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList);
    void onUserAudioStatusChanged(IZoomInstantSDKAudioHelper* pAudioHelper, IInstantSDKVector<IZoomInstantSDKUser*>* userList);
    void onUserShareStatusChanged(IZoomInstantSDKShareHelper* pShareHelper, IZoomInstantSDKUser* pUser, ZoomInstantSDKShareStatus status);
    void onLiveStreamStatusChanged(IZoomInstantSDKLiveStreamHelper* pLiveStreamHelper, ZoomInstantSDKLiveStreamStatus status);
    void onChatNewMessageNotify(IZoomInstantSDKChatHelper* pChatHelper, IZoomInstantSDKChatMessage* messageItem);
    void onUserHostChanged(IZoomInstantSDKUserHelper* pUserHelper, IZoomInstantSDKUser* pUser);
    void onUserActiveAudioChanged(IZoomInstantSDKAudioHelper* pAudioHelper, IInstantSDKVector<IZoomInstantSDKUser*>* list);
    void onSessionNeedPassword(IZoomInstantSDKPasswordHandler* handler);
    void onError(ZoomInstantSDKErrors errorCode, int detailErrorCode);
    void onSessionPasswordWrong(IZoomInstantSDKPasswordHandler* handler);
    void onMixedAudioRawDataReceived(AudioRawData* data_);
    void onOneWayAudioRawDataReceived(AudioRawData* data_, IZoomInstantSDKUser* pUser);
    void onUserManagerChanged(IZoomInstantSDKUser* pUser);
    void onUserNameChanged(IZoomInstantSDKUser* pUser);
    int joinSession();
    int InitializeSDK();


//private:
    
    IZoomInstantSDK* m_pInstantSDK;
    // ...
};

END_ZOOM_INSTANT_SDK_NAMESPACE

#endif


