#ifndef MOVINGPHYSICSCOMPONENT_H
#define MOVINGPHYSICSCOMPONENT_H

#include "component.h"
#include "gamevector.h"
#include "entity.h"
#include "physicscomponent.h"
#include <cstdint>
#include <vector>

namespace game {

class GameState;
class Tile;
template<typename T> class Rect;

class MovingPhysicsComponent : public PhysicsComponent
{
public:
  static const float GRAVITY;
  static const float FALL_SPEED;

  MovingPhysicsComponent(Entity &owner, bool isObstacle=true, bool hasGravity=true);

  ~MovingPhysicsComponent();

  void update(std::uint32_t step, GameState &game) override;

  Vector<float> &velocity() { return mVelocity; }

  bool isOnGround();

  void setGravityEnabled(bool enabled);

  const std::vector<std::pair<Vector<int>, Vector<int>>> &getCollidingTiles() const;

  void collide(PhysicsComponent &other);
  void collide(Tile &tile, const Vector<int> &location);

private:
  void collisionResponse(const Vector<int> &normal);

private:
  Vector<float> mVelocity;
  Vector<float> mRemainder;
  bool mIsOnGround;
  bool mHasGravity;

  // Pair: tile position => collision normal
  std::vector<std::pair<Vector<int>, Vector<int>>> mCollidingTiles;
};

} // namespace game

#endif // MOVINGPHYSICSCOMPONENT_H
