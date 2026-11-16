
#pragma once
//============================================================================
// Copyright (C) 2023 Brett R. Jones 
//
// Code copyrighted by Brett R. Jones is under dual license similar to Ruby's license
// See file COPYING and LEGAL in root of the No Limit Connect project
//
// bjones.engineer@gmail.com
// https://nolimitconnect.org
//============================================================================

enum EMyIcons
{
	eMyIconNone			= 0,		// no icon to show
	eMyIconUnknown,					// Icon with question mark
	eMyIconApp,
    eMyIconAvatarImage,
	
    eMyIconNotifyJoinOverlay,		// joined overlay
    eMyIconNotifyOnlineOverlay,		// online dot
	eMyIconNotifyDirectConnectOverlay, // direct connect overlay
	eMyIconNotifyInGroupOverlay,	// in group overlay
    eMyIconNotifyOfferOverlay,		// hand offer overlay
    eMyIconNotifyForbbidenOverlay,	// permission denied
	eMyIconNotifyAdminOverlay,		// is host administrator

	eMyIconEyeOverlay,				// eye overlay
	eMyIconGlobeOverlay,			// is random connect person globe in upper left
	eMyIconNlcFavoriteOverlay,		// nlc preferred host or user overlay

	eMyIconHashtag,
    eMyIconInformation,
	eMyIconInfoOffer,
    eMyIconPeople,
    eMyIconSettingsGear,
	eMyIconFileServer,

    eMyIconEyeAll,
	eMyIconEyeAnnouncedChatRooms,
	eMyIconEyeAnnouncedGroups,
	eMyIconEyeAnnouncedRandomConnect,
    eMyIconEyeChatRoom,
    eMyIconEyeFriends,
    eMyIconEyeGroup,
    eMyIconEyeHide,
    eMyIconEyeRandomConnect,
    eMyIconEyeShow,

    eMyIconSearch,
    eMyIconSearchJoinGroup,
    eMyIconSearchJoinChatRoom,
    eMyIconSearchJoinRandomConnect,
    eMyIconSearchPerson,
    eMyIconSearchHeart,
    eMyIconSearchWebCam,
    eMyIconSearchImage,
    eMyIconSearchStoryboard,
    eMyIconSearchFolder,


	eMyIconAdministrator,
	eMyIconFriend,
	eMyIconGuest,
	eMyIconAnonymous,
	eMyIconIgnored,

	eMyIconFriendJoined,

    eMyIconChatRoomClient,
    eMyIconGroupClient,
    eMyIconRandomConnectClient,
    eMyIconClientWebCam,

	eMyIconProfile,
	eMyIconProfileLocked,
	eMyIconProfileDisabled,
	eMyIconProfileIgnored,

	eMyIconWebCamServerLocked,
	eMyIconWebCamServerDisabled,
	eMyIconWebCamServerIgnored,

	eMyIconFolder,

	eMyIconMultiSession,
	eMyIconMultiSessionLocked,
	eMyIconMultiSessionDisabled,
	eMyIconMultiSessionIgnored,

	eMyIconVoicePhoneCancel,
	eMyIconVoicePhoneNormal,
	eMyIconVoicePhoneDisabled,
	eMyIconVoicePhoneLocked,
	eMyIconVoicePhoneIgnored,

	eMyIconPushToTalkOff,
	eMyIconPushToTalkOn,
	eMyIconPushToTalkDisabled,
	eMyIconPushToTalkLocked,
	eMyIconPushToTalkIgnored,

	eMyIconVideoPhoneCancel,
	eMyIconVideoPhoneNormal,
	eMyIconVideoPhoneDisabled,
	eMyIconVideoPhoneLocked,
	eMyIconVideoPhoneIgnored,

	eMyIconTruthOrDareCancel,
	eMyIconTruthOrDareNormal,
	eMyIconTruthOrDareDisabled,
	eMyIconTruthOrDareLocked,
	eMyIconTruthOrDareIgnored,

	eMyIconPermissions,
    eMyIconKeyEnabled,

	eMyIconNotifyStarWhite,
	eMyIconNotifyStarGreen,

	eMyIconRefresh,

	eMyIconPhoto,
	eMyIconMusic,
	eMyIconVideo,
	eMyIconDocument,
	eMyIconArcOrIso,
	eMyIconOther,


	eMyIconStoryBoardNormal,
	eMyIconStoryBoardDisabled,
	eMyIconStoryBoardLocked,
	eMyIconStoryBoardIgnored,

	eMyIconMicrophoneOff,
	eMyIconMicrophoneOn,


	eMyIconDebug,

	eMyIconShareFilesDisabled,
	eMyIconShareFilesNormal,
	eMyIconShareFilesCancel,

	eMyIconPauseNormal,

	eMyIconPlayNormal,

	eMyIconRejectRedX,
	eMyIconAcceptCheckMark,

    eMyIconCancelRecord,
	eMyIconTrash,

	eMyIconShredderNormal,

	eMyIconFileDownloadCancel,
	eMyIconFileDownloadNormal,

	eMyIconSendFileDisabled,
	eMyIconSendFileCancel,
	eMyIconSendFileNormal,
	eMyIconSendFileLocked,
	eMyIconSendFileIgnored,

