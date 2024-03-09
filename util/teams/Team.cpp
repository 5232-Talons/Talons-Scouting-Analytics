#include "Team.hpp"

template <class T>
Team<T>::Team() : m_team_name{"0"}{};

template <class T>
void Team<T>::UpdateMetric(){
    this->team_metric->SetAvgClimbScore(0);
}