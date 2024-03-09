#include "Metrics.hpp"

/*
Metrics takes the following in order:
Average Score
Average Note Score
Average Note Per Match
Standard Deviation
Average Driver Score
Average Human Play Score
Average Climb Score
Match Count
*/
template <class T>
Metrics<T>::Metrics(const T& aScr_, const T& aNtScr_, const T& nPM_, const T& stDv_, const T&dScr_, const T&hScr_, const T&cScr_, const T&mCnt_){
    this->avg_scr = aScr_;
    this->avg_note_scr = aNtScr_;
    this->note_p_match = nPM_;
    this->std_dev = stDv_;
    this->driver_scr = dScr_;
    this->climbing_scr = cScr_;
    this->human_scr = hScr_;
    this->match_cnt = mCnt_;
};

template <class T>
Metrics<T>::Metrics(){

};

#pragma region Sets
template <class T>
void Metrics<T>::SetAvgScore(const T& avg_score){
    this->avg_scr = avg_score;
    return *this;
}

template <class T>
void Metrics<T>::SetAvgNotePerMatch(const T& npm){
    this->note_p_match = npm;
    return *this;
}

template <class T>
void Metrics<T>::SetStdDev(const T& std_dev){
    this->std_dev = std_dev;
    return *this;
}

template <class T>
void Metrics<T>::SetDriverScore(const T& driver_score){
    this->driver_scr = driver_score;
    return *this;
}

template <class T>
void Metrics<T>::SetHumanPlayerScore(const T& human_score){
    this->human_scr = human_score;
    return *this;
}

template <class T>
void Metrics<T>::SetAvgClimbScore(const T& climb_score){
    this->climbing_scr = climb_score;
}

template <class T>
void Metrics<T>::SetMatchCount(const T& match_count){
    this->match_cnt = match_count;
    return *this;
}
#pragma endregion

#pragma region Gets
template <class T>
T& Metrics<T>::GetAvgScore() const{
    return this->avg_scrore;
}

template <class T>
T& Metrics<T>::GetAvgNoteScore() const {
    return this->avg_note_scr;
}

template <class T>
T& Metrics<T>::GetAvgNotePerMatch() const {
    return this->std_dev;
}

template <class T>
T& Metrics<T>::GetDriverScore() const {
    return this->driver_scr;
}

template <class T>
T& Metrics<T>::GetHumanPlayerScore() const {
    return this->human_scr;
}

template <class T>
T& Metrics<T>::GetAvgClimbScore() const {
    return this->climbing_scr;
}

template <class T>
T& Metrics<T>::GetMatchCount() const {
    return this->match_cnt;
}
#pragma endregion