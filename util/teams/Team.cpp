#include "Team.hpp"

template <class T>
Team<T>::Team() : m_team_name{"0"} {};

template <class T>
void Team<T>::UpdateMetric(MetricType &&metric_type, const T& value)
{
    switch (metric_type)
    {
    case MetricType::AVERAGE_SCORE:
        this->team_metric->SetAvgScore(value); break;
    case MetricType::AVERAGE_NOTE_SCORE:
        this->team_metric->SetAvgNoteScore(value); break;
    case MetricType::NOTE_PER_MATCH:
        this->team_metric->SetAvgNotePerMatch(value); break;
    case MetricType::STD_DEV:
        this->team_metric->SetStdDev(value); break;
    case MetricType::DRIVER_SCORE:
        this->team_metric->SetDriverScore(value); break;
    case MetricType::CLIMB_SCORE:
        this->team_metric->SetAvgClimbScore(value); break;
    case MetricType::HUMAN_SCORE:
        this->team_metric->SetHumanPlayerScore(value); break;
    case MetricType::MATCH_COUNT:
        this->team_metric->SetMatchCount(value); break;
    case MetricType::NONE:
    default:
        std::cerr << "Invalid Metric Type was passed to Update Metric" << std::endl;
        break;
    }
}

template <class T>
T& Team<T>::GetMetricValue(const MetricType&& metric_type) const {
    switch (metric_type)
    {
    case MetricType::AVERAGE_SCORE:
        return this->team_metric->GetAvgScore(); break;
    case MetricType::AVERAGE_NOTE_SCORE:
        return this->team_metric->GetAvgNoteScore(); break;
    case MetricType::NOTE_PER_MATCH:
        return this->team_metric->GetAvgNotePerMatch(); break;
    case MetricType::STD_DEV:
        return this->team_metric->GetStdDev(); break;
    case MetricType::DRIVER_SCORE:
        return this->team_metric->GetDriverScore(); break;
    case MetricType::CLIMB_SCORE:
        return this->team_metric->GetAvgClimbScore(); break;
    case MetricType::HUMAN_SCORE:
        return this->team_metric->GetHumanPlayerScore(); break;
    case MetricType::MATCH_COUNT:
         return this->team_metric->GetMatchCount(); break;
    case MetricType::NONE:
    default:
        std::cerr << "Invalid Metric Type was passed to Get Metric, got NONE, expected other" << std::endl;
        throw;
        break;
    }
}