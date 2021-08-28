#include <fstream>
#include <iostream>
#include <vector>
//Denna funktion kopierade jag från stackoverflow och ändrade lite
int calcTrees(std::vector<std::string> map, int right, int down){
	int count = 0;
	int y = 0;
	int x = 0;
	while (y < map.size()){
		if (map[y][x] == '#')
			count++;
		y += down;
		x += right;
		if (x >= map[y].size()){
			x-=map[y].size();
		}
	}
	return count;
}

std::vector<std::string> checkTree(std::string file){
	std::vector<std::string> result;
	std::ifstream inFile;
	inFile.open(file);
	std::string line;
	while (inFile >> line){
		result.push_back(line);
	}
	inFile.close();
	return result;
}


int main(){
    std::vector<std::string> input;
	std::ifstream ifs;
	ifs.open("data.txt");
	std::string line;
	while (ifs >> line){
		input.push_back(line);
	}
	ifs.close();
	std::cout << calcTrees(input, 3, 1) << std::endl;

	return 0;
}