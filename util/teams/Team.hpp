#ifndef team_hpp
#define team_hpp

#include "../math/Metrics.hpp"
#include <vector>


template <class T>
struct Team {
    private:
        

    protected:
        std::string m_team_name; 
        const Metrics<T>* team_metric = new Metrics<T>();
        std::vector<std::vector<T>> scouted_data{};
        std::vector<std::vector<T>> scoutless_data{}; 
        
        

    public:
        Team();
        void AddScoutedData(const std::vector<T>&);
        void AddScoutlessData(const std::vector<T>&);
        void UpdateMetric(MetricType&&, const T&);

        T& GetMetricValue(const MetricType&&) const;

        ~Team(){};
};





#include "Team.cpp"
#endif