/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		UTCMGR.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CUTCMGRApp class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef UTCMGR_HPP
#define UTCMGR_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/App.hpp>
#include "AppWnd.hpp"
#include "AppCmds.hpp"
#include "Profile.hpp"
#include <WCL/HelpFile.hpp>
#include <WCL/IniFile.hpp>
#include "Cache.hpp"
#include <WCL/StrArray.hpp>

/******************************************************************************
** 
** The application class.
**
*******************************************************************************
*/

class CUTCMGRApp : public CApp
{
public:
	//
	// Constructors/Destructor.
	//
	CUTCMGRApp();
	~CUTCMGRApp();

	//
	// Members
	//
	CAppWnd		m_AppWnd;			// Main window.
	CAppCmds	m_AppCmds;			// Command handler.
	CHelpFile	m_oHelpFile;		// The help file.
	CIniFile	m_oIniFile;			// Config File.
	uint		m_nModified;		// Config modified flags.

	CCache		m_oCache;			// MDB Cache table.

	CProfiles	m_aoProfiles;		// The list of profiles.
	CProfile*	m_pProfile;			// Current profile.
	CString		m_strDefProfile;	// Default profile.

	CString		m_strCacheIndex;	// Cache index file name.
	CString		m_strCacheExt;		// Cache file extensions.

	CStrArray	m_astrPinned;		// The list of pinned files.

	bool		m_bScanOnStart;		// Scan on startup?
	bool		m_bScanOnSwitch;	// Scan when switching profiles?
	bool		m_bScanForTmp;		// Scan for old .tmp files?
	bool		m_bScanIndex;		// Scan index for old entries?
	bool		m_bShowAllFiles;	// Show all files?
	bool		m_bLogEdits;		// Log edit operations to a file?
	bool		m_bIgnoreDates;		// Ignore dates mismatches?

	CRect		m_rcLastWndPos;		// Main window position.
	CRect		m_rcLastDlgPos;		// Import/Restore dialog position.

	CString		m_strDefStatus;		// The default status bar text.

	//
	// Profile methods.
	//
	CProfile* FindProfile(const tchar* pszName) const;
	CProfile* FindProfileByCfgFile(const CPath& strCfgFile) const;
	int       GetProfileIndex(CProfile* pProfile) const;
	void      BuildProfileMenu();

	//
	// Formatting methods.
	//
	CString FormatType(tchar cType) const;
	CString FormatSize(int nSize) const;
	CString FormatStatus(tchar cStatus) const;
	int     IconIndex(tchar cType) const;

	//
	// Utility methods.
	//
	void UpdateCacheStatus();

	//
	// Constants.
	//
	static const tchar* VERSION;

	//
	// Modified flags.
	//
	enum
	{
		NONE	 = 0x0000,
		SETTINGS = 0x0001,
		PROFILES = 0x0002,
		PIN_LIST = 0x0004,
	};

protected:
	//
	// Startup and Shutdown template methods.
	//
	virtual	bool OnOpen();
	virtual	bool OnClose();

	//
	// Internal methods.
	//
	void LoadConfig();
	void SaveConfig();

	//
	// Constants.
	//
	static const tchar* INI_FILE_VER_10;
	static const tchar* INI_FILE_VER_20;
	static const tchar* INI_FILE_VER_25;
};

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

// The application object.
extern CUTCMGRApp App;

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/


#endif //UTCMGR_HPP
