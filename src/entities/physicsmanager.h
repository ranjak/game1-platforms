#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include <vector>

namespace game {

class MovingPhysicsComponent;
class StaticPhysicsComponent;
class Level;
template<typename T> class Vector;

class PhysicsManager
{
public:
  PhysicsManager(Level &level);

  bool moveObject(MovingPhysicsComponent *object, const Vector<float> &dest);

  void checkCollisions(MovingPhysicsComponent *object);

  void addComponent(MovingPhysicsComponent *cmp);
  void removeComponent(MovingPhysicsComponent *cmp);

  void addComponent(StaticPhysicsComponent *cmp);
  void removeComponent(StaticPhysicsComponent *cmp);

private:
  std::vector<MovingPhysicsComponent *> mMovingComps;
  std::vector<StaticPhysicsComponent *> mStaticComps;
  Level &mLevel;
};

} // namespace game

#endif // PHYSICSMANAGER_H
