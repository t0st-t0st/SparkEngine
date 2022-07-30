#pragma once

#include <SparkEngine/Editor/Export.hpp>

#include <SparkEngine/Core/Framework/ApplicationLayer.hpp>

class EDITOR_API EditorLayer : public ApplicationLayer
{
public:
    EditorLayer();
    ~EditorLayer();
};

extern "C" EDITOR_API ApplicationLayer* createLayer()
{
    return new EditorLayer();
}