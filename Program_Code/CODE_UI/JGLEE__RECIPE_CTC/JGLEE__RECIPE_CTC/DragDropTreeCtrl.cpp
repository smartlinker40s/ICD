// DragDropTreeCtrl.cpp : implementation file
#include "stdafx.h"

#include "DragDropTreeCtrl.h"
#include "DragDropContainer.h"
#include "DragEventListener.h"
#include "resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragDropTreeCtrl

CDragDropTreeCtrl::CDragDropTreeCtrl()
{
	m_pImageList = NULL;
	m_bDragging = FALSE;

	pLink_DragDrop = NULL;
}

CDragDropTreeCtrl::~CDragDropTreeCtrl()
{
	//
	// Delete the image list created by CreateDragImage.
	//
	//if (m_pImageList != NULL)
	//	delete m_pImageList;
}

BEGIN_MESSAGE_MAP(CDragDropTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CDragDropTreeCtrl)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY_REFLECT(NM_CLICK,  OnClick)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragDropTreeCtrl message handlers

BOOL CDragDropTreeCtrl::PreCreateWindow(CREATESTRUCT& cs) 
{
	//
	// Make sure the control's TVS_DISABLEDRAGDROP flag is not set.
	// If you subclass an existing tree view control rather than create
	// a CDragDropTreeCtrl outright, it's YOUR responsibility to see that
	// this flag isn't set.
	//
	//cs.style &= ~TVS_DISABLEDRAGDROP;
	return CTreeCtrl::PreCreateWindow(cs);
}

void CDragDropTreeCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if ( m_bDragging )
	{
		POINT pt = point ;
		ClientToScreen ( &pt ) ;

		CImageList::DragMove ( pt ) ;
		int nEventListenerCount = m_vEventListener.size();
		for( int nEventListenerIdx = 0; nEventListenerIdx < nEventListenerCount; ++nEventListenerIdx )
		{
			m_vEventListener[nEventListenerIdx]->OnDragMove(point);
		}
		return;
	}
	if(m_bLButtonDown)
	{
		// if( DragDetect(m_hWnd,point) )		// Ver 6.0
		if( DragDetect(point) )			// Ver .Net
		{
			OnDrag(point);
		}
	}
	CTreeCtrl::OnMouseMove(nFlags,point);
} 

void CDragDropTreeCtrl::Set_LinkDragDrop(CLink__DragDrop * p_link)
{
	pLink_DragDrop = p_link;
}

void CDragDropTreeCtrl::OnTimer(UINT nIDEvent)
{
	POINT pt;
	
	GetCursorPos ( &pt ) ;
	CImageList::DragMove ( pt ) ;
	
	int nEventListenerCount = m_vEventListener.size();
	for( int nEventListenerIdx = 0; nEventListenerIdx < nEventListenerCount;  ++nEventListenerIdx )
	{
		m_vEventListener[nEventListenerIdx]->OnDragMove(pt);
	}
}

void CDragDropTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{  
	printf(" * CDragDropTreeCtrl::OnLButtonUp() ... \n");

	// ...
	m_bLButtonDown = false;

	if((m_bDragging) 
	&& (m_pImageList != NULL))
	{		
		m_bDragging = FALSE;    

		KillTimer(1);

		ReleaseCapture();
		m_pImageList->DragLeave (this);
		m_pImageList->DragLeave (GetParent());
		m_pImageList->EndDrag ();
		SelectDropTarget(NULL);
		delete m_pImageList;

		m_pImageList = NULL;

		HTREEITEM h_item = HitTest(point,&nFlags);
		int size = m_vEventListener.size();
		int i;

		for(i=0;i<size;i++)
		{
			m_vEventListener[i]->OnDragRelease(point,h_item);
		}

		size = m_vSelItem.size();

		for(i=0;i<size;i++)
		{
			h_item = m_vSelItem[i];

			if(GetParentItem(h_item) != NULL)
			{
				if(pLink_DragDrop != NULL)
				{
					POINT pt = point;
					ClientToScreen(&pt);

					pLink_DragDrop->Call__DragDrop(this, h_item, pt);
				}
			}
		}
	}

	if(!(MK_CONTROL&nFlags) && !(MK_SHIFT&nFlags))
	{
		if(m_vSelItem.size() > 1)
		{
			ClearSelection();
			SetItemState(m_hLastSelItem,TVIS_SELECTED,TVIS_SELECTED);
			m_vSelItem.push_back(m_hLastSelItem);
		}    
	}

	CTreeCtrl::OnLButtonUp(nFlags, point);
}
void CDragDropTreeCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	printf(" * CDragDropTreeCtrl::OnLButtonDown() ... \n");

	// ...
	m_bLButtonDown = true;
	SetFocus();

	HTREEITEM hItem = GetSelectedItem();

	if(hItem)
	{
		SetItemState(hItem,0,TVIS_SELECTED);	
	}

	do
	{	
		hItem = HitTest(point,&nFlags);

		if( nFlags & TVHT_ONITEMBUTTON )
		{
			// Check if any child present
			if(!ItemHasChildren(hItem))
			{
				break;
			}

			// CTreeCtrl::OnLButtonDown(nFlags,point);
			break;
		}
		if( NULL == hItem )
		{
			break;
		}
		//HTREEITEM hSelect = GetSelectedItem();
		//SetItemState(hSelect, 0, TVIS_SELECTED);
		//if( NULL == GetParentItem(hItem) )
		//{
		//	break;
		//}
		unsigned short shKeyState = GetKeyState(VK_CONTROL);
		shKeyState >>= 15;
		if( shKeyState == 1 )
		{
			OnControlKeyPress(hItem);
			break;
		} 
		else
		{
			if(m_vSelItem.size() == 0)
			{
				SetItemState(hItem,TVIS_SELECTED,TVIS_SELECTED);
				m_vSelItem.push_back(hItem);
				break;
			}
			shKeyState = GetKeyState(VK_SHIFT);
			shKeyState >>= 15;
			if(shKeyState == 1)
			{
				OnShiftKeyPress(hItem);
				break;
			}
		}
		m_hLastSelItem = hItem;

		if(m_vSelItem.size() == 1)
		{
			ClearSelection();
			SetItemState(m_hLastSelItem,TVIS_SELECTED,TVIS_SELECTED);
			m_vSelItem.push_back(m_hLastSelItem);
		}
	}
	while(false);

	CTreeCtrl::OnLButtonDown(nFlags,point);
}

void CDragDropTreeCtrl::ClearSelection()
{
	int nSelItemCount = m_vSelItem.size();
	for( int nIdx = 0; nIdx < nSelItemCount ; ++nIdx )
	{
		SetItemState(m_vSelItem[nIdx],0,TVIS_SELECTED);
	}
	m_vSelItem.clear();
}

void CDragDropTreeCtrl::RemoveFromSelectionList(HTREEITEM hItem)
{
	SEL_ITEM_LIST::iterator itr;
	for( itr = m_vSelItem.begin(); itr != m_vSelItem.end(); ++itr )
	{
		if( (*itr) == hItem )
		{
			m_vSelItem.erase(itr);
			break;
		}
	}  
}

void CDragDropTreeCtrl::SelectItems(HTREEITEM hItemFrom,HTREEITEM hItemTo)
{
	RECT FromRect;
	GetItemRect(hItemFrom,&FromRect,FALSE);
	RECT ToRect;
	GetItemRect(hItemTo,&ToRect,FALSE);
	HTREEITEM hTemp;

	if( FromRect.top > ToRect.top )
	{
		hTemp = hItemFrom;
		hItemFrom = hItemTo;
		hItemTo = hTemp;
	}
	ClearSelection();

	hTemp = hItemFrom;
	while(1)
	{
		SetItemState(hTemp,TVIS_SELECTED,TVIS_SELECTED);
		m_vSelItem.push_back(hTemp);
		if( hTemp ==  hItemTo )
		{
			break;
		}
		hTemp = GetNextVisibleItem(hTemp);
		Sleep(1);
	}
}

