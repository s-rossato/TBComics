
#include "stdafx.h"

#include "DBoxs.h"  
#include <Comics\ComicsDbl\TBoxes.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
static TCHAR szParamID[] = _T("paramID");

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxs implementation
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (DBTBoxs, DBTMaster)

//-----------------------------------------------------------------------------	
DBTBoxs::DBTBoxs
	(
		CRuntimeClass*		pClass, 
		CAbstractFormDoc*	pDocument
	)
	:
	DBTMaster (pClass, pDocument, _NS_DBT("Boxs"))
{
}

//-----------------------------------------------------------------------------
void DBTBoxs::OnEnableControlsForFind ()
{
	GetBoxes ()->f_BoxNo.SetFindable();
	GetBoxes ()->f_Name.SetFindable();
}

//-----------------------------------------------------------------------------
void DBTBoxs::OnDisableControlsForEdit ()
{
}

//-----------------------------------------------------------------------------	
void DBTBoxs::OnPrepareBrowser (SqlTable* pTable)
{
	TBoxes* pRec = (TBoxes*) pTable->GetRecord();

	pTable->SelectAll();
	pTable->AddSortColumn(pRec->f_BoxNo);
	pTable->AddSortColumn(pRec->f_CreationDate);
}

//-----------------------------------------------------------------------------
void DBTBoxs::OnDefineQuery ()
{
	m_pTable->SelectAll			();
	m_pTable->AddParam			(szParamID, GetBoxes()->f_BoxNo);
	m_pTable->AddFilterColumn	(GetBoxes()->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxs::OnPrepareQuery ()
{
	m_pTable->SetParamValue (szParamID, GetBoxes()->f_BoxNo);
}

//-----------------------------------------------------------------------------
BOOL DBTBoxs::OnCheckPrimaryKey	()
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxsDetails implementation
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (DBTBoxsDetails, DBTSlaveBuffered)

//-----------------------------------------------------------------------------	
DBTBoxsDetails::DBTBoxsDetails
	(
		CRuntimeClass*		pClass, 
		CAbstractFormDoc*	pDocument
	)
	:
	DBTSlaveBuffered (pClass, pDocument, _NS_DBT("BoxsDetails"), ALLOW_EMPTY_BODY, FALSE)
{
}

//-----------------------------------------------------------------------------
void DBTBoxsDetails::OnDefineQuery ()
{
	m_pTable->SelectAll			();
	m_pTable->AddParam			(szParamID,GetBoxes()->f_BoxNo);
	m_pTable->AddFilterColumn	(GetBoxes ()->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxsDetails::OnPrepareQuery ()
{
	m_pTable->SetParamValue(szParamID, GetBoxes()->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxsDetails::OnPreparePrimaryKey (int nRow, SqlRecord* pRec)
{
	m_pTable->SetParamValue (szParamID, GetBoxes()->f_BoxNo);

	ASSERT (pRec->IsKindOf(RUNTIME_CLASS(TBoxCollections)));
	
	TBoxCollections* pDetail= (TBoxCollections*) pRec;
  
	pDetail->f_BoxNo	= GetBoxes()->f_BoxNo;
	// pDetail->f_Collection	= GetBoxes()->f_Collection;
	// GetBoxes()->f_LastSubId += 1;
}

//-----------------------------------------------------------------------------
BOOL DBTBoxsDetails::OnCheckPrimaryKey	()
{
	return NULL;
}

//////////////////////////////////////////////////////////////////////////////
//									DBoxs                          //
//////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(DBoxs, CAbstractFormDoc)

//-----------------------------------------------------------------------------
DBoxs::DBoxs()
	:
	m_pDBTBoxs	(NULL),
	m_pDBTDetail				(NULL)
{
}

//-----------------------------------------------------------------------------
TBoxes*			DBoxs::GetBoxes	()		 	const {return m_pDBTBoxs->GetBoxes(); }
TBoxesDetails*	DBoxs::GetDetail					(int nRow)  const {return m_pDBTDetail->GetDetail(nRow); }

//-----------------------------------------------------------------------------
BOOL DBoxs::OnAttachData()
{              
	SetFormTitle (_TB("Boxs document"));
	
	m_pDBTBoxs	= new DBTBoxs 		(RUNTIME_CLASS (TBoxes), this);
	m_pDBTDetail				= new DBTBoxsDetails	(RUNTIME_CLASS (TBoxCollections), this);
	
	m_pDBTBoxs->Attach(m_pDBTDetail);

	return Attach (m_pDBTBoxs);
}