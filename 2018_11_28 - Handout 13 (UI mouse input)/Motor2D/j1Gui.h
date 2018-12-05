#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

class UIObject {
	//Variables
public:
	int index = -1;//The index of this object in the factory (j1Gui) UIObject list
	iPoint position;
	j1MouseState state;//Determines is above the specified object (similar to KeyStates)
	p2SString string;
	void(*clickedFunction)(p2SString);//A pointer to the function that's going to be called when we click the UIObject
	//Methods
public:
	UIObject(const iPoint & position, int index);//TODO: Add function pointer to execute "OnMouseClick"

	virtual bool PreUpdate();
	//virtual bool Update();//No update method provided in factory, maybe Ric recommends not to use it?
	virtual bool PostUpdate();

	//virtual bool OnMouseEnter();
	//virtual bool OnMouseHover();
	//virtual bool OnMouseExit();
	virtual bool OnMouseClick();
	iPoint GetGlobalPos();
};

class Button : public UIObject {
	//Variables
private:
	SDL_Texture * tex = nullptr;
	SDL_Rect * currSection = nullptr;
	SDL_Rect idleSection;
	SDL_Rect hoverSection;
	SDL_Rect pressedSection;
	//Animation animations[j1MouseState::MAX];
	//Methods
public:
	Button(SDL_Texture * tex, const SDL_Rect & idleSection, const SDL_Rect & hoverSection, const SDL_Rect & pressedSection, const iPoint & position, int index);
	virtual bool PostUpdate();
};

class Text : public UIObject {
	//Variables
private:
	//_TTF_Font font;
	SDL_Color color;
	uint size;
	p2SString string;
	//Methods
public:
	Text(uint size, const SDL_Color & color, p2SString &string, const iPoint & position, int index);//TODO: Add font
	virtual bool PostUpdate();
};

class CheckBox : public UIObject {
	//Methods
public:
	CheckBox(const iPoint & position, int index);
};

// ---------------------------------------------------
class j1Gui : public j1Module
{
	//Variables
private:
	SDL_Texture* atlas;
	p2SString atlas_file_name;
	UIObject * uiObjects [MAX_UI_OBJ];
	uint objNum = 0u;

	//Methods
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	Button* CreateButton(SDL_Texture * tex, const SDL_Rect & idleSection, const SDL_Rect & hoverSection, const SDL_Rect & pressedSection, const iPoint & position);
	Text* CreateText(const uint size, const SDL_Color& color, p2SString string, const iPoint & position);//TODO: Add font
	Button* CreateButton(const iPoint & position);
	CheckBox* CreateCheckbox(const iPoint & position);

	const SDL_Texture* GetAtlas() const;


private:
	int FindEmptyPosition();

};

#endif // __j1GUI_H__