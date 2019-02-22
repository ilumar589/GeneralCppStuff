#include "BirdExample.h"

Bird::Bird()
{
}

void Bird::set_song(const std::string & song)
{
	m_Song = song;
}

void Bird::set_song(std::string && song)
{
	m_Song = std::move(song);
}

void move_and_copy_examples()
{
	std::string a_song{ "A song!" };

	Bird b1{};
	b1.set_song(std::move(a_song));
}
