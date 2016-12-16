/**
 * \file BugFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "stdafx.h"
#include "BugFactory.h"
#include "Bug.h"
#include "Basket.h"


using namespace std;

/**
 * Constructor
 */
CBugFactory::CBugFactory()
{
}


/**
 * Destructor
 */
CBugFactory::~CBugFactory()
{
}


/**
 * Create a bug object
 * \returns Object of type CBug
 */
std::shared_ptr<CBugActual> CBugFactory::CreateBug()
{
	return make_shared<CBugActual>();
}


/**
 * Create a Basket object
 * \returns Object of type CBasket
 */
std::shared_ptr<CBasketActual> CBugFactory::CreateBasket()
{
    return make_shared<CBasketActual>();
}

