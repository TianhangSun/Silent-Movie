/**
 * \file TreeDrawable.h
 *
 * \author Tianhang Sun
 *
 * adaptor class, use the tree in treelib
 */

#pragma once
#include "Drawable.h"
#include "Tree.h"
#include "picture.h"
#include <memory>

/**the tree drawable class*/
class CTreeDrawable :
	public CDrawable
{
public:
	CTreeDrawable(const std::wstring &name);
	virtual ~CTreeDrawable();

	/** \brief Default constructor disabled */
	CTreeDrawable() = delete;
	/** \brief Copy constructor disabled */
	CTreeDrawable(const CTreeDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTreeDrawable &) = delete;

	/**hit test, don't need it for the tree
	* \param pos the position
	* \returns false*/
	bool HitTest(Gdiplus::Point pos){ return false; }
	void Draw(Gdiplus::Graphics *graphics);

	/**set the frame to tree
	* \param frame the current frame*/
	void SetTreeFrame(int frame){ mCurrentFrame = frame; }

	/**set the picture
	* \param p the picture*/
	void SetPicture(std::shared_ptr<CPicture> p){ mPicture = p; }

	/**set the tree seed directly
	* \param seed want to set*/
	void SetSeed(int seed){ mTree->SetSeed(seed); }

	/**set the scale
	* \param scale of the tree*/
	void SetScale(double scale){ mScale = scale; }

	/**harvest, call harvest in actual tree
	* \returns vector of fruit*/
	std::vector<std::shared_ptr<CFruit>> Harvest(){ return mTree->Harvest(); }

	void SetSeed();

	/**save seed to XML
	* \returns seed*/
	int SaveSeed(){ return mTree->GetSeed(); }

	/**load seed from XML
	* \param seed want to set*/
	void LoadSeed(int seed){ mTree->SetSeed(seed); }

private:
	std::shared_ptr<CTree> mTree;			///< pointer to the tree
	int mCurrentFrame = 0;					///< the current frame 
	std::shared_ptr<CPicture> mPicture;		///< pointer to the picture
	double mScale = 0.8;					///< default scale of tree
};

