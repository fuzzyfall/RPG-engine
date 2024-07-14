#ifndef MAINMENUFUNCTIONS_H
#define MAINMENUFUNCTIONS_H

#pragma once
#include <vector>
#include "Structures.h"

void MainMenu();
void StartNewSaveFile(std::vector<Game>& games);
void LoadSaveFile(std::vector<Game>& games);
void LoadAndPlayGame(std::vector<Game>& games); 
void CreateNewGame(std::vector<Game>& games);
void EditGame(std::vector<Game>& games);
void DeleteSaveFile(std::vector<Game>& games);
void DeleteGame(std::vector<Game>& games);
void QuitProgram();

#endif
