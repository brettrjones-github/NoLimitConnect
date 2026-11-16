//============================================================================
// Copyright (C) 2018 Brett R. Jones
//
// Code copyrighted by Brett R. Jones is under dual license similar to Ruby's license
// See file COPYING and LEGAL in root of the No Limit Connect project
//
// bjones.engineer@gmail.com
// https://nolimitconnect.org
//============================================================================

#include "AppletUserIdentity.h"

#include "AppletMgr.h"

#include "AppletEditAvatarImage.h"
#include "AppCommon.h"
#include "AppGlobals.h"
#include "AppSettings.h"
#include "GuiHelpers.h"
#include "HomeWindow.h"
#include "AccountMgr.h"

#include <QMessageBox>
#include <QUuid>
#include <QFileDialog>

#include <P2PEngine/EngineSettings.h>
#include <P2PEngine/P2PEngine.h>
#include <ThumbMgr/ThumbInfo.h>

#include <CoreLib/ObjectCommonDefs.h>
#include <CoreLib/VxFileUtil.h>
#include <CoreLib/VxDebug.h>
#include <CoreLib/VxGlobals.h>

#include "ui_AppletUserIdentity.h"

//============================================================================
AppletUserIdentity::AppletUserIdentity( AppCommon& app, QWidget* parent )
: AppletBase( OBJNAME_APPLET_USER_IDENTITY, app, parent )
, ui(*(new Ui::AppletUserIdentityUi))
, m_bUserPickedImage( false )
, m_bUsingDefaultImage( true )
{
    setAppletType( eAppletUserIdentity );
    ui.setupUi( getContentItemsFrame() );
	setTitleBarText( DescribeApplet( m_EAppletType ) );
    ui.m_EditAvatarImageButton->setIcon( eMyIconServiceAvatarImage );
    ui.m_EditAboutMeButton->setIcon( eMyIconAboutMeEdit );
    ui.m_ViewAboutMeButton->setIcon( eMyIconServiceShareAboutMe );
    ui.m_EditStoryboardButton->setIcon( eMyIconStoryboardEdit );
    ui.m_ViewStoryboardButton->setIcon( eMyIconServiceShareStoryboard );

    GuiHelpers::fillGender( ui.m_GenderComboBox );
    GuiHelpers::fillLanguage( ui.m_LanguageComboBox );
    GuiHelpers::fillContentRating( ui.m_ContentComboBox );
    GuiHelpers::fillAge( ui.m_AgeComboBox );

    VxNetIdent* curIdent = m_MyApp.getAppGlobals().getMyNetIdent();
    m_strOrigMoodMessage = curIdent->getOnlineDescription();
    ui.m_UserNameValueLabel->setText( curIdent->getOnlineName() );

    GuiHelpers::setValuesFromIdentity( this, curIdent, ui.m_AgeComboBox, ui.m_GenderComboBox, ui.m_LanguageComboBox, ui.m_ContentComboBox );

    connect( ui.m_ApplyMoodButton, SIGNAL(clicked()), this, SLOT( onApplyMoodMsgClick() ) );
    connect( ui.m_ApplyAgeButton, SIGNAL(clicked()), this, SLOT( onApplyAgeClick() ) );
    connect( ui.m_ApplyGenderButton, SIGNAL(clicked()), this, SLOT( onApplyGenderClick() ) );

    connect( ui.m_EditAboutMeButton, SIGNAL(clicked()), this, SLOT(slotEditAboutMeButClick() ) );
    connect( ui.m_ViewAboutMeButton, SIGNAL(clicked()), this, SLOT(slotViewAboutMeButClick() ) );
    connect( ui.m_EditAvatarImageButton, SIGNAL(clicked()), this, SLOT(slotEditAvatarButClick() ) );
    connect( ui.m_AvatarImageButton, SIGNAL(clicked()), this, SLOT(slotEditAvatarButClick() ) );
    connect( ui.m_EditStoryboardButton, SIGNAL(clicked()), this, SLOT(slotEditStoryboardButClick() ) );
    connect( ui.m_ViewStoryboardButton, SIGNAL(clicked()), this, SLOT(slotViewStoryboardButClick() ) );

    loadIdentity( *curIdent );

	m_MyApp.activityStateChange( this, true );
}

//============================================================================
void AppletUserIdentity::loadIdentity( VxNetIdent& ident )
{
    QString strMoodMessage = ident.getOnlineDescription();
    ui.m_MoodMessageEdit->setText( strMoodMessage );
    updateAvatarImage( ident.getAvatarThumbGuid(), ident.getAvatarThumbModifiedTime() );
}

//============================================================================
void AppletUserIdentity::saveIdentity( VxNetIdent& ident )
{
    QString strMoodMessage = ui.m_MoodMessageEdit->text();
    ident.setOnlineDescription( strMoodMessage.toUtf8().constData() );
}

