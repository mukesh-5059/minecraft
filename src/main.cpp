#include "Settings.hpp"
#include <VoxelEngine.hpp>
#include <iostream>


int main(){
    std::cout << "Window Resolution: " <<RESOLUTION.x << " | " << RESOLUTION.y << std::endl;
    VoxelEngine app;
    app.run();
}