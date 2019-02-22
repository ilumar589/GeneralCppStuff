#pragma once

#include <string>

class Bird
{
public:
	Bird();
	void set_song(const std::string& song);
	void set_song(std::string&& song);
private:
	std::string m_Song;
};

void move_and_copy_examples();
