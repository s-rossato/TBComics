
#include "stdafx.h"             

//ERP
#include <Items\ItemsLen.h>
#include <Items\Dbl\ItemsInfo.h>

//Local
#include "TBoxes.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static TCHAR szP1[]	= _T("P1");
static TCHAR szP2[]	= _T("P2");
static TCHAR szP3[]	= _T("P3");

/////////////////////////////////////////////////////////////////////////////
//	SqlRecord					### TBoxes ###	
/////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(TBoxes, SqlRecord)

//-----------------------------------------------------------------------------
TBoxes::TBoxes(BOOL bCallInit)
	:
	SqlRecord(GetStaticName()),
	f_IsClosed(FALSE)
{
	f_BoxNo.SetUpperCase();

	BindRecord();
	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TBoxes::BindRecord()
{
	BEGIN_BIND_DATA();
	BIND_DATA(_NS_FLD("BoxNo"), f_BoxNo);
	BIND_DATA(_NS_FLD("CreationDate"), f_CreationDate);
	BIND_DATA(_NS_FLD("ClosingDate"), f_ClosingDate);
	BIND_DATA(_NS_FLD("IsClosed"), f_IsClosed);
	BIND_DATA(_NS_FLD("LastName"), f_LastName);
	BIND_DATA(_NS_FLD("Name"), f_Name);
	BIND_DATA(_NS_FLD("Telephone1"), f_Telephone1);
	BIND_DATA(_NS_FLD("Telephone2"), f_Telephone2);
	BIND_DATA(_NS_FLD("Mail"), f_Mail);
	BIND_DATA(_NS_FLD("Discount"), f_Discount);
	BIND_DATA(_NS_FLD("Notes"), f_Notes);

	// LOCAL_STR(_NS_LFLD("l_BmpStatusBox"), l_BmpStatusBox, LEN_COLLECTION_DESCRI);
	BIND_TB_GUID();
	END_BIND_DATA();
}



//-----------------------------------------------------------------------------
LPCTSTR TBoxes::GetStaticName() { return _NS_TBL("CO_Boxes"); }

/////////////////////////////////////////////////////////////////////////////
//	SqlRecord					### TBoxCollections ###	
/////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(TBoxCollections, SqlRecord)

//-----------------------------------------------------------------------------
TBoxCollections::TBoxCollections(BOOL bCallInit)
	:
	SqlRecord(GetStaticName()),
	f_IsClosed(FALSE)
{
	f_Collection.SetUpperCase();

	BindRecord();
	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TBoxCollections::BindRecord()
{
	BEGIN_BIND_DATA();
	BIND_DATA(_NS_FLD("BoxNo"), f_BoxNo);
	BIND_DATA(_NS_FLD("Collection"), f_Collection);
	BIND_DATA(_NS_FLD("CreationDate"), f_CreationDate);
	BIND_DATA(_NS_FLD("FromNumber"), f_FromNumber);
	BIND_DATA(_NS_FLD("LastReceiptNumber"), f_LastReceiptNumber);
	BIND_DATA(_NS_FLD("LastIssuedNumber"), f_LastIssuedNumber);
	BIND_DATA(_NS_FLD("LastReceiptDate"), f_LastReceiptDate);
	BIND_DATA(_NS_FLD("LastIssuedDate"), f_LastIssuedDate);
	BIND_DATA(_NS_FLD("ClosingDate"), f_ClosingDate);
	BIND_DATA(_NS_FLD("IsClosed"), f_IsClosed);
	BIND_DATA(_NS_FLD("Notes"), f_Notes);

	// LOCAL_STR(_NS_LFLD("CollectionDescri"), l_CollectionDescri, LEN_COLLECTION_DESCRI);
	END_BIND_DATA();
}

//-----------------------------------------------------------------------------
LPCTSTR TBoxCollections::GetStaticName() { return _NS_TBL("CO_CollectionsBox"); }

/////////////////////////////////////////////////////////////////////////////
//	SqlRecord					### TBoxEntries ###	
/////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(TBoxEntries, SqlRecord)

//-----------------------------------------------------------------------------
TBoxEntries::TBoxEntries(BOOL bCallInit)
	:
	SqlRecord(GetStaticName())
{
	f_Item.SetUpperCase();

	BindRecord();
	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TBoxEntries::BindRecord()
{
	BEGIN_BIND_DATA();
	BIND_DATA(_NS_FLD("BoxNo"), f_BoxNo);
	BIND_DATA(_NS_FLD("Item"), f_Item);
	BIND_DATA(_NS_FLD("ReceiptDate"), f_ReceiptDate);

	LOCAL_STR(_NS_LFLD("ItemDescri"), l_ItemDescri, LEN_DESCRI_ITEM);
	END_BIND_DATA();
}

//-----------------------------------------------------------------------------
LPCTSTR TBoxEntries::GetStaticName() { return _NS_TBL("CO_ReceiptsBox"); }

