/**
 * \file TreeFactory.h
 *
 * \author Charles Owen
 *
 * Tree factory class. Creates Tree and Basket objects
 */

#pragma once

#include <memory>
#include "ActualTree.h"
#include "ActualBasket.h"

class CTree;
class CBasket;


/**
 * Tree factory class. Creates Tree and Basket objects
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CTreeFactory
{
public:
    CTreeFactory();
    ~CTreeFactory();

	std::shared_ptr<CActualTree> CreateTree();
    std::shared_ptr<CActualBasket> CreateBasket();
};