//============================================================================
//! apply mood message change
void AppletUserIdentity::onApplyMoodMsgClick( void )
{
    if( false == validateMoodMessage() )
    {
        return;
    }

    QString moodMsg = ui.m_MoodMessageEdit->text();

    if( moodMsg != m_strOrigMoodMessage )
    {
        VxNetIdent* myIdent = m_MyApp.getAppGlobals().getMyNetIdent();
        std::string strOnlineDesc = moodMsg.toUtf8().constData();
        myIdent->setOnlineDescription( strOnlineDesc.c_str() );
        m_MyApp.getAccountMgr().updateAccount( *myIdent );
        m_Engine.fromGuiMoodMessageChanged( strOnlineDesc.c_str() );
        m_strOrigMoodMessage = moodMsg;

        QString msgText = QObject::tr( "Applied Mood Message Change " );
        QMessageBox::information( this, QObject::tr( "Mood Message Change Success" ), msgText );
    }
}

//============================================================================
void AppletUserIdentity::applyPersonalInfoChange( const QString& successTitle, const QString& successMsg )
{
    VxNetIdent* myIdent = m_MyApp.getAppGlobals().getMyNetIdent();
    GuiHelpers::setIdentityFromValues( this, myIdent, ui.m_AgeComboBox, ui.m_GenderComboBox, ui.m_LanguageComboBox, ui.m_ContentComboBox );

    m_MyApp.getAccountMgr().updateAccount( *myIdent );
    m_Engine.fromGuiIdentPersonalInfoChanged( myIdent->getAgeType(), myIdent->getGender(), myIdent->getPrimaryLanguage(), myIdent->getPreferredContent() );

    QMessageBox::information( this, successTitle, successMsg );
}

//============================================================================
void AppletUserIdentity::onApplyAgeClick( void )
{
    applyPersonalInfoChange( QObject::tr( "Age and Preferred Content Success" ), QObject::tr( "Applied Age and Preferred Content Change " ) );
}

//============================================================================
void AppletUserIdentity::onApplyContentClick( void )
{
    applyPersonalInfoChange( QObject::tr( "Age and Preferred Content Success" ), QObject::tr( "Applied Age and Preferred Content Change " ) );
}

//============================================================================
void AppletUserIdentity::onApplyGenderClick( void )
{
    applyPersonalInfoChange( QObject::tr( "Gender Change Success" ), QObject::tr( "Applied Gender Change " ) );
}

//============================================================================
void AppletUserIdentity::slotEditAvatarButClick( void )
{
    AppletEditAvatarImage* editAvatarImage = dynamic_cast<AppletEditAvatarImage*>(m_MyApp.getAppletMgr().launchApplet( eAppletEditAvatarImage, this ));
    if( editAvatarImage )
    {
        connect( editAvatarImage, SIGNAL(signalAvatarImageChanged( ThumbInfo* ) ), this, SLOT(slotAvatarImageChanged( ThumbInfo* ) ) );
        connect( editAvatarImage, SIGNAL(signalAvatarImageRemoved() ), this, SLOT(slotAvatarImageRemoved() ) );
    }
}

//============================================================================
void AppletUserIdentity::slotEditAboutMeButClick( void )
{
    m_MyApp.getAppletMgr().launchApplet( eAppletEditAboutMe, this );
}

//============================================================================
void AppletUserIdentity::slotViewAboutMeButClick( void )
{
    m_MyApp.getAppletMgr().launchApplet( eAppletAboutMeServerViewMine, this );
}

//============================================================================
void AppletUserIdentity::slotEditStoryboardButClick( void )
{
    m_MyApp.getAppletMgr().launchApplet( eAppletEditStoryboard, this );
}

//============================================================================
void AppletUserIdentity::slotViewStoryboardButClick( void )
{
    m_MyApp.getAppletMgr().launchApplet( eAppletStoryboardServerViewMine, this );
}

//============================================================================
//! validate user input
QString AppletUserIdentity::validateString( QString charSeq )
{
    //return charSeq.toString();    	
    return charSeq;
}

//============================================================================
bool AppletUserIdentity::validateMoodMessage( void )
{
    QString strMoodMsg = ui.m_MoodMessageEdit->text();
    return GuiHelpers::validateMoodMessage( this, strMoodMsg );
}

//============================================================================
void AppletUserIdentity::updateAvatarImage( VxGUID& thumbId, int64_t thumbModifiedTime )
{
    QImage thumbImage;
    m_MyApp.getThumbMgr().getAvatarImage( thumbId, thumbImage );
    if( !thumbImage.isNull() )
    {
        ui.m_AvatarImageButton->setIconOverrideImage( thumbImage );
        ui.m_AvatarImageButton->update();
    }
}

//============================================================================
void AppletUserIdentity::slotAvatarImageChanged( ThumbInfo* avatarThumb )
{
    m_MyApp.getThumbMgr().addThumbIfDoesNotExist( avatarThumb );
    updateAvatarImage( avatarThumb->getAssetUniqueId(), avatarThumb->getModifiedTime() );
}

//============================================================================
void AppletUserIdentity::slotAvatarImageRemoved( void )
{
    ui.m_AvatarImageButton->clearIconOverrideImage();
}
