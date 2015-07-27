// my_tests.h : main header file for the MY_TESTS application
//

#if !defined(AFX_MY_TESTS_H__09210C84_65F3_435F_8906_8C071D9D1EC9__INCLUDED_)
#define AFX_MY_TESTS_H__09210C84_65F3_435F_8906_8C071D9D1EC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include 'stdafx.h' before including this file for PCH


/////////////////////////////////////////////////////////////////////////////
// CMy_testsApp:
// See my_tests.cpp for the implementation of this class
//

class CMy_testsApp : public CWinApp
{
public:
	CMy_testsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy_testsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy_testsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MY_TESTS_H__09210C84_65F3_435F_8906_8C071D9D1EC9__INCLUDED_)
