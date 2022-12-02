#ifndef PRNG_H
#define PRNG_H
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>

/* now include Rcpp.h */
#include <Rcpp.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

class PRNG {
   protected:
    u64 seed, state, limit;

   public:
    PRNG();
    ~PRNG() = default;
    
    /* other methods */
    void check();
    double get_value();
    Rcpp::NumericVector unif(u32);
    Rcpp::IntegerVector draw(u32);
    virtual std::string toString() const = 0;
    virtual void update() = 0;
};

#endif /* PRNG_H */
