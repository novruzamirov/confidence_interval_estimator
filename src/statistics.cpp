//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Novruz Amirov
//---Student Number: 150200903
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

double StatisticalDistribution::getter() const
{
    return mean;
}

std::vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> random_sample, int sample_size, double t_value)
{
    double sum = 0.0;
    double sample_mean = 0.0;
    double variance = 0.0;
    for (int i = 0; i < sample_size; i++)
    {
        sum += random_sample[i];
    }
    sample_mean = sum / sample_size;
    double standart_deviation;
    for (int i = 0; i < sample_size; i++)
    {
        variance += std::pow(random_sample[i] - sample_mean, 2);
    }
    variance = variance / sample_size;
    standart_deviation = std::sqrt(variance);
    double lower_bound, upper_bound;
    lower_bound = sample_mean - (t_value * (standart_deviation) / std::sqrt(sample_size));
    upper_bound = sample_mean + (t_value * (standart_deviation) / std::sqrt(sample_size));
    std::vector<double> result = {lower_bound, sample_mean, upper_bound};

    return result;
}

NormalDistribution::NormalDistribution()
{
    mean = 0.0;
    stddev = 1.0;
}

std::vector<double> NormalDistribution::sample(int sample_size, int seed_value)
{
    std::vector<double> normal_sample;
    std::default_random_engine generator;
    generator.seed(seed_value);
    std::normal_distribution<double> distribution(mean, stddev);

    for (int i = 0; i < sample_size; i++)
    {
        double number = distribution(generator);
        normal_sample.push_back(number);
    }

    return normal_sample;
}

UniformDistribution::UniformDistribution()
{
    mean = 0.0;
    a = -1.0;
    b = 1.0;
}

std::vector<double> UniformDistribution::sample(int sample_size, int seed_value)
{
    std::vector<double> uniform_sample;

    std::default_random_engine generator;
    generator.seed(seed_value);
    std::uniform_real_distribution<double> distribution(a, b);

    for (int i = 0; i < sample_size; i++)
    {
        double number = distribution(generator);
        uniform_sample.push_back(number);
    }

    return uniform_sample; // same with normal_sample??
}

ExponentialDistribution::ExponentialDistribution()
{
    mean = 1.0;
    lambda = 1.0;
}

std::vector<double> ExponentialDistribution::sample(int sample_size, int seed_value)
{
    std::vector<double> exponential_sample;

    std::default_random_engine generator;
    generator.seed(seed_value);
    std::exponential_distribution<double> distribution(lambda);

    for (int i = 0; i < sample_size; i++)
    {
        double number = distribution(generator);
        exponential_sample.push_back(number);
    }

    return exponential_sample;
}