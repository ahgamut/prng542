#ifndef PRNG_BLUM2SHUB_H
#define PRNG_BLUM2SHUB_H
#include "prng.h"

class PRNGBlum2Shub : public PRNG {
   protected:
    u64 p, q;

   public:
    PRNGBlum2Shub(u64, u64, u64);
    ~PRNGBlum2Shub() = default;
    void check();
    void update();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    std::string toString() const;
};

#endif /* PRNG_BLUM2SHUB_H */
