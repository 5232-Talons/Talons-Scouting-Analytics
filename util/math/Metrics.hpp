#ifndef Metrics_hpp
#define Metrics_hpp


enum class MetricType {
    AVERAGE_SCORE,
    AVERAGE_NOTE_SCORE,
    NOTE_PER_MATCH,
    STD_DEV,
    DRIVER_SCORE,
    CLIMB_SCORE,
    HUMAN_SCORE,
    MATCH_COUNT, 
    NONE
};

/*
Container for storing TSA Metrics. 
For best results use with double or floats. 
*/
template <class T>
struct Metrics{
    private:

    protected:
        T avg_scr      = 0.0;
        T avg_note_scr = 0.0;
        T note_p_match = 0.0;
        T std_dev      = 0.0;
        T driver_scr   = 0.0;
        T climbing_scr = 0.0;
        T human_scr    = 0.0;
        T match_cnt    = 0.0;

    public:
        Metrics();
        Metrics(const T&, const T&, const T&, const T&, const T&, const T&, const T&, const T&);

        void SetAvgScore(const T&);
        void SetAvgNoteScore(const T&);
        void SetAvgNotePerMatch(const T&);
        void SetStdDev(const T&);
        void SetDriverScore(const T&);
        void SetHumanPlayerScore(const T&);
        void SetAvgClimbScore(const T&);
        void SetMatchCount(const T&);

        T& GetAvgScore();
        T& GetAvgNoteScore();
        T& GetAvgNotePerMatch();
        T& GetStdDev();
        T& GetDriverScore();
        T& GetHumanPlayerScore();
        T& GetAvgClimbScore();
        T& GetMatchCount();

        ~Metrics(){};
};

#include "Metrics.cpp"
#endif
