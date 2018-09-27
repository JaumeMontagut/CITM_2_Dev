#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include <list>
//#include "p2SString.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct Tileset {
	SDL_Texture* tilesetImage;
	uint firstGid = 0;
	p2SString name;
	uint tileWidth = 0;
	uint tileHeight = 0;
	int spacing = -1;
	int margin = -1;
};

// TODO 1: Create a struct needed to hold the information to Map node
enum class mapOrientation {
	invalid,
	orthogonal,
	isometric
};

enum class renderOrder {
	invalidRenderOrder = 0,
	rightUp,
	rightDown,
	leftUp,
	leftDown
};

struct Map{
	mapOrientation orientation = mapOrientation::invalid;
	renderOrder renderOrder = renderOrder::invalidRenderOrder;
	uint width = 0;
	uint height = 0;
	uint tileWidth = 0;
	uint tileHeight = 0;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	bool LoadMap(pugi::xml_node& node);
	bool LoadTilesets(pugi::xml_node& node);

private:


public:

	// TODO 1: Add your struct for map info as public for now
	std::list<Tileset> tilesetList;
	std::list<Map>mapList;

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
	
};

#endif // __j1MAP_H__