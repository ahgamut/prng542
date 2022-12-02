#ifndef PRNG_MIDSQ_H
#define PRNG_MIDSQ_H
#include "prng.h"

class PRNGMidsq : public PRNG {
   public:
    PRNGMidsq(u64, u64);
    ~PRNGMidsq() = default;
    void check();
    void update();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    std::string toString() const;
};

#endif /* PRNG_MIDSQ_H */
