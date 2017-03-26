/**
 * \file TreeFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "stdafx.h"
#include "TreeFactory.h"
#include "Tree.h"
#include "Limb.h"
#include "Basket.h"

using namespace std;

/**
 * Constructor
 */
CTreeFactory::CTreeFactory()
{
}


/**
 * Destructor
 */
CTreeFactory::~CTreeFactory()
{
}


/**
 * Create a Tree object
 * \returns Object of type CTree
 */
std::shared_ptr<CActualTree> CTreeFactory::CreateTree()
{
	auto tree = make_shared<CActualTree>();
    return tree;
}


/**
 * Create a Basket object
 * \returns Object of type CBasket
 */
std::shared_ptr<CActualBasket> CTreeFactory::CreateBasket()
{
    return make_shared<CActualBasket>();
}

