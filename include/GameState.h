//
// Created by shuviu on 3/9/25.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <chrono>
#include <functional>
#include <thread>

#include "InputHandlerAsync.h"
#include "Scene.h"
using namespace std::chrono;
using namespace Scenes;
using namespace IO;

namespace Gamestate {
    class GameState {
    private:
        Scene* currScene_{};
        int keyPressed_;
        bool isRunning_;
        bool keyUpdate_;
        static void StartInputHandlerAsync(InputHandlerAsync *inputHandler);
        int FetchPressedKey(InputHandlerAsync *inputHandler);

    public:
        GameState();
        void Initialize(const std::function<int(GameState*)>& UpdateLoop);
        int GetKeyPressed();
        [[nodiscard]] Scene* GetScene() const;
        [[nodiscard]] bool GetKeyUpdate() const;
        void SetScene(Scene* scene);
    };
}

#endif //GAMESTATE_H
