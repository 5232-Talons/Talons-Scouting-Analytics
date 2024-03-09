#ifndef team_hpp
#define team_hpp

#include "../math/Metrics.hpp"


template <class T>
struct Team {
    private:
        

    protected:
        std::string m_team_name; 
        Metrics<T>* team_metric = new Metrics<T>();

        
        

    public:
        Team();

        void UpdateMetric(MetricType&&, const T&);

        T& GetMetricValue(const MetricType&&) const;

        ~Team(){};
};





#include "Team.cpp"
#endif