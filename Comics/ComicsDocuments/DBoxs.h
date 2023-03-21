
#pragma once

#include <Comics\ComicsComponents\ADMBoxs.h>

#include "beginh.dex"

class TBoxes;
class TBoxesDetails;

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxs definition
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
class TB_EXPORT DBTBoxs : public DBTMaster
{ 
	DECLARE_DYNAMIC (DBTBoxs)

public:
	DBTBoxs (CRuntimeClass*, CAbstractFormDoc*);

public:
	TBoxes* GetBoxes () const { return (TBoxes*) GetRecord(); }

protected: 
	virtual void	OnEnableControlsForFind		();
	virtual void	OnDisableControlsForEdit	();
	
	virtual	void	OnDefineQuery		();
	virtual	void	OnPrepareQuery		();
	virtual	void	OnPrepareBrowser	(SqlTable* pTable);
	
	virtual	BOOL	OnCheckPrimaryKey	();
	virtual	void	OnPreparePrimaryKey	() {}
};

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxsDetails definition
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
class TB_EXPORT DBTBoxsDetails : public DBTSlaveBuffered
{ 
	DECLARE_DYNAMIC (DBTBoxsDetails)

public:
	DBTBoxsDetails (CRuntimeClass*, CAbstractFormDoc*);

public:
	TBoxes* 			GetBoxes () 			const { return (TBoxes*)m_pDocument->GetMaster()->GetRecord(); }
	TBoxesDetails*	GetDetail 				(int nRow)	const { return (TBoxesDetails*) GetRow(nRow); }

protected: 
	virtual	void	OnDefineQuery		();
	virtual	void	OnPrepareQuery		();

	virtual	BOOL	OnCheckPrimaryKey	();
	virtual	void	OnPreparePrimaryKey	(int nRow, SqlRecord* pRec);
};

//=============================================================================
class TB_EXPORT DBoxs : public CAbstractFormDoc, public ADMBoxsObj
{
	DECLARE_DYNCREATE(DBoxs)

public:
	DBoxs();
	DBTBoxs*			m_pDBTBoxs;
	DBTBoxsDetails*	m_pDBTDetail;
	
public:
	virtual	TBoxes*			GetBoxes	() 			const;
	virtual	TBoxesDetails*	GetDetail				(int nRow)	const;
                       
	// ADM Interface
	virtual	ADMObj*		GetADM		()	{ return this; }

protected:
	virtual BOOL	OnAttachData	();
};

#include "endh.dex"
