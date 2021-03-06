#ifndef SDLINPUTHANDLER_H
#define SDLINPUTHANDLER_H

#include "inputhandler.h"
#include "SDL.h"
#include <cstdint>

namespace game {

class SDLInputHandler : public InputHandler
{
public:
  SDLInputHandler();

  /**
   * @brief Handle player input for one frame.
   */
  void handle() override;

  bool isModifierPressed(ModifierKey modifier) const override;

  bool applicationHasFocus() const override;

private:
  SDL_Event mEvent;
  bool mHasFocus;
};

} // namespace game

#endif // SDLINPUTHANDLER_H
