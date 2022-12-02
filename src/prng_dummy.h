#ifndef PRNG_DUMMY_H
#define PRNG_DUMMY_H
#include "prng.h"

class PRNGDummy : public PRNG
{
public:
    PRNGDummy(u64, u64);
    ~PRNGDummy() = default;
    void update();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    std::string toString() const;
};

#endif /* PRNG_DUMMY_H */   
