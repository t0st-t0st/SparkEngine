#include <SparkEngine/Core/Framework/ApplicationLayer.hpp>
#include <SparkEngine/Core/Dll.hpp>

int main()
{
    ApplicationLayer* layer = Dll::import<ApplicationLayer>("Editor", "createLayer")();
    delete layer;
}