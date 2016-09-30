#include "movementcomponent.h"
#include "entity.h"
#include "gamestate.h"
#include "world/level.h"
#include <cmath>

namespace game {

MovementComponent::MovementComponent(Entity &entity) :
  mVelocity(0.f, 0.f),
  mRemainder(0.f, 0.f),
  mEntity(entity)
{

}

void MovementComponent::update(uint32_t step, GameState &game)
{
  Rect<float> box = mEntity.getGlobalBox();
  // Only use integers for position. Store fractional part in a remainder.
  mRemainder.x += mVelocity.x * step / 1000.f;
  mRemainder.y += mVelocity.y * step / 1000.f;

  Vector<float> destination(0.f, 0.f);
  mRemainder.x = std::modf(mRemainder.x, &destination.x);
  mRemainder.y = std::modf(mRemainder.y, &destination.y);

  destination.x += box.x;
  destination.y += box.y;

  game.getLevel().tryMoving(mEntity, destination);

  if (mEntity.isCollidable())
    game.getLevel().handleCollisions(mEntity);
}

Vector<float> &MovementComponent::velocity()
{
  return mVelocity;
}



} // namespace game