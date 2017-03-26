 /**
 * \file TreeComponent.h
 *
 * \author Tianhang Sun
 *
 * the tree component class
 */

#pragma once
#include <vector>
#include <memory>

class CActualTree;
class CLimb;

/**the tree component class*/
class CTreeComponent
{
public:
	CTreeComponent();
	virtual ~CTreeComponent();
	/** \brief Copy constructor disabled */
	CTreeComponent(const CTreeComponent &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTreeComponent &) = delete;

	void AddChild(std::shared_ptr<CTreeComponent> child);

	/** \brief Set the parent
	* \param parent New parent pointer */
	void SetParent(CTreeComponent *parent) { mParent = parent; }

	/** \brief Draw the component
	* \param graphics Graphics object to draw on 
	* \param angle we're setting
	* \param x the location
	* \param y the location*/
	virtual void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y) = 0;

	/** \brief grow the tree*/
	virtual void Grow() = 0;

	/**get the current frame
	* \returns the frame number*/
	int GetFrame(){ return mCurrentFrame; }

	/**setter for current frame
	* \param frame the frame we're setting to*/
	void SetFrame(int frame){ mCurrentFrame = frame; }

	/**set the component to a tree
	* \param tree we're setting to*/
	void SetTree(CActualTree *tree){ mTree = tree; }

	/**set angle for this component
	* \param angle we're setting to*/
	void SetAngle(double angle){ mAngle = angle; }

	/**getter for angle
	* \returns the angle*/
	double GetAngle(){ return mAngle; }

	/**get type function
	* \returns apple when it's an apple, nothing otherwise*/
	std::wstring GetType(){ return mType; }
	void ClearApple();
	void SetWindSpeed(double speed);

protected:
	int mCurrentFrame = 0;					///< the current frame
	double mAngle = 0;						///< the current angle
	double mWindSpeed = 0;					///< the current wind speed
	std::vector<std::shared_ptr<CTreeComponent>> mChildren;		///< vector that stores the children
	CActualTree *mTree = nullptr;			///< the tree set to
	CTreeComponent *mParent = nullptr;		///< parent of a member
	std::wstring mType = L"";				///< type, apple if it's an apple

};

