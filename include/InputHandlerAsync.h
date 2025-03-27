//
// Created by shuviu on 3/13/25.
//

#ifndef INPUTHANDLERASYNC_H
#define INPUTHANDLERASYNC_H
#include <atomic>
#include <bits/std_thread.h>

namespace IO {
    class InputHandlerAsync {
    private:
        std::atomic<int> inputKey_;
        std::atomic<bool> keyUpdate_;
        std::atomic<bool> threadStopped_;

    public:
        // Default constructor
        InputHandlerAsync();
        ~InputHandlerAsync();

        void Start();
        void Stop();
        int InputKey();
        bool KeyUpdate() const;


    };
}

#endif //INPUTHANDLERASYNC_H
