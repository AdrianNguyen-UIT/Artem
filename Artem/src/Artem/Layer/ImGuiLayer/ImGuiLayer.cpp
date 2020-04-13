#include "atpch.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "examples/imgui_impl_opengl3.h"
#include "examples/imgui_impl_glfw.h"

#include "Artem/Core/Application.h"
#include "GLFW/glfw3.h"
namespace Artem
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}


	void ImGuiLayer::OnUpdate()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			bool open = true;
			ImGui::Begin("hello", &open);
			if (ImGui::Button("Button"))
			{
				AT_APP_INFO("BUTTON PRESSED!");
			}
			static char buf[64 * 50] = "";
			ImGui::InputTextMultiline("Input", buf, IM_ARRAYSIZE(buf), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 10));
			ImGui::End();
		}
		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnAttach()
	{
		//Setup ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;

		//ImFont* font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Roboto-Medium.ttf", 24.0f);
		ImFont* font = io.Fonts->AddFontFromFileTTF("C:\\Devs\\Artem\\Artem\\vendor\\ImGui\\misc\\fonts\\Roboto-Medium.ttf", 16.0f);

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;

		//Setup ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();


		Application& app = Application::GetApplication();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetOriginalWindow());
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		const char* glsl_version = "#version 330";
		ImGui_ImplOpenGL3_Init(glsl_version);
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		AT_APP_TRACE("Layer: {0} {1}", m_LayerName, event);
	}
}