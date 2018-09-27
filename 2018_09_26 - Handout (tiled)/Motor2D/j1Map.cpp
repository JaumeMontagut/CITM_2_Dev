#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)
	std::list<Tileset>::const_iterator iterator;
	for (iterator = tilesetList.begin(); iterator != tilesetList.end(); ++iterator) {
		App->render->Blit(iterator->tilesetImage, 0, 0);
	}
	//Source (iterate on a std list): http://www.cplusplus.com/forum/general/22957/
}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map
	

	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		LoadMap(map_file.child("map"), file_name);
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	LoadTilesets(map_file.child("map"));

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

bool j1Map::LoadMap(pugi::xml_node &node, const char * file_name) {
	Map newMap;
	//Orientation
	if (node.attribute("orientation").as_string() == "orthogonal") {
		newMap.orientation = mapOrientation::orthogonal;
	}
	else if (node.attribute("orientation").as_string() == "isometric") {
		newMap.orientation = mapOrientation::isometric;
	}
	else {
		newMap.orientation = mapOrientation::invalid;
	}
	//Render order
	if (node.attribute("renderorder").as_string() == "right-up") {
		newMap.renderOrder = renderOrder::rightUp;
	}
	else if (node.attribute("renderorder").as_string() == "right-down") {
		newMap.renderOrder = renderOrder::rightDown;
	}
	else if (node.attribute("renderorder").as_string() == "left-up") {
		newMap.renderOrder = renderOrder::leftUp;
	}
	else if (node.attribute("renderorder").as_string() == "left-down") {
		newMap.renderOrder = renderOrder::leftDown;
	}
	else {
		newMap.renderOrder = renderOrder::invalidRenderOrder;
	}
	newMap.renderOrder;
	newMap.width = node.attribute("width").as_int();
	newMap.height = node.attribute("height").as_int();
	newMap.tileWidth = node.attribute("tilewidth").as_int();
	newMap.tileHeight = node.attribute("tileheight").as_int();
	mapList.push_back(newMap);

	//For some reason renderOrder and orientation don't work when checket (they don't seem to be different than invalid even thought the names are correctly written)
	if (newMap.width != 0 && newMap.height != 0 && newMap.tileWidth != 0 && newMap.tileHeight != 0) {
		LOG("Succesfully parsed map XML file: %s", file_name);
		LOG("width: %i  height: %i", newMap.width, newMap.height);
		LOG("tile_width: %i tile_height: %i", newMap.tileWidth, newMap.tileHeight);
	}
	else {
		LOG("Map not parsed successfully");
	}
	return true;
}

bool j1Map::LoadTilesets(pugi::xml_node &node) {
	for (pugi::xml_node tileset = node.child("tileset"); tileset; tileset = tileset.next_sibling("tileset")) {
		Tileset newTileset;
		newTileset.tilesetImage = App->tex->Load(tileset.child("image").attribute("source").as_string());
		newTileset.firstGid = tileset.attribute("firstgid").as_int();
		newTileset.name = tileset.attribute("name").as_string();
		newTileset.tileWidth = tileset.attribute("tilewidth").as_int();
		newTileset.tileHeight = tileset.attribute("tileheight").as_int();
		newTileset.spacing = tileset.attribute("spacing").as_int();
		newTileset.margin = tileset.attribute("margin").as_int();
		tilesetList.push_back(newTileset);

		//INFO: name can't be checked as it doesn't have a default value
		if (newTileset.tilesetImage != nullptr && newTileset.firstGid != 0 && newTileset.tileWidth != 0 && newTileset.tileHeight != 0 && newTileset.spacing != -1 && newTileset.margin != -1) {
			LOG("Tileset ----");
			LOG("name: %s firstgid: %i", newTileset.name, newTileset.firstGid);
			LOG("tile width: %s tile height: %i", newTileset.tileWidth, newTileset.tileHeight);
			LOG("spacing %i margin: %i", newTileset.spacing, newTileset.margin);
		}
		else {
			LOG("Tileset not parsed succesfully");
		}
	}
	//TODO: Remove front and make a decent loop
	return true;
}

