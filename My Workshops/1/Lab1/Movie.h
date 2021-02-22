//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       1 (Lab)
// Date:           22/09/2020
//==============================================

#pragma once
#ifndef sdds_MOVIE_H
#define sdds_MOVIE_H

namespace sdds
{
    struct Movie
    {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;
    };

    bool loadMovies();
    bool hasGenre(const Movie* mvp, const char genre[]);
    void displayMovie(const Movie* mvp);
    void displayMoviesWithGenre(const char genre[]);

}




#endif
