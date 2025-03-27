//
// Created by shuviu on 3/12/25.
//

#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <vector>

namespace Rendering {
    class ScreenRenderer {
    public:
        // Render the given Frame to the std::out at x=0 and y=0
        static void RenderFrame(const std::vector<std::vector<char>>&);
        // Render the given frame to the std::out at the specified position
        static void RenderFrame(const std::vector<std::vector<char>> &, const std::tuple<int, int> &);
        // Resets the provided area and then renders the given frame to the std::out at the specified position
        static void RenderFrame(const std::vector<std::vector<char>>&, const std::tuple<int, int>&, const std::tuple<int, int>&, const std::tuple<int, int>&);
    };
}



#endif //SCREENRENDERER_H
