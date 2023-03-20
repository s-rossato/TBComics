
#include "stdafx.h"

#include "DCollections.h"  
#include <Comics\ComicsDbl\TCollections.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
static TCHAR szParamCode[] = _T("paramCode");

//////////////////////////////////////////////////////////////////////////////
//             class DBTCollections implementation
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (DBTCollections, DBTMaster)

//-----------------------------------------------------------------------------	
DBTCollections::DBTCollections
	(
		CRuntimeClass*		pClass, 
		CAbstractFormDoc*	pDocument
	)
	:
	DBTMaster (pClass, pDocument, _NS_DBT("Collections"))
{
}

//-----------------------------------------------------------------------------
void DBTCollections::OnEnableControlsForFind ()
{
	GetCollections ()->f_Collection.SetFindable();
	GetCollections ()->f_Description.SetFindable();
}

//-----------------------------------------------------------------------------
void DBTCollections::OnDisableControlsForEdit ()
{
	GetCollections ()->f_Collection.SetReadOnly ();
}

//-----------------------------------------------------------------------------	
void DBTCollections::OnPrepareBrowser (SqlTable* pTable)
{
	TCollections* pRec = (TCollections*) pTable->GetRecord();

	pTable->SelectAll();
	pTable->AddSortColumn(pRec->f_Collection);
}

//-----------------------------------------------------------------------------
void DBTCollections::OnDefineQuery ()
{
	m_pTable->SelectAll			();
	m_pTable->AddParam			(szParamCode,GetCollections ()->f_Collection);
	m_pTable->AddFilterColumn	(GetCollections ()->f_Collection);
}

//-----------------------------------------------------------------------------
void DBTCollections::OnPrepareQuery ()
{
	m_pTable->SetParamValue (szParamCode, GetCollections()->f_Collection);
}

//-----------------------------------------------------------------------------
BOOL DBTCollections::OnCheckPrimaryKey	()
{
	return
		!GetCollections ()->f_Collection.IsEmpty() ||
		!SetError(_TB("The code field is mandatory"));
}

//////////////////////////////////////////////////////////////////////////////
//									DCollections                          //
//////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(DCollections, CAbstractFormDoc)

//-----------------------------------------------------------------------------
DCollections::DCollections()
	:
	m_pDBTCollections	(NULL)
{
}

//-----------------------------------------------------------------------------
TCollections*	DCollections::GetCollections () const 
{ 
	return (TCollections*) m_pDBTCollections->GetRecord(); 
}

//-----------------------------------------------------------------------------
BOOL DCollections::OnAttachData()
{              
	SetFormTitle (_TB("Collections document"));
	
	m_pDBTCollections = new DBTCollections (RUNTIME_CLASS (TCollections), this);
	
	return Attach (m_pDBTCollections);
}