//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Novruz Amirov
//---Student Number: 150200903
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>

class StatisticalDistribution // abstract base class.
{
protected:
    double mean;

public:
    double getter() const;                                                               // to get the mean value.
    virtual std::vector<double> sample(int, int) = 0;                                    // pure virtual function with parameters sample_size and seed_value.
    std::vector<double> calculate_confidence_interval(std::vector<double>, int, double); // method with parameter random_sample, sample_size, and t_value.
};

class NormalDistribution : public StatisticalDistribution
{
private:
    double stddev; // standart deviation value.
public:
    NormalDistribution(); // constructor to initialize "mean" as 0.0 and "stddev" as 1.0.
    std::vector<double> sample(int, int);
};

class UniformDistribution : public StatisticalDistribution
{
private:
    double a; // beginning value of range.
    double b; // ending value of range.
public:
    UniformDistribution(); // constructor to initialize "mean" as 0.0, "a" as -1.0, and "b" as 1.0.
    std::vector<double> sample(int, int);
};

class ExponentialDistribution : public StatisticalDistribution
{
private:
    double lambda; // average rate of occurence.

public:
    ExponentialDistribution(); // constructor to initalize "mean" as 0.0 and "lambda" as 1.0.
    std::vector<double> sample(int, int);
};

#endif