CImageList* CDragDropTreeCtrl::CreateDragImageEx()
{
	// Find the bounding rectangle of all the selected items
	CRect		rectBounding; // Holds rectangle bounding area for bitmap
	CRect		rectFirstItem; // Holds first item's height and width
	CRect		rectTextArea;  // Holds text area of image

	int			nNumSelected; // Holds total number of selected items
	HTREEITEM hItem;

	CClientDC	DraggedNodeDC(this); // To draw drag image

	CDC			*pDragImageCalcDC = NULL;	// to find the drag image width and height
	CString		strItemText;


	CBitmap		*pBitmapOldMemDCBitmap = NULL; // Pointer to bitmap in memory

	CFont		*pFontOld = NULL; // Used for  bitmap font
	int			nIdx = 0, nCounter = 0; // Counts array elements
	int			nMaxWidth = 0;		// holds the maximum width to be taken to form the bounding rect

	//UINT		uiSelectedItems;  // Holds an item
	CImageList	*pImageListDraggedNode = NULL; // Holds an image list pointer

	nNumSelected = m_vSelItem.size();
	if( nNumSelected > 0)
	{
		pDragImageCalcDC = GetDC();
		if(pDragImageCalcDC == NULL)
			return NULL;
		CImageList *pImageList = GetImageList(TVSIL_NORMAL);
		//HICON hIcon = pImageList->ExtractIcon(nImg);
		int cx,cy;
		ImageList_GetIconSize(*pImageList, &cx, &cy);
		// Calculate the maximum width of the bounding rectangle
		for ( nIdx = 0; nIdx < nNumSelected; nIdx++)
		{
			// Get the item's height and width one by one
			hItem = m_vSelItem[nIdx];
			strItemText = GetItemText(hItem);
			rectFirstItem.SetRectEmpty();
			pDragImageCalcDC->DrawText(strItemText, rectFirstItem, DT_CALCRECT);
			if(nMaxWidth < ( rectFirstItem.Width()+cx))
				nMaxWidth = rectFirstItem.Width()+cx;
		}

		// Get the first item's height and width
		hItem = m_vSelItem[0];
		strItemText = GetItemText(hItem);
		rectFirstItem.SetRectEmpty();
		pDragImageCalcDC->DrawText(strItemText, rectFirstItem, DT_CALCRECT);
		ReleaseDC(pDragImageCalcDC);

		// Initialize textRect for the first item
		rectTextArea.SetRect(1, 1, nMaxWidth, rectFirstItem.Height());

		// Find the bounding rectangle of the bitmap
		rectBounding.SetRect(0,0, nMaxWidth+2, (rectFirstItem.Height()+2)*nNumSelected);

		CDC	MemoryDC; // Memory Device Context used to draw the drag image
		// Create bitmap		
		if(!MemoryDC.CreateCompatibleDC(&DraggedNodeDC))
			return NULL;
		CBitmap		DraggedNodeBmp; // Instance used for holding  dragged bitmap
		if(!DraggedNodeBmp.CreateCompatibleBitmap(&DraggedNodeDC, rectBounding.Width(), rectBounding.Height()))
			return NULL;

		pBitmapOldMemDCBitmap = MemoryDC.SelectObject( &DraggedNodeBmp );
		pFontOld = MemoryDC.SelectObject(GetFont());

		CBrush brush(RGB(255,255,255));
		MemoryDC.FillRect(&rectBounding,&brush);
		MemoryDC.SetBkColor(RGB(255,255,255));
		MemoryDC.SetBkMode(TRANSPARENT);
		MemoryDC.SetTextColor(RGB(0,0,0));

		// Search through array list
		for( nIdx = 0; nIdx < nNumSelected; nIdx++)
		{
			hItem = m_vSelItem[nIdx];
			int nImg = 0,nSelImg=0;
			GetItemImage(hItem,nImg,nSelImg);
			HICON hIcon = pImageList->ExtractIcon(nImg);
			//cdcMemory.DrawIcon(rectTextArea.left,rectTextArea.top,hIcon);
			MemoryDC.MoveTo(rectTextArea.left,rectTextArea.top);
			if( nIdx != nNumSelected-1 )
			{
				MemoryDC.LineTo(rectTextArea.left,rectTextArea.top+18);
			}
			else
			{
				MemoryDC.LineTo(rectTextArea.left,rectTextArea.top+8);
			}
			MemoryDC.MoveTo(rectTextArea.left,rectTextArea.top+8);
			MemoryDC.LineTo(rectTextArea.left+5,rectTextArea.top+8);

			int nLeft = rectTextArea.left;
			rectTextArea.left += 3;
			::DrawIconEx(MemoryDC.m_hDC,rectTextArea.left,rectTextArea.top,hIcon, 16,16,0,NULL,DI_NORMAL);
			rectTextArea.left += cx;
			MemoryDC.Rectangle(rectTextArea);
			MemoryDC.DrawText(GetItemText(hItem), rectTextArea, DT_LEFT| DT_SINGLELINE|DT_NOPREFIX);
			rectTextArea.left = nLeft;
			rectTextArea.OffsetRect(0, rectFirstItem.Height()+2);
			DestroyIcon(hIcon);
		}
		MemoryDC.SelectObject( pFontOld );
		MemoryDC.SelectObject( pBitmapOldMemDCBitmap );
		MemoryDC.DeleteDC();
		// Create imagelist
		pImageListDraggedNode = new CImageList;
		pImageListDraggedNode->Create(rectBounding.Width(), rectBounding.Height(), ILC_COLOR | ILC_MASK, 0, 1); 
		pImageListDraggedNode->Add(&DraggedNodeBmp, RGB(255, 255,255)); 
		return pImageListDraggedNode;
	}
	return NULL;
}

