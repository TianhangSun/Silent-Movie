/**
 * \file TreeDrawable.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "TreeDrawable.h"
#include "TreeFactory.h"
#include "TreeSeedDlg.h"

/**constructor
* \param name is the file name*/
CTreeDrawable::CTreeDrawable(const std::wstring &name) : CDrawable(name)
{
	CTreeFactory factory;
	mTree = factory.CreateTree();
}

/**destructor*/
CTreeDrawable::~CTreeDrawable()
{
}

/**draw function
* \param graphics*/
void CTreeDrawable::Draw(Gdiplus::Graphics *graphics)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);		// Where you want the tree
	graphics->ScaleTransform((float)mScale, (float)mScale);
	mTree->SetRootLocation(0, 0);
	mTree->DrawTree(graphics);
	graphics->Restore(state);

	mTree->SetTreeFrame(mPicture->GetTimeline()->GetCurrentFrame()-100);
	mTree->DrawTree(graphics);
}

/**set seed function, pop up the dialog box*/
void CTreeDrawable::SetSeed()
{
	CTreeSeedDlg dlg(mTree);
	if (dlg.DoModal() == IDOK) {
		mTree->SetTreeFrame(0);
		mTree->SetTreeFrame(mPicture->GetTimeline()->GetCurrentFrame() - 100);
	}
}