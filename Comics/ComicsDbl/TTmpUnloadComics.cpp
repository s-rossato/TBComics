
#include "stdafx.h"             

// Locals
#include "TTmpUnloadComics.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static TCHAR szP1[]	= _T("P1");
static TCHAR szP2[]	= _T("P2");
static TCHAR szP3[]	= _T("P3");

IMPLEMENT_DYNCREATE(TTmpUnloadComics, SqlRecord) 

//-----------------------------------------------------------------------------
TTmpUnloadComics::TTmpUnloadComics(BOOL bCallInit)
	:
	SqlRecord(GetStaticName())
{
	BindRecord();
	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TTmpUnloadComics::BindRecord()
{
	BEGIN_BIND_DATA	();
		BIND_DATA	(_NS_FLD("SaleDocId"),		f_Document_Id);
		BIND_DATA	(_NS_FLD("Line"),			f_Line);
		BIND_DATA	(_NS_FLD("BoxNo"),			f_BoxNo);
		BIND_DATA	(_NS_FLD("SubId"),			f_SubId);
		BIND_DATA	(_NS_FLD("LastName"),		f_LastName);
		BIND_DATA	(_NS_FLD("Name"),			f_Name);
		BIND_DATA	(_NS_FLD("Item"),			f_Item);
		BIND_DATA	(_NS_FLD("Collection"),		f_Collection);
		BIND_DATA	(_NS_FLD("ReceiptDate"),	f_ReceiptDate);
	END_BIND_DATA();							
}

//-----------------------------------------------------------------------------
LPCTSTR TTmpUnloadComics::GetStaticName() { return _NS_TBL("CO_TmpUnloadComics"); }