void CDragDropTreeCtrl::OnDrag(CPoint point)
{
	if( m_vSelItem.size() ==  0 )
	{
		return;
	}
	m_bDragging = TRUE;
	UINT nFlags;
	HTREEITEM hItem = HitTest(point,&nFlags);

	m_pImageList = CreateDragImageEx();

	ASSERT (m_pImageList != NULL);

	if (m_pImageList != NULL)
	{
		CRect rect;
		GetItemRect (hItem, rect, TRUE);
		POINT pt;
		pt.x = rect.left+5;
		pt.y = rect.top+5;

		ClientToScreen ( &pt ) ;
		m_pImageList->BeginDrag (0,CPoint(-5,-5));
		m_pImageList->DragEnter (NULL, pt);    
		SetCapture();
		int nEventListenerCount = m_vEventListener.size();
		for( int nEventListenerIdx = 0; nEventListenerIdx < nEventListenerCount; ++nEventListenerIdx )
		{
			m_vEventListener[nEventListenerIdx]->OnDrag();
		}
	}
}

void CDragDropTreeCtrl::OnClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	printf(" * CDragDropTreeCtrl::OnClick() ... \n");

	// ClearSelection();    
}

void CDragDropTreeCtrl::OnControlKeyPress(HTREEITEM hCurItem)
{
	if( m_vSelItem.size() > 0 )
	{
		if( !IsInTheSameLevel(hCurItem) )
		{
			return;
		}
	}

	int nState = (TVIS_SELECTED == GetItemState(hCurItem,TVIS_SELECTED))? 0:TVIS_SELECTED;
	SetItemState(hCurItem,nState,TVIS_SELECTED);
	if( 0 == nState )
	{
		RemoveFromSelectionList(hCurItem);
	}
	else
	{
		m_vSelItem.push_back(hCurItem);
	}
}
void CDragDropTreeCtrl::OnShiftKeyPress(HTREEITEM hCurItem)
{
	if( m_vSelItem.size() > 0 )
	{
		if( !IsInTheSameLevel(hCurItem) )
		{
			return;
		}
	}
	HTREEITEM hItemFrom = m_vSelItem[0];
	SetItemState(hCurItem,TVIS_SELECTED,TVIS_SELECTED);
	SelectItems(hItemFrom,hCurItem);
}

BOOL CDragDropTreeCtrl::IsItemPresent(HTREEITEM hItem)
{
	BOOL bPresent = FALSE;
	SEL_ITEM_LIST::iterator itr;
	for( itr = m_vTempSelItemList.begin(); itr!=m_vTempSelItemList.end(); ++itr )
	{
		if( hItem == (*itr) )
		{
			bPresent = TRUE;
			break;
		}
	}
	return bPresent;
}

BOOL CDragDropTreeCtrl::IsInTheSameLevel(HTREEITEM hItem)
{
	BOOL bInTheSameLevel = TRUE;
	SEL_ITEM_LIST::iterator itr;
	for( itr = m_vSelItem.begin(); itr != m_vSelItem.end(); ++itr )
	{
		if( GetParentItem(hItem) != GetParentItem(*itr) )
		{
			bInTheSameLevel = FALSE;
		}
	}
	return bInTheSameLevel;
}

SEL_ITEM_LIST CDragDropTreeCtrl::GetSelectedItems()
{
	return m_vSelItem;
}

void CDragDropTreeCtrl::RemoveFromSelList(HTREEITEM hItem)
{
	SEL_ITEM_LIST::iterator itr;
	for(  itr = m_vSelItem.begin(); m_vSelItem.end() != itr; ++itr)
	{
		if( (*itr) == hItem )
		{
			m_vSelItem.erase(itr);
			m_vSelItem.clear();
			break;
		}
	}
}

void CDragDropTreeCtrl::AddDragEventListener(CDragEventListener *pListener)
{
	m_vEventListener.push_back(pListener);
}

void CDragDropTreeCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{	

	CTreeCtrl::OnLButtonDblClk(nFlags, point);
}

void CDragDropTreeCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_vSelItem.size() > 0)
	{
		if(GetParentItem(m_vSelItem[0]) == NULL)
		{
			return;
		}

		/*
		((CEQP__STARTDlg*) m_pParentWnd)->OnDblclkTreeNode(m_vSelItem[0]);
		*/
	}

	*pResult = 0;
}