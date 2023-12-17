#include "MainMenuScene.h"

#include <SceneGraph/Scene.h>
#include <Components/RenderComponents/CameraComponent.h>
#include <Camera.h>
#include <Components/Transform/Transform.h>
#include <Components/RenderComponents/DirectionalLightComponent.h>
#include <Components/RenderComponents/UIComponents/CanvasComponent.h>
#include <Components/RenderComponents/UIComponents/CanvasActions.h>
#include <Components/Audio/AudioListener.h>

#include "../Components/InfoUI.h"
#include "../Components/WindowManager.h"
#include "../Components/FreeCamMovement.h"

void unag::MainMenuScene::Load(leap::Scene& scene)
{
	leap::GameObject* pDirLight{ scene.CreateGameObject("Directional Light") };
	pDirLight->AddComponent<leap::DirectionalLightComponent>();
	pDirLight->GetTransform()->SetWorldRotation(60.0f, 0.0f, 0.0f);

	leap::GameObject* pCameraObj{ scene.CreateGameObject("Main Camera") };
	const leap::CameraComponent* pMainCamera{ pCameraObj->AddComponent<leap::CameraComponent>() };
	pMainCamera->SetAsActiveCamera(true);
	pMainCamera->GetData()->SetFarPlane(1000.0f);
	pCameraObj->AddComponent<leap::AudioListener>();
	pCameraObj->GetTransform()->SetLocalPosition(0.0f, 5.0f, -5.0f);
	pCameraObj->AddComponent<FreeCamMovement>();

	const auto canvas{ scene.CreateGameObject("Canvas") };
	leap::CanvasComponent* pCanvas{ canvas->AddComponent<leap::CanvasComponent>() };
	pCanvas->SetReferenceResolution({ 1920,1080 });
	pCanvas->SetMatchMode(leap::CanvasComponent::MatchMode::MatchHeight);
	canvas->AddComponent<leap::CanvasActions>();

	const auto info{ scene.CreateGameObject("Info") };
	info->AddComponent<InfoUI>();

	const auto windowControls{ scene.CreateGameObject("Window") };
	windowControls->AddComponent<WindowManager>();
}
