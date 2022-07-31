#include <SparkEngine/Core/Dll.hpp>

#include <SparkEngine/Core/Framework/ApplicationLayer.hpp>

int main()
{
    ApplicationLayer* layer = Dll::import<ApplicationLayer>("Editor", "createLayer")();
    delete layer;
}