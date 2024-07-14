#ifndef EDITOR_MENU_FUNCTIONS_H
#define EDITOR_MENU_FUNCTIONS_H

#include "Structures.h"

void ShowEditorMenu(Game& game);
void CreateNewZone(Game& game, std::vector<Zone>& zones);
void EditExistingZone(Game& game, std::vector<Zone>& zones);
void DeleteExistingZone(Game& game);

#endif // EDITOR_MENU_FUNCTIONS_H
