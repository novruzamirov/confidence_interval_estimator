//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Novruz Amirov
//---Student Number: 150200903
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

StatisticalDistribution *choose_function(int choice)
{
    if (choice == 0)
    {
        NormalDistribution *normal = new NormalDistribution();
        return normal;
    }
    else if (choice == 1)
    {
        UniformDistribution *uniform = new UniformDistribution();
        return uniform;
    }
    else if (choice == 2)
    {
        ExponentialDistribution *exponential = new ExponentialDistribution();
        return exponential;
    }
    else
    {
        throw "Unidentified distribution function!";
    }
}

double many_trials(StatisticalDistribution *dist, std::vector<double> random_sample, double t_value, int trials, int sample_size, int seed_value)
{
    double precision = 0.0;
    double successes = 0.0;

    for (int i = 0; i < trials; i++)
    {

        std::vector<double> rand_sample = dist->sample(sample_size, seed_value);
        std::vector<double> interval = dist->calculate_confidence_interval(rand_sample, sample_size, t_value);

        if (dist->getter() > interval[0] && dist->getter() < interval[2])
        {
            successes += 1.0;
        }

        seed_value++;
    }

    precision = successes / trials;

    return precision;
}