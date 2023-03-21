
#pragma once

#include "beginh.dex"

class TBoxes;
class TBoxesDetails;

/////////////////////////////////////////////////////////////////////////////
//							ADMBoxsObj
/////////////////////////////////////////////////////////////////////////////
//
class TB_EXPORT ADMBoxsObj : public ADMObj
{     
	DECLARE_ADMCLASS(ADMBoxsObj)
		
public:
	virtual	ADMObj*				GetADM					()					= 0;
	virtual	TBoxes*	GetBoxes	()			const	= 0;
	
	virtual	TBoxesDetails*	GetDetail	(int nRow)		const	= 0;
};

#include "endh.dex"
