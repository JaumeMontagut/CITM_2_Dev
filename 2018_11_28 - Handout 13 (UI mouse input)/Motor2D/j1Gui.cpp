#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	for (uint i = 0; i < MAX_UI_OBJ; ++i) {
		if (uiObjects[i] != nullptr) {
			uiObjects[i]->PreUpdate();
		}
	}

	if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN) {
		for (uint i = 0; i < MAX_UI_OBJ; ++i) {
			//App->input->GetMousePosition()
			//if () {

			//}
			if (uiObjects[i] != nullptr) {
				uiObjects[i]->clickedFunction(uiObjects[i]->string.GetString());
			}
		}
	}
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	for (uint i = 0; i < MAX_UI_OBJ; ++i) {
		if (uiObjects[i] != nullptr) {
			uiObjects[i]->PostUpdate();
		}
	}
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

Button * j1Gui::CreateButton(SDL_Texture * tex, const SDL_Rect & idleSection, const SDL_Rect & hoverSection, const SDL_Rect & pressedSection, const iPoint & position)
{
	Button* ret = nullptr;
	int index = FindEmptyPosition();
	if (index != -1) {
		uiObjects[index] = ret = new Button(tex, idleSection, hoverSection, pressedSection, position, index);
	}
	return ret;
}

Text * j1Gui::CreateText(const uint size, const SDL_Color & color, p2SString string, const iPoint & position)
{
	Text* ret = nullptr;
	int index = FindEmptyPosition();
	if (index != -1) {
		uiObjects[index] = ret = new Text(size, color, string, position, index);
	}
	return ret;
}

CheckBox * j1Gui::CreateCheckbox(const iPoint & position)
{
	CheckBox* ret = nullptr;
	int index = FindEmptyPosition();
	if (index != -1) {
		uiObjects[index] = ret = new CheckBox(position, index);
	}
	return ret;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

int j1Gui::FindEmptyPosition() {
	for (uint i = 0; i < MAX_UI_OBJ; ++i)
	{
		if (uiObjects[i] == nullptr)
		{
			objNum++;
			return i;
		}
	}
	LOG("Reached maximum object capacity, returning -1");
	return -1;
}

// class Gui ---------------------------------------------------

UIObject::UIObject(const iPoint & position, int index) : position(position), index(index)
{
	string = "hello";
}

bool UIObject::PreUpdate()
{
	return false;
}

bool UIObject::PostUpdate()
{
	return false;
}

bool UIObject::OnMouseClick()
{
	return false;
}

//iPoint UIObject::GetGlobalPos()
//{
//	anchoredElement.GetGlobalPos() + localPos;
//	return iPoint();
//}

Button::Button(SDL_Texture * tex, const SDL_Rect & idleSection, const SDL_Rect & hoverSection, const SDL_Rect & pressedSection, const iPoint & position, int index) : tex(tex), idleSection(idleSection), hoverSection(hoverSection), pressedSection(pressedSection) , UIObject(position, index)
{
	currSection = (SDL_Rect *)&this->idleSection;//TODO: Simply pass SDL_Rect * no const SDL_Rect *
}

bool Button::PostUpdate()
{
	SDL_Rect screenRect;
	screenRect.x = position.x;
	screenRect.y = position.y;
	screenRect.w = currSection->w;
	screenRect.h = currSection->h;
	SDL_RenderCopy(App->render->renderer, tex, currSection, &screenRect);//TODO: Create a new function instead of blit for ui (they aren't drawn in the world position, they are drawn directly on top of the screen)
	return true;
}

Text::Text(uint size, const SDL_Color & color, p2SString & string, const iPoint & position, int index) : size(size), color(color), string(string), UIObject(position, index)
{
}

bool Text::PostUpdate()
{
	//TODO: Render font
	SDL_Texture *tex = App->font->Print(string.GetString());
	SDL_Rect screenRect;
	screenRect.w = 100;
	screenRect.h = 50;
	screenRect.x = position.x - screenRect.w * 0.5f;
	screenRect.y = position.y;
	SDL_RenderCopy(App->render->renderer, tex, NULL, &screenRect);
	return true;
}

CheckBox::CheckBox(const iPoint & position, int index) : UIObject(position, index)
{
}
