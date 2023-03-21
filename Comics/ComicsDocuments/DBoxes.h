
#pragma once

#include <Comics\ComicsComponents\ADMBoxes.h>

#include "beginh.dex"

class TBoxes;
class TBoxCollections;

//////////////////////////////////////////////////////////////////////////////
//             class DBTBoxes definition
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
class TB_EXPORT DBTBoxes : public DBTMaster
{ 
	DECLARE_DYNAMIC (DBTBoxes)

public:
	DBTBoxes (CRuntimeClass*, CAbstractFormDoc*);

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
//             class DBTBoxesDetails definition
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
class TB_EXPORT DBTBoxesDetails : public DBTSlaveBuffered
{ 
	DECLARE_DYNAMIC (DBTBoxesDetails)

public:
	DBTBoxesDetails (CRuntimeClass*, CAbstractFormDoc*);

public:
	TBoxes* 			GetBoxes () 			const { return (TBoxes*)m_pDocument->GetMaster()->GetRecord(); }
	TBoxCollections*	GetDetail 				(int nRow)	const { return (TBoxCollections*) GetRow(nRow); }

protected: 
	virtual	void	OnDefineQuery		();
	virtual	void	OnPrepareQuery		();

	virtual	BOOL	OnCheckPrimaryKey	();
	virtual	void	OnPreparePrimaryKey	(int nRow, SqlRecord* pRec);
};

//=============================================================================
class TB_EXPORT DBoxes : public CAbstractFormDoc, public ADMBoxesObj
{
	DECLARE_DYNCREATE(DBoxes)

public:
	DBoxes();
	DBTBoxes*			m_pDBTBoxes;
	DBTBoxesDetails*	m_pDBTDetail;
	
public:
	virtual	TBoxes*			GetBoxes	() 			const;
	virtual	TBoxCollections*	GetDetail				(int nRow)	const;
                       
	// ADM Interface
	virtual	ADMObj*		GetADM		()	{ return this; }

protected:
	virtual BOOL	OnAttachData	();
};

#include "endh.dex"
