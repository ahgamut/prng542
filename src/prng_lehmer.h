#ifndef PRNG_LEHMER_H
#define PRNG_LEHMER_H
#include "prng.h"

class PRNGLehmer : public PRNG {
   protected:
    u64 k;

   public:
    PRNGLehmer(u64, u64, u64);
    ~PRNGLehmer() = default;
    void check();
    void update();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    std::string toString() const;
};

#endif /* PRNG_LEHMER_H */
