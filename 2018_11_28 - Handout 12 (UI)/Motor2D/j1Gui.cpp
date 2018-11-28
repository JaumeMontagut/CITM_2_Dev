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

Image * j1Gui::CreateImage(SDL_Texture * tex, const SDL_Rect & section, const iPoint & position)
{
	Image* ret = nullptr;
	int index = FindEmptyPosition();
	if (index != -1) {
		uiObjects[index] = ret = new Image(tex, section, position, index);
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

Button * j1Gui::CreateButton(const iPoint & position)
{
	Button* ret = nullptr;
	int index = FindEmptyPosition();
	if (index != -1) {
		uiObjects[index] = ret = new Button(position, index);
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
}

bool UIObject::PreUpdate()
{
	return false;
}

bool UIObject::PostUpdate()
{
	return false;
}

Image::Image(SDL_Texture * tex, const SDL_Rect & rect, const iPoint & position, int index) : tex(tex), section(rect) , UIObject(position, index)
{

}

bool Image::PostUpdate()
{
	SDL_Rect screenRect;
	screenRect.x = position.x;
	screenRect.y = position.y;
	screenRect.w = section.w;
	screenRect.h = section.h;
	SDL_RenderCopy(App->render->renderer, tex, &section, &screenRect);//TODO: Create a new function instead of blit for ui (they aren't drawn in the world position, they are drawn directly on top of the screen)
	return true;
}

Text::Text(uint size, const SDL_Color & color, p2SString & string, const iPoint & position, int index) : size(size), color(color), string(string), UIObject(position, index)
{
}

bool Text::PostUpdate()
{
	//TODO: Render font
	return true;
}

CheckBox::CheckBox(const iPoint & position, int index) : UIObject(position, index)
{
}

Button::Button(const iPoint & position, int index) : UIObject(position, index)
{
}
