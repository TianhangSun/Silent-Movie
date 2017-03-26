/**
 * \file TreeComponent.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "TreeComponent.h"
#include "Limb.h"

/**constructor*/
CTreeComponent::CTreeComponent()
{
}

/**destructor*/
CTreeComponent::~CTreeComponent()
{
}

/**
* \brief Add a child to this component
* \param child The child to add
*/
void CTreeComponent::AddChild(std::shared_ptr<CTreeComponent> child)
{
	mChildren.push_back(child);
	child->SetParent(this);
}

/**delete all apples*/
void CTreeComponent::ClearApple()
{
	for (int i = 0; i < mChildren.size(); i++)
	{
		if (mChildren[i]->GetType() != L"")
			mChildren.erase(mChildren.begin() + i);
		else
			mChildren[i]->ClearApple();
	}
}

/**set wind speed for each child
* \param speed the wind speed*/
void CTreeComponent::SetWindSpeed(double speed)
{
	mWindSpeed = speed;
	for (auto child : mChildren)
	{
		child->SetWindSpeed(speed);
	}
}