///
/// anax
/// Copyright (C) 2013 Anax Creations. All rights reserved.
///
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the
/// use of this software.
///
/// Permission is hereby granted, free of charge, to any person
/// obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///	   and must not be misrepresented as being the original software.
///
/// 3. The above copyright notice and this permission notice shall be included in
///    all copies or substantial portions of the Software.
///

#include "EntityFactory.h"

#include <cassert>

#include "World.h"


namespace anax
{
	EntityFactory::EntityFactory()
	: _aliveCount(0),
	_totalCreatedCount(0),
	_totalDestroyedCount(0)
	{
		/* do nothing */
	}
	
	EntityFactory::~EntityFactory()
	{
		/* do nothing */
	}
	
	
	
	EntityPtr EntityFactory::createEntity(World& world)
	{		
		++_totalCreatedCount;
		++_aliveCount;
		return new Entity(world);
	}
	
	void EntityFactory::destroyEntity(EntityPtr e)
	{
		delete &e;					// delete the entity
		
		--_aliveCount;
		++_totalDestroyedCount;
	}
	
	size_t EntityFactory::getCreatedEntityCount() const
	{
		return _totalCreatedCount;
	}
	
	size_t EntityFactory::getDestroyedEntityCount() const
	{
		return _totalDestroyedCount;
	}
	
	size_t EntityFactory::getAliveEntityCount() const
	{
		return _aliveCount;
	}
	
	void EntityFactory::clearCountData()
	{
		_totalCreatedCount = _totalDestroyedCount = _aliveCount = 0;
	}
}