	eMyIconRecordMovieNormal,

	eMyIconRecordMotionNormal,

	eMyIconMotionAlarmRed,
	eMyIconMotionAlarmWhite,

	eMyIconAcceptNormal,
	eMyIconAcceptDisabled,
	eMyIconCancelNormal,

	eMyIconSendArrowNormal,
	eMyIconSendArrowCancel,

	eMyIconCameraNormal,
	eMyIconCameraCancel,

	eMyIconCamcorderNormal,
	eMyIconCamcorderCancel,

	eMyIconSelectCameraNormal,

	eMyIconSpeakerOn,
	eMyIconSpeakerOff,



	eMyIconNotepadNormal,

	eMyIconGalleryNormal,


	eMyIconFaceSelectNormal,

	eMyIconCamPreviewNormal,
	eMyIconCamPreviewCancelNormal,

	eMyIconCamRotateNormal,
	eMyIconCamSetupNormal,
	eMyIconCamSelectNormal,

	eMyIconImageRotateNormal,

	eMyIconFileBrowseNormal,

	eMyIconMoveUpDirNormal,

	eMyIconLibraryNormal,
	eMyIconLibraryCancel,


	eMyIconMenuNormal,
	eMyIconMenuDisabled,




	//=== title bar icons ===//
	eMyIconPowerOff,
	eMyIconHome,
	eMyIconMenu,
	eMyIconBack,

	//=== bottom bar icons ===//
	eMyIconMediaStop,
	eMyIconArrowLeft,
    eMyIconWindowExpand,
    eMyIconWindowShrink,

    //=== applet icons ===//
    eMyIconUserIdentity,

    eMyIconMessenger,



    eMyIconTheme,

    eMyIconNetworkKey,
    eMyIconNetworkSettings,
    eMyIconSearchRandomConnect,


    // built in plugin options
    eMyIconCamStreamProvider,
    eMyIconNlcStation,

    eMyIconShareServices,

    eMyIconServiceAvatarImage,
    eMyIconServiceChatRoom,
    eMyIconServiceConnectionTest,
    eMyIconServiceHostGroup,
    eMyIconServiceHostNetwork,
    eMyIconServiceShareAboutMe,
    eMyIconServiceShareFiles,
    eMyIconServiceShareStoryboard,
    eMyIconServiceShareWebCam,
    eMyIconServiceRandomConnect, 

    eMyIconSettingsAboutMe,
    eMyIconSettingsAvatarImage,
    eMyIconSettingsChatRoom,
    eMyIconSettingsConnectionTest,
    eMyIconSettingsHostGroup,
    eMyIconSettingsHostNetwork,
	eMyIconSettingsSendFile,
    eMyIconSettingsShareFiles,
    eMyIconSettingsShareStoryboard,
    eMyIconSettingsShareWebCam,
    eMyIconSettingsRandomConnect,
    eMyIconSettingsRandomConnectRelay,
    eMyIconSettingsFileXfer,
    eMyIconSettingsMessenger,
    eMyIconSettingsTruthOrDare,
    eMyIconSettingsVoicePhone,
    eMyIconSettingsVideoPhone,
	eMyIconSettingsPushToTalk,

    eMyIconEditRedo,
    eMyIconEditUndo,
    eMyIconEditAlignCenter,
    eMyIconEditAlignLeft,
    eMyIconEditAlignLeftAndRight,
    eMyIconEditAlignRight,
    eMyIconEditBold,
    eMyIconEditCopy,
    eMyIconEditCut,
    eMyIconEditField,
    eMyIconEditFileNew,
    eMyIconEditItalic,
    eMyIconEditPaste,
    eMyIconEditPrint,
    eMyIconEditText,
    eMyIconEditUnderline,

    eMyIconEditHyperLink,

    eMyIconFileOpen,
    eMyIconFileSave,
    eMyIconFileSaveAs,

	eMyIconOfferHistory,
    eMyIconOfferList,
    eMyIconOfferTruthOrDare,
    eMyIconOfferVideoChat,
    eMyIconOfferVoicePhone,

	eMyIconPersonAdd,
	eMyIconPersonsOfferList,
	eMyIconGroupJoined,

	eMyIconDirectConnected,

	eMyIconConnect,
	eMyIconDisconnect,

	eMyIconInviteAccept,
	eMyIconInviteCreate,

	eMyIconBoot,

	eMyIconChatRoomInfo,
	eMyIconGroupInfo,
	eMyIconNetworkInfo,
	eMyIconRandomConnectInfo,

    eMyIconSoundSettings,

	eMyIconShareAboutMeEye,
	eMyIconShareFilesEye,
	eMyIconShareStoryboardEye,
	eMyIconShareWebCamEye,

	eMyIconAboutMeEdit,
	eMyIconStoryboardEdit,

	eMyIconOfferEye,

	eMyIconUserPreferences,

	eMyIconNetworking,

	eMyIconUserConnections,

	eMyIconPlayerNlc,
	eMyIconPlayStream,
	eMyIconPlayExtern,

	eMyIconFriendRequestList,

	eMyIconUserLeave,

	eMyIconLanguageSelect,

	eMaxMyIcon	// must be last
};
