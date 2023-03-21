
#include "stdafx.h"

#include "DBoxes.h"  
#include <Comics\ComicsDbl\TBoxes.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
static TCHAR szParamID[] = _T("paramID");

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxes implementation
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (DBTBoxes, DBTMaster)

//-----------------------------------------------------------------------------	
DBTBoxes::DBTBoxes
	(
		CRuntimeClass*		pClass, 
		CAbstractFormDoc*	pDocument
	)
	:
	DBTMaster (pClass, pDocument, _NS_DBT("Boxes"))
{
}

//-----------------------------------------------------------------------------
void DBTBoxes::OnEnableControlsForFind ()
{
	GetBoxes ()->f_BoxNo.SetFindable();
}

//-----------------------------------------------------------------------------
void DBTBoxes::OnDisableControlsForEdit ()
{
}

//-----------------------------------------------------------------------------	
void DBTBoxes::OnPrepareBrowser (SqlTable* pTable)
{
	TBoxes* pRec = (TBoxes*) pTable->GetRecord();

	pTable->SelectAll();
	pTable->AddSortColumn(pRec->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxes::OnDefineQuery ()
{
	m_pTable->SelectAll			();
	m_pTable->AddParam			(szParamID, GetBoxes()->f_BoxNo);
	m_pTable->AddFilterColumn	(GetBoxes()->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxes::OnPrepareQuery ()
{
	m_pTable->SetParamValue (szParamID, GetBoxes()->f_BoxNo);
}

//-----------------------------------------------------------------------------
BOOL DBTBoxes::OnCheckPrimaryKey	()
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxesDetails implementation
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (DBTBoxesDetails, DBTSlaveBuffered)

//-----------------------------------------------------------------------------	
DBTBoxesDetails::DBTBoxesDetails
	(
		CRuntimeClass*		pClass, 
		CAbstractFormDoc*	pDocument
	)
	:
	DBTSlaveBuffered (pClass, pDocument, _NS_DBT("BoxesDetails"), ALLOW_EMPTY_BODY, FALSE)
{
}

//-----------------------------------------------------------------------------
void DBTBoxesDetails::OnDefineQuery ()
{
	m_pTable->SelectAll			();
	m_pTable->AddParam			(szParamID,GetBoxes()->f_BoxNo);
	m_pTable->AddFilterColumn	(GetBoxes ()->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxesDetails::OnPrepareQuery ()
{
	m_pTable->SetParamValue(szParamID, GetBoxes()->f_BoxNo);
}

//-----------------------------------------------------------------------------
void DBTBoxesDetails::OnPreparePrimaryKey (int nRow, SqlRecord* pRec)
{
	m_pTable->SetParamValue (szParamID, GetBoxes()->f_BoxNo);

	ASSERT (pRec->IsKindOf(RUNTIME_CLASS(TBoxCollections)));
	
	TBoxCollections* pDetail= (TBoxCollections*) pRec;
  
	pDetail->f_BoxNo = GetBoxes()->f_BoxNo;
	// pDetail->f_Collection	= GetBoxes()->f_Collection;
}

//-----------------------------------------------------------------------------
BOOL DBTBoxesDetails::OnCheckPrimaryKey	()
{
	return NULL;
}

//////////////////////////////////////////////////////////////////////////////
//									DBoxes                          //
//////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(DBoxes, CAbstractFormDoc)

//-----------------------------------------------------------------------------
DBoxes::DBoxes()
	:
	m_pDBTBoxes	(NULL),
	m_pDBTDetail				(NULL)
{
}

//-----------------------------------------------------------------------------
TBoxes*			DBoxes::GetBoxes	()		 	const {return m_pDBTBoxes->GetBoxes(); }
TBoxCollections*	DBoxes::GetDetail					(int nRow)  const {return m_pDBTDetail->GetDetail(nRow); }

//-----------------------------------------------------------------------------
BOOL DBoxes::OnAttachData()
{              
	SetFormTitle (_TB("Boxes document"));
	
	m_pDBTBoxes	= new DBTBoxes 		(RUNTIME_CLASS (TBoxes), this);
	m_pDBTDetail				= new DBTBoxesDetails	(RUNTIME_CLASS (TBoxCollections), this);
	
	m_pDBTBoxes->Attach(m_pDBTDetail);

	return Attach (m_pDBTBoxes);
}