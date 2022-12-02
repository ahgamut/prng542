#ifndef PRNG_LCG_H
#define PRNG_LCG_H
#include "prng.h"

class PRNGLCG: public PRNG
{
protected:
    u64 a, c;

public:
    PRNGLCG(u64, u64, u64, u64);
    ~PRNGLCG() = default;
    void check();
    void update();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    std::string toString() const;
};

#endif /* PRNG_LCG_H */
