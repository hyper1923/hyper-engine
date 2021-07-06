#pragma once



class Stats{
public:
    static Stats& getInstance(){static Stats stats ;return stats;}
    unsigned int m_RenderCalls;
    unsigned int m_frameCount;
    unsigned int currentObjectsinScene;
};