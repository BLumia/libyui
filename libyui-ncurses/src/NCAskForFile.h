/*---------------------------------------------------------------------\
|                                                                      |
|                      __   __    ____ _____ ____                      |
|                      \ \ / /_ _/ ___|_   _|___ \                     |
|                       \ V / _` \___ \ | |   __) |                    |
|                        | | (_| |___) || |  / __/                     |
|                        |_|\__,_|____/ |_| |_____|                    |
|                                                                      |
|                               core system                            |
|                                                        (C) SuSE GmbH |
\----------------------------------------------------------------------/

   File:       NCAskForFile.h

   Author:     Gabriele Strattner <gs@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#ifndef NCAskForFile_h
#define NCAskForFile_h

#include <iosfwd>

#include <vector>
#include <string>

#include "NCPopup.h"
#include "NCLabel.h"
#include "NCFileSelection.h"
#include "NCPushButton.h"
#include "NCComboBox.h"
#include "NCCheckBox.h"
#include "NCTextEntry.h"


///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NCAskForFile
//
//	DESCRIPTION :
//
class NCAskForFile : public NCPopup {

    NCAskForFile & operator=( const NCAskForFile & );
    NCAskForFile            ( const NCAskForFile & );

private:

    NCPushButton * okButton;
    NCPushButton * cancelButton;
    NCComboBox * dirName;
    NCDirectoryTable *dirList;		// directory list
    NCFileTable *fileList;		// file list
    NCCheckBox *detailed;

    NCTextEntry *fileName;
    
    bool getCheckBoxValue( NCCheckBox * detailed );
    
protected:

    virtual bool postAgain();

    virtual NCursesEvent wHandleInput( wint_t ch );
    
public:
    
    NCAskForFile( const wpos at,
		  const YCPString & startDir,
		  const YCPString & filter,
		  const YCPString & headline );

    virtual ~NCAskForFile() {}

    /**
     * Set the default size
     */
    virtual long nicesize(YUIDimension dim);
    
    /**
     * Create layout of file selection popup
     * @param YCPString The initial start directory
     * @param YCPString The filter (show files matching this pattern) 
     * @param YCPString The headline of the popup
     * @param bool	File name field editable?
     * @return void
     */
    void createLayout( const YCPString & iniDir,
		       const YCPString & filter,
		       const YCPString & headline,
		       bool  editable );

    /**
     * Shows the popup with the list of directories.
     * @return NCursesEvent
     */
    NCursesEvent & showDirPopup( );

};

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NCAskForExistingFile
//
//	DESCRIPTION :
//
class NCAskForExistingFile : public NCAskForFile {

    NCAskForExistingFile & operator=( const NCAskForFile & );
    NCAskForExistingFile ( const NCAskForFile & );

public:

    NCAskForExistingFile( const wpos at,
			  const YCPString & startDir,
			  const YCPString & filter,
			  const YCPString & headline );

    virtual ~NCAskForExistingFile() {} 
};

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NCAskForSaveFileName
//
//	DESCRIPTION :
//
class NCAskForSaveFileName : public NCAskForFile {

    NCAskForSaveFileName & operator=( const NCAskForFile & );
    NCAskForSaveFileName ( const NCAskForFile & );

public:

    NCAskForSaveFileName( const wpos at,
			  const YCPString & startDir,
			  const YCPString & filter,
			  const YCPString & headline );

    virtual ~NCAskForSaveFileName() {}
    
};

///////////////////////////////////////////////////////////////////


#endif // NCAskForFile_h
