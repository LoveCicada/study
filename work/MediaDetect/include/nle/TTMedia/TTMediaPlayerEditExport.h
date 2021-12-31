#ifndef _TT_MEDIAPLAYEREDIT_EXPORTS_
#define _TT_MEDIAPLAYEREDIT_EXPORTS_

#include "TTMediaPlayerEditDef.h"
#include <vector>

//!TTMediaPlayerContorlInterface I/F

#define HEDITCMD			void*
#define HEDITFONT			void*
#define HEDITHCOLOR			void*
#define HEDITSTATE			void*
#define HEDITLINE			void*
#define HEDITSONGSTATE		void*
#define HEDITTLCOMPONENT	void*

typedef struct stu_TTMediaPlayerContorlInterface
{

	int				(* TT_MPI_Cmd_GetTLFont)( HEDITFONT hFont, wchar_t* pszEnFontName, wchar_t* pszChFontName,
		double &dFontWidth, double &dFontHeight, BOOL &bBound, BOOL &bItalic, int &nDistance );
	int				(* TT_MPIC_Cmd_GetHColor)( HEDITHCOLOR hColor, unsigned int &nColor );
	HEDITFONT		(* TT_MPI_Cmd_CreateTLFont)( HTTMPHANDLE hSequence, wchar_t* pszEnFontName, wchar_t* pszChFontName, double dFontWidth, double dFontHeight, BOOL bBound, BOOL bItalic, int nDistance );
	HEDITHCOLOR		(* TT_MPI_Cmd_CreateTLColor)( HTTMPHANDLE hSequence, short bHaveFace, unsigned int nFaceColor,short bHaveBorder,int nBorderWdith,unsigned int nBorderColor );
	HEDITSTATE		(* TT_MPI_Cmd_CreateTLExteriorState)( HTTMPHANDLE hSequence, long lIndex, HEDITFONT hFont, HEDITHCOLOR hColor, long lTrimIn, long lTrimOut, wchar_t* pText );
	HEDITSTATE       (*TT_MPI_Cmd_CreateTLPosState)(HTTMPHANDLE hSequence, long lIndex ,DWORD ePosType,POINTF* pPtLeftTop,POINTF *pPtRightBottom);
	HEDITLINE		(* TT_MPI_Cmd_CreateTTLine)( HTTMPHANDLE hSequence, long lIndex, HEDITFONT hFont, HEDITHCOLOR hColor, long lTrimIn, long lTrimOut, wchar_t* pText );
	HEDITSONGSTATE	(* TT_MPI_Cmd_CreateTLSongExteriorState)( HTTMPHANDLE hSequence );

	HEDITCMD		(* TT_MPI_Cmd_CreateAddCommand)( HTTMPHANDLE hSequence, ADDTYPE addType );
	HEDITCMD		(* TT_MPI_Cmd_CreateAddSongCommand)( HTTMPHANDLE hSequence, HEDITSONGSTATE hSongState );
	HEDITCMD		(* TT_MPI_Cmd_CreateModifyCommand)( HTTMPHANDLE hSequence, HTLITEM hTLItem, int nModifyType, HEDITSTATE hState );
	HEDITCMD		(* TT_MPI_Cmd_CreateRemoveCommand)( HTTMPHANDLE hSequence, HTLITEM hTLItem );
	HEDITCMD		(* TT_MPI_Cmd_CreateCommandSet)( HTTMPHANDLE hSequence, std::vector<HEDITCMD> & cmdSet );
	HEDITCMD		(* TT_MPI_Cmd_CreateClapSongCommand)( HTTMPHANDLE hSequence, GUID guidProject, HTLITEM hTLItem, CLAPTYPE clapType, BOOL bCover, int nFrame, int nLine );
	HEDITCMD		(* TT_MPI_Cmd_CreateOpenProjectCommand)( HTTMPHANDLE hSequence, GUID guidProject );

	HTLITEM			(* TT_MPI_Cmd_GetTLComponent)( HTTMPHANDLE hSequence, HEDITCMD hCmd );
	HTLITEM			(* TT_MPI_Cmd_GetItemChild)( HTTMPHANDLE hSequence, HTLITEM hTLItem, int nIndex );
	int				(* TT_MPI_Cmd_GetItemChildCount)( HTTMPHANDLE hSequence, HTLITEM hTLItem, int& nCount );
	int				(* TT_MPI_Cmd_GetItemText)( HTTMPHANDLE hSequence, HTLITEM hTLItem, wchar_t* pszText );
	int				(* TT_MPI_Cmd_GetItemTrimIn)( HTTMPHANDLE hSequence, HTLITEM hTLItem, int& nTrimIn );
	int				(* TT_MPI_Cmd_GetItemTrimOut)( HTTMPHANDLE hSequence, HTLITEM hTLItem, int& nTrimOut );
	int				(* TT_MPI_Cmd_InsertLine)( HTTMPHANDLE hSequence, HEDITSONGSTATE hSongState, HEDITLINE hLine );


	int				(* TT_MPI_Cmd_Execute)( HTTMPHANDLE hSequence, HEDITCMD hCmd );
	int				(* TT_MPI_Cmd_Redo)( HTTMPHANDLE hSequence );
	int				(* TT_MPI_Cmd_Undo)( HTTMPHANDLE hSequence );
	HTLITEM			(* TT_MPI_GetTL)( HTTMPHANDLE hSequence );
	int				(*TT_MPI_Cmd_SetSafeBox)( HTTMPHANDLE hSequence,BOOL bShow,BOOL bShow43, float fBoxSie);
	int				(*TT_MPI_Cmd_GetObjectPos)(HTTMPHANDLE hSequence,HTLITEM hTLItem,int lIndex,float &xPos,float &yPos);
	int				(*TT_MPI_Cmd_GetObjectRect)(HTTMPHANDLE hSequence,HTLITEM hTLItem,int lIndex,POINTF &PtLeftTop,POINTF &PtRightBottom);
	

	stu_TTMediaPlayerContorlInterface()
	{
		memset( this, 0, sizeof( stu_TTMediaPlayerContorlInterface ) );
	}

}TTMediaPlayerContorlInterface,*lpTTMediaPlayerContorlInterface;


int AFX_EXT_API TT_GetEditInterface( lpTTMediaPlayerContorlInterface lpContorlInfterface );

#endif