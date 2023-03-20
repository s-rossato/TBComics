
#pragma once

#include "beginh.dex"

class TB_EXPORT TBoxes : public SqlRecord
{
	DECLARE_DYNCREATE(TBoxes)

public:
	DataStr		f_BoxNo;
	DataDate	f_CreationDate;
	DataDate	f_ClosingDate;
	DataBool	f_IsClosed;
	DataStr		f_LastName;
	DataStr		f_Name;
	DataStr		f_Telephone1;
	DataStr		f_Telephone2;
	DataStr		f_Mail;
	DataPerc	f_Discount;
	DataStr		f_Notes;

	DataStr		l_BmpStatusBox;

public:
	TBoxes(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord();

public:
	static  LPCTSTR  GetStaticName();
};

class TB_EXPORT TBoxCollections : public SqlRecord
{
	DECLARE_DYNCREATE(TBoxCollections)

public:
	DataStr		f_BoxNo;
	DataStr		f_Collection;
	DataDate	f_CreationDate;
	DataStr		f_FromNumber;
	DataStr		f_LastReceiptNumber;
	DataStr		f_LastIssuedNumber;
	DataDate	f_LastReceiptDate;
	DataDate	f_LastIssuedDate;
	DataDate	f_ClosingDate;
	DataBool	f_IsClosed;
	DataStr		f_Notes;

	DataStr		l_CollectionDescri;

public:
	TBoxCollections(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord();

public:
	static  LPCTSTR  GetStaticName();
};

class TB_EXPORT TBoxEntries : public SqlRecord
{
	DECLARE_DYNCREATE(TBoxEntries)

public:
	DataStr		f_BoxNo;
	DataStr		f_Item;
	DataDate	f_ReceiptDate;

	DataStr		l_ItemDescri;

public:
	TBoxEntries(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord();

public:
	static  LPCTSTR  GetStaticName();
};

#include "endh.dex"