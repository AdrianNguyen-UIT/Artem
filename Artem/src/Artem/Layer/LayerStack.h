#pragma once
#include "Layer.h"
namespace Artem
{
	class LayerStack
	{
    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex;

    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin();
        std::vector<Layer*>::iterator end();
        std::vector<Layer*>::reverse_iterator rbegin();
        std::vector<Layer*>::reverse_iterator rend();

	};
}