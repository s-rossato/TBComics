
#pragma once

#include "beginh.dex"

class TB_EXPORT TTmpUnloadComics : public SqlRecord
{
	DECLARE_DYNCREATE(TTmpUnloadComics) 

public:
	DataLng		f_Document_Id;
	DataInt		f_Line;
	DataStr		f_BoxNo;
	DataLng		f_SubId;
	DataStr		f_LastName;
	DataStr		f_Name;
	DataStr		f_Item;
	DataStr		f_Collection;
	DataDate	f_ReceiptDate;

public:
	TTmpUnloadComics(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord	();	

public:
	static  LPCTSTR  GetStaticName();
};

#include "endh.dex"