/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		UTCONFIGDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CUTConfigDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef UTCONFIGDLG_HPP
#define UTCONFIGDLG_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/CommonUI.hpp>
#include <WCL/IniFile.hpp>

/******************************************************************************
** 
** The dialog to edit the UT cache settings.
**
*******************************************************************************
*/

class CUTConfigDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CUTConfigDlg();
	
protected:
	//
	// Members.
	//
	CIniFile	m_oIniFile;
	CEditBox	m_ebFolder;
	CEditBox	m_ebExpiry;

	//
	// Message processors.
	//
	virtual void OnInitDialog();
	virtual bool OnOk();
	virtual void OnHelp(HELPINFO& oInfo);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //UTCONFIGDLG_HPP
