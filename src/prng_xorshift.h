#ifndef PRNG_XORSHIFT_H
#define PRNG_XORSHIFT_H
#include "prng.h"

typedef struct _XorshiftABC {
    u8 a, b, c;
} XorshiftABC;
typedef u32 (*XorshiftUpdater)(u32, u32, u32, u32);

class PRNGXorshift : public PRNG {
   protected:
    XorshiftABC abc;
    XorshiftUpdater upfunc;

   public:
    PRNGXorshift(u64, u64, u64);
    ~PRNGXorshift() = default;
    void check();
    void update();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    std::string toString() const;
};

#endif /* PRNG_XORSHIFT_H */
